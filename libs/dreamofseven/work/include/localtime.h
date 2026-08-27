
/*
 * Definitions for localtime() efun
 */

#define LT_SEC		0
#define LT_MIN		1
#define LT_HOUR		2
#define LT_MDAY		3
#define LT_MON		4
#define LT_YEAR		5
#define LT_WDAY		6
#define LT_YDAY		7
#define LT_GMTOFF	8
#define LT_ZONE		9

#define DAWN_PHASE	0
#define SUNRISE_PHASE	1
#define MORNING_PHASE	2
#define NOON_PHASE	3
#define AFTERNOON_PHASE	4
#define EVENING_PHASE	5
#define NIGHT_PHASE	6
#define MIDNIGHT_PHASE	7

#define REAL_TIME_TICK (time())
#define GAME_TIME_TICK (time()*30)
