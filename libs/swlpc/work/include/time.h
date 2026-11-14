#define MORNING 25200 /* 31000 - second count of when to finish */
#define EVENING 68400  /* 63000 - second count of when to start */
#define DAY 86400	/* no of secs in a day */
#define TIME_ADJUST 36000 /* +10hrs EST, +11hrs ESST */
/* #define	TIME_ADJUST	(36000+3600)	/* daylight saving time! */

#define REAL_SEC_TO_GAME_MIN 5    /* How many seconds to a game minute */ 
#define MUD_MINUTE REAL_SEC_TO_GAME_MIN
#define MUD_HOUR (60 * MUD_MINUTE) 
#define MUD_DAY (24 * MUD_HOUR)
#define MUD_MONTH (28 * MUD_DAY)
#define MUD_YEAR (12 * MUD_MONTH)

/* NB: Armageddon now has an array of shut times - G. */
