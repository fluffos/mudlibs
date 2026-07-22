// Modified by Find.

#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT		300

// define this if you want a new player to register
// by a valid email address.
#undef MAIL_REG

#define BLOCK_HACK_WIZ			/* define 这项防止猜测巫师账号的密码 */
#undef BLOCK_HACK_ALL			/* define 这项对所有的账号防止密码猜测,但有弊端 */

#define WIZ_PASSWD_CHK

#undef REFUSE_NEW_PLAYER                /* 如果 define 这一项将不接受新玩家登记 */

#define WELCOME				"/adm/etc/welcome"
#define NEW_PLAYER_INFO			"/adm/etc/new_player"
#define MOTD				"/adm/etc/motd"
#define WIZMOTD				"/adm/etc/wizmotd"  //find.
#define TITLE                           "/adm/etc/title"    // find.
#define WIZLIST				"/adm/etc/wizlist"

#define REGISTER_ROOM			"/d/wiz/register"
#define WELCOME_ROOM			"/d/wiz/welcome"
#define START_ROOM                      "/d/changan/jiulou"
#define DEATH_ROOM			"/d/death/gate"
#define REVIVE_ROOM			"/d/changan/jiulou"

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
#define MAX_USERS			200
#define MAX_SAME_IP                     10

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK			"/d/wiz/courthouse"

// This defines the minimum wiz_level of users that are allowed to 
// enter the mud. Note players has wiz_level 0.

// modified by find. for mud down can't wizlock.
// 正式开放以后修改回来,要加入新人可以 wizlock (player).
//#define WIZ_LOCK_LEVEL 0
#define WIZ_LOCK_LEVEL 0
// end.

#endif

