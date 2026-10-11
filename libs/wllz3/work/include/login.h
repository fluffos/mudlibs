// login.h

#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT           240

#define WELCOME                 CONFIG_DIR +"/welcome"
#define NEW_PLAYER_INFO         CONFIG_DIR +"/new_player"
#define UNREG_MOTD              CONFIG_DIR +"/unreg_motd"
#define MOTD                    CONFIG_DIR +"/motd"
#define WIZLIST			CONFIG_DIR +"wizlist"

#define WIZ_START_ROOM          "/d/wizard/wizard_room.lpc"

#define START_ROOM              "/d/center/inn.lpc"
#define NEW_PLAYER_START        "/d/welcome/wel1.lpc"
#define DEATH_ROOM              "/d/death/gate.lpc"
#define REVIVE_ROOM             "/d/center/guandimiao.lpc"

#define REBOOT_TIME             259200

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)

#define MAX_USERS               300

#define ENABLE_MD5_PASSWORD

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK             "/d/wiz/courthouse"

// This defines the minimum wiz_level of users that are allowed to
// enter the mud. Note players has wiz_level 0.
#define WIZ_LOCK_LEVEL          0
#define NO_USER			0

#endif
