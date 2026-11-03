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
#define SEFUN_DIR      SECURE_DIR "sefuns/"

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
#define TERM_D     DAEMON_DIR "termd"

#define WIZ_SHELL  SECURE_OBJ_DIR "player/shell"
#define PLYR_SHELL SECURE_OBJ_DIR "player/shell"

#include "config.h"
#ifndef __MUD_NAME__
#define __MUD_NAME__ "Sagenwelt"
#endif
#ifndef __MUD_IP__
#define __MUD_IP__ "127.0.0.1"
#endif

#ifndef ORIGIN_EFUN
/* FluffOS origin() returns strings (KB 05 7.47) */
#define ORIGIN_LOCAL "local"
#define ORIGIN_CALL_OTHER "call_other"
#define ORIGIN_SIMUL_EFUN "simul"
#define ORIGIN_EFUN "efun"
#endif

/* Pieces archive std.h would have provided (catalog replaces std.h) */
#define I_NONE        0
#define I_NO_ECHO     1
#define I_NO_ESC      2
#define I_SINGLE_CHAR 4
#define INPUT_AUTO_POP 1

#include "syslog.h"
#include "message.h"

#endif
