#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT			300

#define WELCOME				"/adm/etc/welcome"
#define NEW_PLAYER_INFO			"/adm/etc/new_player"
#define MOTD				"/adm/etc/motd"
#define WIZ_MOTD			"/adm/etc/motd.wiz"
#define WIZLIST				"/adm/etc/wizlist"
#define WIZBOSS				"/adm/etc/wizboss"
#define COP_HEAD                        "/open/common/npc/cop"
#define CHECK_MAIL		        "/adm/etc/check_mail"
#define BANNED_IP           		"/adm/etc/banned_ip"
#define STARTROOM           		"/open/newhand/newhand"
#define DEATHROOM			"/open/death/start"
#define REVIVEROOM                      "/open/common/room/inn"

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
//#define MAX_USERS    500 // 平时人数上限
//#define MAX_USERS_2  500 // tintin人数上限

// multi login 人数限制 by ACKY
#define MAX_MULTI_USUAL		10 // 平常时段
#define MAX_MULTI_UNUSUAL	20 // 非平时时段
#define MAX_MULTI_SPECIAL	20 // 特殊IP (例如:雄专全部共用同一IP)

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK			"/open/wiz/courthouse"

// 想要不让玩家上线, 可以把 undef 改成 define, 然后 update /adm/daemons/logind
// 反之, 要取消则把 define 改成 undef, 当然也要 update /adm/daemons/logind
// 或者想限制总上线人数, 则改 MAX_USERS 的数值.
#define LOCK_PLAYER  "\n\nsorry. 现在修理中\n\n\n"
#undef LOCK_WIZARD "\n\n巫师请连往 140.122.77.123 1234 开发新区域.\n\n\n"

#endif
