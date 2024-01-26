# 搭建环境<a name="ZH-CN_TOPIC_0000001054781998"></a>

## 环境要求<a name="section466851916410"></a>

## 硬件要求<a name="section07318322310"></a>

-   Linux服务器
-   Windows工作台（主机电脑）
-   BearPi-HM_Nano开发板
-   USB Type-C线（Windows工作台通过USB与BearPi-HM_Nano开发板组连接）

各硬件连接关系如下图所示。

**图 1**  硬件连线图<a name="fig1651211924914"></a>  
![](/applications/BearPi/BearPi-HM_Nano/docs/quick-start/figures/硬件连线图.png "硬件连线图")

## 软件系统要求<a name="section182305581332"></a>

**表 1**  BearPi-HM_Nano开发板开发平台要求

<a name="tc50585b2b3fe43f7835154789b0e25af"></a>
<table><thead align="left"><tr id="ra9df6acc53154b819d5f86d885d994de"><th class="cellrowborder" valign="top" width="12.41%" id="mcps1.2.5.1.1"><p id="a999bb40532eb4f74a7383e1e776bb94a"><a name="a999bb40532eb4f74a7383e1e776bb94a"></a><a name="a999bb40532eb4f74a7383e1e776bb94a"></a>硬件</p>
</th>
<th class="cellrowborder" valign="top" width="12.389999999999999%" id="mcps1.2.5.1.2"><p id="ae63cf791fbe348d3b907d20fc4927df8"><a name="ae63cf791fbe348d3b907d20fc4927df8"></a><a name="ae63cf791fbe348d3b907d20fc4927df8"></a>软件</p>
</th>
<th class="cellrowborder" valign="top" width="46.21%" id="mcps1.2.5.1.3"><p id="a54c4c80c43c84cb187342865a1d2b51e"><a name="a54c4c80c43c84cb187342865a1d2b51e"></a><a name="a54c4c80c43c84cb187342865a1d2b51e"></a>描述</p>
</th>
<th class="cellrowborder" valign="top" width="28.99%" id="mcps1.2.5.1.4"><p id="a11e8d096fb204378a63d8805cd6d1f88"><a name="a11e8d096fb204378a63d8805cd6d1f88"></a><a name="a11e8d096fb204378a63d8805cd6d1f88"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row117591159175819"><td class="cellrowborder" valign="top" width="12.41%" headers="mcps1.2.5.1.1 "><p id="a0c1290183f2548898dbfc516a4db2c4b"><a name="a0c1290183f2548898dbfc516a4db2c4b"></a><a name="a0c1290183f2548898dbfc516a4db2c4b"></a>Linux编译服务器</p>
</td>
<td class="cellrowborder" valign="top" width="12.389999999999999%" headers="mcps1.2.5.1.2 "><p id="a687efa8001f140488dc1da9a2ee8f6d1"><a name="a687efa8001f140488dc1da9a2ee8f6d1"></a><a name="a687efa8001f140488dc1da9a2ee8f6d1"></a>操作系统</p>
</td>
<td class="cellrowborder" valign="top" width="46.21%" headers="mcps1.2.5.1.3 "><p id="ace724e00c9094eccb8c600d6ad426ed8"><a name="ace724e00c9094eccb8c600d6ad426ed8"></a><a name="ace724e00c9094eccb8c600d6ad426ed8"></a>Ubuntu16.04及以上64位系统版本，Shell使用bash</p>
</td>
<td class="cellrowborder" rowspan="2" valign="top" width="28.99%" headers="mcps1.2.5.1.4 "><p id="a4d0e2c8444484554ab58949ce322be32"><a name="a4d0e2c8444484554ab58949ce322be32"></a><a name="a4d0e2c8444484554ab58949ce322be32"></a>开发人员可以在Windows工作台中进行程序开发，或者远程登录到Linux服务器进行程序开发。</p>
</td>
</tr>
<tr id="r85c4bf56ff3244e48db9d2f5b622b340"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="a8e99fd0262cb4489b70cf86c2144c294"><a name="a8e99fd0262cb4489b70cf86c2144c294"></a><a name="a8e99fd0262cb4489b70cf86c2144c294"></a>Windows工作台</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="a44d6164ce2e9421f9ade362f600c2815"><a name="a44d6164ce2e9421f9ade362f600c2815"></a><a name="a44d6164ce2e9421f9ade362f600c2815"></a>操作系统</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="a1c17349e334a44ada5c5f150457fe17d"><a name="a1c17349e334a44ada5c5f150457fe17d"></a><a name="a1c17349e334a44ada5c5f150457fe17d"></a>Windows XP/Windows7/Windows10</p>
</td>
</tr>
</tbody>
</table>

