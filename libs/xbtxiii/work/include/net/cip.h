/* file: cip.h
 */
#ifndef __NET__DNS_H
#include "net/dns.h"
#endif

#define RouterPort 9000
#define maxConnections 12
#define maxPacketSize 8192
#define debug(x)  if( find_object(CHANNEL_D) ) CHANNEL_D->do_channel(this_object(),"log",sprintf("%O",x))

class mudInfo {
	string chineseName;	// 中文名称
	string name;		// 名称
	string passwd;		// 登录密码，以第一次为默认
	string alias;		// 别名
	mapping dns;		// 域名
	mapping ip;		// IP 地址
	int commPort;		// 通讯断口
	int port;		// 主端口
	string admin;		// 负责人的 email 地址，必须是 id@host 格式的
	string web;		// 网页地址
	string language;	// 使用的语言
	string mudlib;
	int version;		// 版本
	string description;
	int status;		// 通讯状态: 0 拒绝连线，1 开放连线，2 连线中, -1 断线.
/*	class services;		// 开通功能
	class others;
*/
}

class commInfo {
	string name;		// 名称
	string localTime;	// 当地时间, YYYYMMDDHHMM
	mapping IPechoTime;	// 各IP连接速度, 单位：ms
	int users;		// 线上玩家数量
}


/*int updateMudInfo(class);
int addMudInfo(class);
int removeMudInfo(string);

int bandMudInfo(string);
int updateCommInfo(class);

class queryMudInfo(string);
class queryCommInfo(string);

*/
void setupRouter();
void listenRouter(int);
void routerCallBack(int);
void lostConnection(int);
void routerDataRec(int,string);
void shutdownRouter();
