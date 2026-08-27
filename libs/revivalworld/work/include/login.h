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

// Originally a 3-separate-port architecture (a real player port, a
// wizard-only port, and a "special client" protocol port -- each meant
// to run as its own driver instance on the real server); login_ob.lpc's
// logon() dispatches purely on query_ip_port() and returns 0 (no login
// daemon at all, connection just hangs with no banner) for any port
// that doesn't match one of these three. This project's convention
// (like every other lib in this collection) runs a single port for
// everything, with admin status granted per-account rather than
// per-connection-port -- so route that one real port through the
// normal player login flow (PPL_LOGIN_D). See AGENTS.md 5.3.
#define PPL_PORT		40238
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