## Linux构建工具要求<a name="section20374218687"></a>

Linux服务器通用环境配置需要的工具及其获取途径如下表所示。

**表 2**  Linux服务器开发工具及获取途径

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="25.562556255625562%" id="mcps1.2.4.1.1"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>开发工具</p>
</th>
<th class="cellrowborder" valign="top" width="20.7020702070207%" id="mcps1.2.4.1.2"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>用途</p>
</th>
<th class="cellrowborder" valign="top" width="53.73537353735374%" id="mcps1.2.4.1.3"><p id="p12997271757"><a name="p12997271757"></a><a name="p12997271757"></a>获取途径</p>
</th>
</tr>
</thead>
<tbody><tr id="row1829915274517"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p1629902717511"><a name="p1629902717511"></a><a name="p1629902717511"></a>交叉编译器gcc_riscv32</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1219863434519"><a name="p1219863434519"></a><a name="p1219863434519"></a>交叉编译工具</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p165031126103215"><a name="p165031126103215"></a><a name="p165031126103215"></a><a href="https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234" target="_blank" rel="noopener noreferrer">https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234 </a>提取码：1234 </p>
</td>
</tr>
<tr id="row430016273514"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p330015271158"><a name="p330015271158"></a><a name="p330015271158"></a>Python3.7+</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p43003270510"><a name="p43003270510"></a><a name="p43003270510"></a>编译构建工具</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p18254155164617"><a name="p18254155164617"></a><a name="p18254155164617"></a><a href="https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz" target="_blank" rel="noopener noreferrer">https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz</a></p>
</td>
</tr>
<tr id="row1397335913612"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p097355911620"><a name="p097355911620"></a><a name="p097355911620"></a>SCons3.0.4+</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1973195917619"><a name="p1973195917619"></a><a name="p1973195917619"></a>编译构建工具</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p1722663441514"><a name="p1722663441514"></a><a name="p1722663441514"></a>通过互联网获取</p>
</td>
</tr>
<tr id="row42668197206"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p426711912014"><a name="p426711912014"></a><a name="p426711912014"></a>bash</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p14267131962014"><a name="p14267131962014"></a><a name="p14267131962014"></a>命令处理器</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p14267101962014"><a name="p14267101962014"></a><a name="p14267101962014"></a>通过互联网获取</p>
</td>
</tr>
<tr id="row1463517494402"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p258814561424"><a name="p258814561424"></a><a name="p258814561424"></a>build-essential</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1749611716181"><a name="p1749611716181"></a><a name="p1749611716181"></a>编译依赖的基础软件包</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p8635174916403"><a name="p8635174916403"></a><a name="p8635174916403"></a>通过互联网获取</p>
</td>
</tr>
<tr id="row1711946154018"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p15588165684216"><a name="p15588165684216"></a><a name="p15588165684216"></a>gn</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p4588135634213"><a name="p4588135634213"></a><a name="p4588135634213"></a>产生ninja编译脚本</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p10572194318318"><a name="p10572194318318"></a><a name="p10572194318318"></a><a href="https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234" target="_blank" rel="noopener noreferrer">https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234 </a>提取码：1234</p>
</td>
</tr>
<tr id="row16990164213404"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p1858825613428"><a name="p1858825613428"></a><a name="p1858825613428"></a>ninja</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p15844174611816"><a name="p15844174611816"></a><a name="p15844174611816"></a>执行ninja编译脚本</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p377581023312"><a name="p377581023312"></a><a name="p377581023312"></a><a href="https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234" target="_blank" rel="noopener noreferrer">https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234 </a>提取码：1234</p>
</td>
</tr>
</tbody>
</table>

## Windows开发工具要求<a name="section11161833102716"></a>

**表 3**  Windows工作台开发工具及获取途径

