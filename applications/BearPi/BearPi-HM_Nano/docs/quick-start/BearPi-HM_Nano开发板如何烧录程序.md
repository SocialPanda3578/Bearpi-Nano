# BearPi-HM_Nano开发板如何烧录程序<a name="ZH-CN_TOPIC_0000001053302600"></a>
1. 在Windows打开Hiburn工具，并点击`Refresh`，在`COM`中选择`第八-4`看到的COM号
- Hiburn工具下载地址（百度云）：https://pan.baidu.com/s/1i6P_LuUzclS6hlQ3XHOobQ&amp;t=downloads 提取码：1234


    ![](figures/HiBurn主界面.png)

    然后点击`Setting`，并选择 `Com settings`，

2. 在Com settings中设置`Baud`为：`921600`，点击确定    

    ![](figures/HiBurn_Comsettings.png)

3. 点击 Hiburn工具中的`Select file`按钮，在弹出的文件框中，选择`七-2` 中对应的路径，并选中：`Hi3861_wifiiot_app_allinone.bin` 文件。

    ![](figures/HiBurn_打开文件.png)

4. 点击`Auto burn`复选框，然后点击`Connect`

    ![](figures/HiBurn准备下载.png)

    此时`Connect`按钮变成`Disconnect`，等待下载

5. 复位开发板`RESET`按键，开始下载程序

    ![](figures/复位开发板.png)

    ![](figures/Hiburn_下载程序中.png)

    
6. 直到出现`Execution Successful`字样，程序下载完成。

7. 下载完后，点击`Disconnect`按钮，便于后面调测使用。

