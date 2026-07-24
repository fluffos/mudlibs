#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT		120

#define WELCOME				"/adm/etc/welcome"
#define NEW_PLAYER_INFO	        	"/adm/etc/new_player"
#define MOTD				"/adm/etc/motd"

#define WIZLIST				"/adm/etc/wizlist"

#define START_ROOM 			"/d/zhongzhou/yinghao"
#define DEATH_ROOM			"/d/death/gate"
// NOTE: the archive's original value here was "/d/yangzhou/temple" (隋
// 炀帝陵), which belonged to an OLDER, entirely different "yangzhou" zone
// now archived under d/yz_bak/yangzhou/ -- the live d/yangzhou/ is an
// unrelated, incompatible zone rewrite that never got a "temple" room, so
// every call_other() to the old path fails with "couldn't find object"
// (confirmed live: crashes d/death/npc/{wgargoyle,bgargoyle}.lpc's
// death_stage() -> reincarnate flow on EVERY player death, right after
// the death-realm dialogue finishes). Repointed at START_ROOM, the same
// always-loadable fallback enter_world() already uses for a broken/
// missing custom startroom, rather than resurrecting the disconnected
// old zone.
#define REVIVE_ROOM			START_ROOM

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
#define MAX_USERS                       100

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK			"/d/wiz/robotcheck"

// This defines the minimum wiz_level of users that are allowed to 
// enter the mud. Note players has wiz_level 0.
#define WIZ_LOCK_LEVEL 0

#endif
