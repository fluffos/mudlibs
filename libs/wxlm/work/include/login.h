// login.h
// Originally from ES2
// Modified for XKX

#ifndef __LOGIN__
#define __LOGIN__

// 登录超时时间
#define LOGIN_TIMEOUT		240

// 欢迎信息
#define WELCOME			"/adm/etc/welcome"
// 新玩家信息
#define NEW_PLAYER_INFO		"/adm/etc/new_player"
// 未注册玩家欢迎信息
#define UNREG_MOTD		"/adm/etc/unreg_motd"
// 玩家欢迎信息
#define MOTD			"/adm/etc/motd"
#define MOVIE		   "/adm/etc/movie"

#define GAOSHOU			"/data/gaoshou"
#define RICHMAN			"/data/richman"

#define WIZLIST			"/adm/etc/wizlist"

// 注册房间
#define REGISTER_ROOM	   "/d/register/entry"
// 出生房间
// #define BORN_ROOM	       "/d/register/yanluodian"
// 默认起始房间
#define START_ROOM	      "/d/city/kedian"
// 死亡房间
#define DEATH_ROOM	      "/d/death/gate"
// 复活房间
#define REVIVE_ROOM	     "/d/city/wumiao"

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
#define MAX_USERS		((int) CONFIG_D->query_int("max users"))

// This defines the minimum wiz_level of users that are allowed to 
// enter the mud. Note players has wiz_level 0.
#define WIZ_LOCK_LEVEL	  ((int) CONFIG_D->query_int("wiz lock"))

#endif
