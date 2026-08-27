#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT		180

#define WELCOME				"/adm/etc/welcome"
#define NEW_PLAYER_INFO			"/adm/etc/new_player"
#define MOTD				"/adm/etc/motd"
#define WIZNOTE				"/adm/etc/wiznote"

#define WIZLIST				"/adm/etc/wizlist"

#define START_ROOM			"/open/world2/anfernee/start/hall"
#define START_ROOM_NEWBIE		"/open/world1/tmr/area/school/school1"
//#define START_ROOM_NOW                  "/open/world2/lichi_town_2/map_5_26"
#define START_ROOM_NOW                  "/open/world2/anfernee/start/hall"
#define START_ROOM_PAST			"/open/world1/tmr/area/hotel"
//#define START_ROOM_FUTURE               "/open/world3/tmr/basic/hotel"
#define START_ROOM_FUTURE               "/open/world2/anfernee/start/hall"
#define DEATH_ROOM			"/open/world2/anfernee/start/prayroom"
#define REVIVE_ROOM			"/open/world2/anfernee/start/prayroom"

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
#define MAX_USERS           400

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK			"/d/wiz/courthouse"

// This defines the minimum wiz_level of users that are allowed to 
// enter the mud. Note players has wiz_level 0.
#define WIZ_LOCK_LEVEL 0

#endif
