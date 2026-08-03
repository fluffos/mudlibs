/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : login.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

/* 原本 config 開了 3 個外部連接埠 (PPL/WIZ/CLIENT 各一), 這個專案的慣例
 * 是每個 lib 只分配一個連接埠 -- 這裡讓 PPL_PORT 對應到 config.fluffos
 * 實際設定的那個連接埠 (見 AGENTS.md §15x), WIZ_PORT/CLIENT_PORT 保留原
 * 值即可 (反正沒有其他連接埠會用到它們, login_ob.lpc 的 switch(query_
 * ip_port()) 分支就直接不會走到，一般玩家連線一律走 PPL_LOGIN_D)。 */
#define PPL_PORT		40081
#define WIZ_PORT		5001
#define CLIENT_PORT		5002

#define MOTD			"/system/daemons/etc/logind_motd"
#define WAITING_ENTER_TIME	5

#define MAX_USERS		1000

#define DEFAULT_WINDOW_SIZE	([ "width":80, "height":24 ])

#define STARTROOM		"/wiz/wizhall/room_wizhall_1"
#define WIZROOM			"/wiz/wizhall/room_wizhall_7"
#define WELCOME_MSG		"/system/daemons/etc/logind_welcome_msg"

#define DATA			"/data/daemon/login.o"
#define LOG			"daemon/connect"

