#define __nightmare__            3.2
#undef MUDLIB   /* conf.h and config.h both define it; the header included last wins */
#define MUDLIB                   "ShadowGate"
#undef MUDLIB_VERSION   /* conf.h and config.h both define it; the header included last wins */
#define MUDLIB_VERSION           "999"

#undef MUD_IS_LOCKED   /* conf.h and config.h both define it; the header included last wins */
#define MUD_IS_LOCKED 0

#undef GMT_OFFSET   /* conf.h and config.h both define it; the header included last wins */
#define GMT_OFFSET               0
#undef MAX_LOG_SIZE   /* conf.h and config.h both define it; the header included last wins */
#define MAX_LOG_SIZE             350000
#define MAX_NET_DEAD_TIME        1800

#define LOGON_TIMEOUT            180
#define MAX_PASSWORD_TRIES       3
#define MIN_USER_NAME_LENGTH     2
#define MAX_USER_NAME_LENGTH     15
#define LOCKED_ACCESS_ALLOWED    ({ "superuser", "assist" })

#undef MORTAL_POSITIONS   /* conf.h and config.h both define it; the header included last wins */
#define MORTAL_POSITIONS         ({"newbie","player","avatar", "high mortal"})
