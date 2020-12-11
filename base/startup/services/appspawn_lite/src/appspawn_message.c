/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "appspawn_message.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "log.h"
#include "ohos_errno.h"
#include "securec.h"

static const size_t MAX_BUNDLE_NAME_LEN = 127;
static const size_t MIN_BUNDLE_NAME_LEN = 7;
static const size_t MAX_IDENTITY_ID_LEN = 24;
static const size_t MIN_IDENTITY_ID_LEN = 1;

void FreeMessageSt(MessageSt* targetSt)
{
    if (targetSt != NULL) {
        if (targetSt->bundleName != NULL) {
            free(targetSt->bundleName);
            targetSt->bundleName = NULL;
        }

        if (targetSt->identityID != NULL) {
            free(targetSt->identityID);
            targetSt->identityID = NULL;
        }

        targetSt->uID = -1;
        targetSt->gID = -1;
    }
}

static int ReadStringItem(cJSON* strItem, char** buf, size_t maxLen, size_t minLen)
{
    if (strItem == NULL || !cJSON_IsString(strItem)) {
        return EC_INVALID;
    }

    char* strPtr = cJSON_GetStringValue(strItem);
    if (strPtr == NULL) {
        return EC_PROTOCOL;
    }

    size_t strLength = strlen(strPtr);
    if (strLength > maxLen || strLength < minLen) {
        return EC_PROTOCOL;
    }

    char* bufTmp = (char*)malloc(strLength + 1);
    if (bufTmp == NULL) {
        return EC_NOMEMORY;
    }

    if (strLength > 0 && memcpy_s(bufTmp, strLength, strPtr, strLength) != EOK) {
        free(bufTmp);
        bufTmp = NULL;
        return EC_FAILURE;
    }

    bufTmp[strLength] = '\0';
    *buf = bufTmp;
    return EC_SUCCESS;
}

static double ReadNumberItem(cJSON* strItem)
{
    if (strItem == NULL || !cJSON_IsNumber(strItem)) {
        return -1;
    }

    return cJSON_GetNumberValue(strItem);
}

int SplitMessage(const char* msg, unsigned int msgLen, MessageSt* msgSt)
{
    if (msg == NULL || msgLen == 0 || msgSt == NULL) {
        return EC_INVALID;
    }

    cJSON* rootJ = cJSON_ParseWithLength(msg, msgLen);
    if (rootJ == NULL) {
        return EC_PROTOCOL;
    }

    cJSON* bundleNameItem = cJSON_GetObjectItem(rootJ, "bundleName");
    int ret = ReadStringItem(bundleNameItem, &(msgSt->bundleName), MAX_BUNDLE_NAME_LEN, MIN_BUNDLE_NAME_LEN);
    if (ret != EC_SUCCESS) {
        cJSON_Delete(rootJ);
        return ret;
    }

    cJSON* identityIDItem = cJSON_GetObjectItem(rootJ, "identityID");
    ret = ReadStringItem(identityIDItem, &(msgSt->identityID), MAX_IDENTITY_ID_LEN, MIN_IDENTITY_ID_LEN);
    if (ret != EC_SUCCESS) {
        FreeMessageSt(msgSt);
        cJSON_Delete(rootJ);
        return ret;
    }

    cJSON* uIDItem = cJSON_GetObjectItem(rootJ, "uID");
    cJSON* gIDItem = cJSON_GetObjectItem(rootJ, "gID");
    msgSt->uID = (int)ReadNumberItem(uIDItem);
    msgSt->gID = (int)ReadNumberItem(gIDItem);
    cJSON_Delete(rootJ);

    if (msgSt->uID <= 0 || msgSt->gID <= 0 || msgSt->uID == INT_MAX || msgSt->gID == INT_MAX) {
        FreeMessageSt(msgSt);
        return EC_PROTOCOL;
    }
    return EC_SUCCESS;
}