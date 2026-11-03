#ifndef __SAGENWELT_CATALOG_GLOBALS__
#define __SAGENWELT_CATALOG_GLOBALS__

/* Catalog overlay global include. Archive std.h pulls simul_efun.h (does not
 * compile); we still need path macros and this_object shortcuts so archive
 * modules that inherit P_INPUT / MOVE / LIVING can parse under FluffOS. */

#define FALSE 0
#define TRUE  1

#define TO this_object
#define TI this_interactive
#define TP this_player
#define PO previous_object

#define SECURE_DIR     "/secure/"
#define DAEMON_DIR     SECURE_DIR "daemons/"
#define SECURE_OBJ_DIR SECURE_DIR "obj/"
#define SECURE_LIB_DIR SECURE_DIR "lib/"
#define STD_LIB        "/std/lib/"

#define P_INPUT   SECURE_LIB_DIR "player/inp_sys"
#define P_MESSAGE SECURE_LIB_DIR "player/messages"
#define P_SHELL   SECURE_LIB_DIR "player/shell"
#define M_INPUT   SECURE_LIB_DIR "input"
#define M_MENU    SECURE_LIB_DIR "menu"
#define MOVE      SECURE_LIB_DIR "move"
#define LIVING    STD_LIB "living"
#define ROOM      STD_LIB "room"
#define STD_OBJECT STD_LIB "object"
#define CONTAINER STD_LIB "container"

#define LOGIN_OB  SECURE_OBJ_DIR "player/login"
#define PLAYER_OB SECURE_OBJ_DIR "player/player"

#define SYSLOG_D  DAEMON_DIR "syslogd"
#define MUD_INFO_D DAEMON_DIR "mud_info"

#include "config.h"
#ifndef __MUD_NAME__
#define __MUD_NAME__ "Sagenwelt"
#ifndef ORIGIN_EFUN
/* FluffOS origin() returns strings (KB 05 7.47) */
#define ORIGIN_LOCAL "local"
#define ORIGIN_CALL_OTHER "call_other"
#define ORIGIN_SIMUL_EFUN "simul"
#define ORIGIN_EFUN "efun"
#endif

#endif
#ifndef __MUD_IP__
#define __MUD_IP__ "127.0.0.1"
#ifndef ORIGIN_EFUN
/* FluffOS origin() returns strings (KB 05 7.47) */
#define ORIGIN_LOCAL "local"
#define ORIGIN_CALL_OTHER "call_other"
#define ORIGIN_SIMUL_EFUN "simul"
#define ORIGIN_EFUN "efun"
#endif

#endif


#define WIZ_SHELL  SECURE_OBJ_DIR "player/shell"
#define PLYR_SHELL SECURE_OBJ_DIR "player/shell"

#ifndef ORIGIN_EFUN
/* FluffOS origin() returns strings (KB 05 7.47) */
#define ORIGIN_LOCAL "local"
#define ORIGIN_CALL_OTHER "call_other"
#define ORIGIN_SIMUL_EFUN "simul"
#define ORIGIN_EFUN "efun"
#endif

#endif
