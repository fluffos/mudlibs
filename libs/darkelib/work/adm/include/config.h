#ifndef __CONFIG_H
#define __CONFIG_H

#include "options.h"

#define __nightmare__            3.2
#define MUDLIB_VERSION		"0.2"
#define MUDLIB			"DarkeLIB"
#define MUD_IS_LOCKED 0

#define GMT_OFFSET               -32000
#define MAX_LOG_SIZE             150000
#define MAX_NET_DEAD_TIME        1800

#define LOGON_TIMEOUT            180
#define MAX_PASSWORD_TRIES       2
#define MIN_USER_NAME_LENGTH     2
#define MAX_USER_NAME_LENGTH     15
#define MAX_USERS		 100 
#define LOCKED_ACCESS_ALLOWED    ({ "superuser", "assist", "wizard", "creator", "wiz", "elder", "mentor" })
#define MORTAL_POSITIONS         ({ "player", "high mortal" })

#endif /* __CONFIG_H */
