#ifndef __CONFIG_H
#define __CONFIG_H

#define DEFAULT_PROMPT           "> "

#define MUD_STATUS               "open to public"
#define ADMIN_EMAIL                "beek@imaginary.com"
#define MUD_IS_LOCKED            0

#define GMT_OFFSET               -32000
#define MAX_LOG_SIZE             150000
#define MAX_NET_DEAD_TIME        1800
#define MINUTES_REBOOT_WARNING   20

#define LOGON_TIMEOUT            180
#define MAX_PASSWORD_TRIES       3
#define MIN_USER_NAME_LENGTH     2
#define MAX_USER_NAME_LENGTH     15
#define MAX_USER_CAP_NAME_LENGTH 20
#define LOCKED_ACCESS_ALLOWED    ({ "SUPERUSER", "ASSIST" })
#define SUPPORTED_CLIENTS       ({ "amcp", "amcp/1.1" })

#define MAX_NEWBIE_LEVEL         5
#define AUTOSAVE_TIME            450
#define MORTAL_POSITIONS         ({ "player", "high mortal", "ambassador" })

#define DEFAULT_GRAVITY          1.0
#define DEFAULT_ITEM_MESSAGE     "You do not see that here."

#endif /* __CONFIG_H */