<a name="table1313323311274"></a>
<table><thead align="left"><tr id="row3133133312711"><th class="cellrowborder" valign="top" width="16.371637163716375%" id="mcps1.2.4.1.1"><p id="p16132203372716"><a name="p16132203372716"></a><a name="p16132203372716"></a>开发工具</p>
</th>
<th class="cellrowborder" valign="top" width="50.29502950295029%" id="mcps1.2.4.1.2"><p id="p1413219339278"><a name="p1413219339278"></a><a name="p1413219339278"></a>用途</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p17133183312711"><a name="p17133183312711"></a><a name="p17133183312711"></a>获取途径</p>
</th>
</tr>
</thead>
<tbody><tr id="row138432533451"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="p163612016916"><a name="p163612016916"></a><a name="p163612016916"></a>Visual Studio Code</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="p1563690791"><a name="p1563690791"></a><a name="p1563690791"></a>代码编辑工具。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p146361701097"><a name="p146361701097"></a><a name="p146361701097"></a><a href="https://code.visualstudio.com/" target="_blank" rel="noopener noreferrer">https://code.visualstudio.com/</a></p>
</td>

</tr>
<tr id="row18342145821513"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="p123421958131517"><a name="p123421958131517"></a><a name="p123421958131517"></a>MobaXterm、PuTTY或其他超级终端（选其一）</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="p18342658131511"><a name="p18342658131511"></a><a name="p18342658131511"></a>远程连接Linux编译服务器，连接模组串口工具。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p17342125851518"><a name="p17342125851518"></a><a name="p17342125851518"></a>通过互联网获取（如：<a href="https://mobaxterm.mobatek.net/" target="_blank" rel="noopener noreferrer">https://mobaxterm.mobatek.net/</a>）</p>
</td>
</tr>
<tr id="row244884215147"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="p1044974291416"><a name="p1044974291416"></a><a name="p1044974291416"></a>CH341SER.EXE</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="p94491342131413"><a name="p94491342131413"></a><a name="p94491342131413"></a>USB转串口驱动。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p6449184214148"><a name="p6449184214148"></a><a name="p6449184214148"></a><a href="http://www.wch.cn/search?q=ch340g&amp;t=downloads" target="_blank" rel="noopener noreferrer">http://www.wch.cn/search?q=ch340g&amp;t=downloads</a></p>
</td>
</tr>
<tr id="row18342145821513"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="p123421958131517"><a name="p123421958131517"></a><a name="p123421958131517"></a>Hiburn烧录工具</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="p18342658131511"><a name="p18342658131511"></a><a name="p18342658131511"></a>代码烧录工具。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p6449184214148"><a name="p6449184214148"></a><a name="p6449184214148"></a><a href="https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234" target="_blank" rel="noopener noreferrer">https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234</a>密码：1234</p>
</td>
</tr>
</tbody>
</table>

## 安装编译基础环境<a name="section497484245614"></a>

## 连接Linux服务器<a name="section15541530155711"></a>

使用Windows远程登录Linux，以MobaXterm工具为例：

