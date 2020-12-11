/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup MultiMedia_MediaCommon
 * @{
 *
 * @brief Provides data types and media formats required for recording and playing audio and videos.
 *
 *
 * @since 1.0
 * @version 1.0
 */

/**
 * @file media_errors.h
 *
 * @brief Declares the <b>media_errors</b> class to define errors that may occur during media operations.
 *
 *
 * @since 1.0
 * @version 1.0
 */

#ifndef MEDIA_ERRORS_H
#define MEDIA_ERRORS_H

#include <cstdint>

namespace OHOS {
namespace Media {
constexpr int32_t MODULE_MEDIA = 1;
constexpr int32_t SUBSYS_MEDIA = 30;

using ErrCode = int32_t;
constexpr int32_t SUBSYSTEM_BIT_NUM = 21;
constexpr int32_t MODULE_BIT_NUM = 16;

/**
 * @brief Generates a start error code with a unique identifier based on specified subsystem and module bit numbers.
 *
 * @param subsystem Indicates the subsystem bit number.
 * @param module Indicates the module bit number.
 * @return
 * @since 1.0
 * @version 1.0
 */
constexpr ErrCode ErrCodeOffset(unsigned int subsystem, unsigned int module = 0)
{
    return (subsystem << SUBSYSTEM_BIT_NUM) | (module << MODULE_BIT_NUM);
}

constexpr int32_t BASE_MEDIA_ERR_OFFSET = ErrCodeOffset(SUBSYS_MEDIA, MODULE_MEDIA);

enum MediaErrorCode : int32_t {
    /** Invalid data size that has been read */
    ERR_INVALID_READ = -1,
    /** Success */
    SUCCESS = 0,
    /** Fail */
    ERROR = BASE_MEDIA_ERR_OFFSET,
    /** Status error */
    ERR_ILLEGAL_STATE = BASE_MEDIA_ERR_OFFSET + 1,
    /** Invalid parameter */
    ERR_INVALID_PARAM = BASE_MEDIA_ERR_OFFSET + 2,
    /** Early media preparation */
    ERR_EARLY_PREPARE = BASE_MEDIA_ERR_OFFSET + 3,
    /** No media source */
    ERR_SOURCE_NOT_SET = BASE_MEDIA_ERR_OFFSET + 4,
    /** Invalid operation */
    ERR_INVALID_OPERATION = BASE_MEDIA_ERR_OFFSET + 5,
    /** No idle channel */
    ERR_NOFREE_CHANNEL = BASE_MEDIA_ERR_OFFSET + 6,
    /** Buffer reading failed */
    ERR_READ_BUFFER = BASE_MEDIA_ERR_OFFSET + 7,
    /**  Device not started */
    ERR_NOT_STARTED = BASE_MEDIA_ERR_OFFSET + 8,
    /** Unknown error */
    ERR_UNKNOWN = BASE_MEDIA_ERR_OFFSET + 200,
};
}  // namespace Media
}  // namespace OHOS
#endif  // MEDIA_ERRORS_H
