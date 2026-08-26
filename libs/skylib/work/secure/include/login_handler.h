/**
 * The include file for the login handler.
 * @author Pinkfish
 */
#ifndef __SYS__LOGIN_HANDLER
/** @ignore yes */
#define __SYS__LOGIN_HANDLER

#include <player_handler.h>

/**
 * The path to the login handler.
 */
#define LOGIN_HANDLER "/handlers/login_handler"

/** The name of the login event.  Used in the nosave/dynamic login calls. */
#define LOGIN "login"
/** The name of the logout event.  Used in the nosave/dynamic login calls. */
#define LOGOUT "logout"
/** The name of the netdeath event.  Used in the nosave/dynamic login calls. */
#define NETDEATH "netdeath"
/** The name of the reconnect event.  Used in the nosave/dynamic login calls. */
#define RECONNECT "reconnect"

/** The maximum number of players online at Discworld at once. */
#define MAX_PLAYERS 175

/** Flag to the is_discworld_full method. */
#define WITHOUT_LOGINS_NOT_IN_QUEUE 3
/** Flag to the is_discworld_full method. */
#define WITHOUT_ANY_LOGINS 2
/** Flag to the is_discworld_full method. */
#define WITHOUT_LOGIN_QUEUE 1
/** Flag to the is_discworld_full method. */
#define WITH_LOGIN_QUEUE    0

#endif /* __SYS__LOGIN_HANDLER */