1.  打开[MobaXterm工具](https://mobaxterm.mobatek.net/)，    输入Linux服务器IP地址，后点击“OK”，打开连接。

    **图 2**  MobaXterm界面示例图<a name="f825e6d7569cc487db9b744e454c7157a"></a> 

    ![](/applications/BearPi/BearPi-HM_Nano/docs/quick-start/figures/MobaXterm登录服务器.png "MobaXterm登录服务器")

2.  弹框告警选择“是\(Y\)”。
3.  弹出界面中输入账号并按回车键，继续输入密码并回车键。

    **图 3**  登录界面图<a name="fe1428afffbdd45f9b4a39497691ff5ff"></a>  
    ![](/applications/BearPi/BearPi-HM_Nano/docs/quick-start/figures/Linux服务器登录.png "Linux服务器登录")

4.  登录成功。

    **图 4**  登录成功界面<a name="f11bea69483e14bd39fef4a10b1ed1a3a"></a>  
    ![](/applications/BearPi/BearPi-HM_Nano/docs/quick-start/figures/Linux服务器登录成功.png "Linux服务器登录成功")


## 将Linux shell改为bash<a name="section182814544221"></a>

查看shell是否为bash，在终端运行如下命令

```
ls -l /bin/sh
```

如果为显示为/bin/sh -\> bash则为正常，否则请按以下方式修改：

**方法一**：在终端运行如下命令，然后选择 no。

```
sudo dpkg-reconfigure dash
```

**方法二**：先删除sh，再创建软链接。

```
rm -rf /bin/sh
sudo ln -s /bin/bash /bin/sh
```

## 安装Python环境<a name="section126831816258"></a>

1.  打开Linux编译服务器终端。
2.  输入命令“python3 --version”，查看Python版本号。需使用python3.7以上版本，否则请按以下步骤执行，以python3.8为例：
    -   如果Ubuntu 版本为18，运行"sudo apt-get install python3.8"
    -   如果Ubuntu 版本为16，请以下载包的方式安装python:

        1. python安装环境依赖\(gcc, g++, make, zlib, libffi\)请运行：

        "sudo apt-get install gcc && sudo apt-get install g++ && sudo apt-get install make && sudo apt-get install zlib\* && sudo apt-get install libffi-dev "

        2. 获取[python3.8.5安装包](https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz)，将其放至linux服务器中，运行 ：

        "tar -xvzf Python-3.8.5.tgz && cd Python-3.8.5 && sudo ./configure && make && sudo make install"

3. 确定Python-3.8.5安装好后，运行"which python3.8"，将回显路径链接到"/usr/bin/python"，示例：

        "cd /usr/bin && sudo rm python && sudo ln -s /usr/bin/python3.8 python && python --version"

        若系统存在python3，通过"python3 --version"指令查询版本，若不是3.7以上版本，则还需要执行下面指令

        "cd /usr/bin && sudo rm python3 && sudo ln -s /usr/bin/python3.8 python3 && python3 --version"


4. 安装Python包管理工具，运行“sudo apt-get install python3-setuptools python3-pip -y”命令。（需root/sudo权限安装），升级pip3运行"sudo pip3 install --upgrade pip"。

        或按官网方式安装Python包管理工具：下载"curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py"后，再执行"python get-pip.py"


5.  安装python模块setuptools，运行"pip3 install setuptools"
6.  运行“sudo pip3 install kconfiglib”命令，安装GUI menuconfig工具，建议安装Kconfiglib 13.2.0+版本。（需root/sudo权限安装）。

    或者按以下方法安装Kconfiglib 13.2.0+。

    1.  下载.whl文件（例如：kconfiglib-13.2.0-py2.py3-none-any.whl）。

        下载路径：“[https://pypi.org/project/kconfiglib\#files](https://pypi.org/project/kconfiglib#files)”


    1.  运行“sudo pip3 install kconfiglib-xxx.whl”命令（例如：sudo pip3 install kconfiglib-13.2.0-py2.py3-none-any.whl），安装.whl文件（需root/sudo权限安装）。
    2.  可能会遇到错误："subprocess.CalledProcessError: Command '\('lsb\_release', '-a'\)' returned non-zero exit status 1."，解决方法："find / -name lsb\_release"，找到lsb\_release位置并删除，如："rm -rf /usr/bin/lsb\_release"

7.  安装pycryptodome。运行“sudo pip3 install pycryptodome”命令，或者按照以下方式安装：

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >-   安装升级文件签名依赖的Python组件包，包括：pycryptodome、six、ecdsa。
    >-   安装ecdsa依赖six，请按文档要求，先安装six，再安装ecdsa。

    1.  下载.whl文件（例如：pycryptodome-3.7.3-cp37-cp37m-manylinux1\_x86\_64.whl）。

        下载路径：“[https://pypi.org/project/pycryptodome/\#files](https://pypi.org/project/pycryptodome/#files)”。


    1.  运行“sudo pip3 install pycryptodome-xxx.whl”命令（例如：sudo pip3 install pycryptodome-3.7.3-cp37-cp37m-manylinux1\_x86\_64.whl），安装.whl文件（需root/sudo权限安装）。

    安装完成后界面会提示“Successfully installed pycryptodome-3.7.3”。

8.  安装six。运行"sudo pip3 install six --upgrade --ignore-installed six"或者按照以下方式安装：

    1.  下载.whl文件（例如：six-1.12.0-py2.py3-none-any.whl）。

        下载路径：“[https://pypi.org/project/six/\#files](https://pypi.org/project/six/#files)”


    1.  运行“sudo pip3 install six-xxx.whl”命令（例如：sudo pip3 install six-1.12.0-py2.py3-none-any.whl），安装.whl文件（需root/sudo权限安装）。

    安装完成后界面会提示“Successfully installed six-1.12.0”。

9.  安装ecdsa。运行"sudo pip3 install ecdsa"或者按照以下方式安装：

    1.  下载.whl文件（例如：ecdsa-0.14.1-py2.py3-none-any.whl）。

        下载路径：“[https://pypi.org/project/ecdsa/\#files](https://pypi.org/project/ecdsa/#files)”


    1.  运行“sudo pip3 install ecdsa-xxx.whl”命令（例如：sudo pip3 install ecdsa-0.14.1-py2.py3-none-any.whl），安装.whl文件（需root/sudo权限安装）。

    安装完成后界面会提示“Successfully installed ecdsa-0.14.1”。


## 安装Scons<a name="section2462246562"></a>

1.  打开Linux编译服务器终端。
2.  安装SCons安装包（需root/sudo权限安装）。

    运行命令：“sudo apt-get install scons -y”。如果软件源中无法找到安装包，请按以下步骤处理：

    1.  下载源码包（下载路径：“  [https://scons.org/pages/download.html](https://scons.org/pages/download.html)  ”，推荐SCons版本是3.0.4+）。
    2.  解压源码包到任意目录。
    3.  安装源码包：进入解压目录，运行命令“sudo python3 setup.py install”（需root/sudo权限安装），等待安装完毕。

3.  输入命令“scons -v”，查看是否安装成功。如果安装成功，查询结果下图所示。

    **图 5**  SCons安装成功界面<a name="fig235815252492"></a>  
    ![](/applications/BearPi/BearPi-HM_Nano/docs/quick-start/figures/SCons安装成功界面.png "SCons安装成功界面")


## 安装编译工具环境<a name="section7227629152013"></a>

>![](public_sys-resources/icon-notice.gif) **须知：** 
>-   如果后续通过“HPM组件方式”或“HPM包管理器命令行工具方式”获取源码，不需要安装gn、ninja、gcc\_riscv32编译工具。
>-   （推荐）如果后续通过“镜像站点方式”或“代码仓库方式”获取源码，需要安装gn、ninja、gcc\_riscv32编译工具。
>    安装gn、ninja、gcc\_riscv32编译工具时，请确保编译工具的环境变量路径唯一。

## 安装gn<a name="section2024354014506"></a>

1.  打开Linux编译服务器终端。
2.  下载gn工具：https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234 提取码：1234
3.  解压gn安装包至\~/gn路径下："tar -xvf gn.1523.tar -C \~/"。
4.  设置环境变量："vim \~/.bashrc", 新增："export PATH=\~/gn:$PATH"。
5.  生效环境变量："source \~/.bashrc"。

## 安装ninja<a name="section182441140185010"></a>

1.  打开Linux编译服务器终端
2.  下载ninja工具：https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234 提取码：1234
3.  解压ninja安装包至\~/ninja路径下："tar -xvf ninja.1.9.0.tar -C \~/"。
4.  设置环境变量："vim \~/.bashrc", 新增："export PATH=\~/ninja:$PATH"。
5.  生效环境变量："source \~/.bashrc"。

## 安装gcc\_riscv32（WLAN模组类编译工具链）<a name="section2014123416523"></a>

>![](public_sys-resources/icon-notice.gif) **须知：** 
>Hi3861平台仅支持使用libgcc运行时库的静态链接，**不建议开发者使用libgcc运行时库的动态链接，会导致商业分发时被GPL V3污染。**

1.  打开Linux编译服务器终端。
2.  下载gcc\_riscv32工具：https://pan.baidu.com/s/1vSpPWvIhL8wCVGnEOjXS7g?pwd=1234 提取码：1234
3.  解压gcc\_riscv32安装包至/opt/gcc\_riscv32路径下："tar -xvf gcc\_riscv32-linux-7.3.0.tar.gz -C \~/"。
4.  设置环境变量："vim \~/.bashrc"，新增："export PATH=\~/gcc\_riscv32/bin:$PATH"。
5.  生效环境变量："source \~/.bashrc"。
6.  Shell命令行中输入“riscv32-unknown-elf-gcc -v”，如果能正确显示编译器版本号，表明编译器安装成功。

