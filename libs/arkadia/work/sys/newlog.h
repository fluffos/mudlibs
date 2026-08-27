/*
   sys/log.h

   This file defines all LOG_ defines relevant to the standard mudlib.
   It also includes the configurable file /config/sys/log2.h
   into which you can put more defines.
 */
#ifndef LOG_DEF
#define LOG_DEF

/*
 * Define this flag if you want to log when a player is killed, and by what.
 *
 * Used in: std/player/death_sec.c
 */
#define LOG_KILLS "KILL_PLAYER"

/*
 * Define this flag if you want to log when a players title is changed.
 *
 * Used in: std/living/savevars.c
 */
#define LOG_TITLE "SET_TITLE"

/*
 * Define this flag if you want to log when a players aligment title 
 * is changed.
 *
 * Used in: std/living/savevars.c
 */
#define LOG_AL_TITLE "SET_AL_TITLE"

/*
 * Define this flag if you want to log when a players hitpoints are
 * reduced.
 *
 * Used in: std/living/savevars.c
 */
#define LOG_REDUCE_HP "REDUCE_HP"

/*
 * LOG_BOOKKEEP
 *
 * If defined, the file where all xp given by domains to mortals are logged
 * if bigger then a certain limit.
 *
 * Used in: /secure/master/fob.c
 */
#define LOG_BOOKKEEP "DOMAIN_XP"
#define LOG_BOOKKEEP_LIMIT_C 1000
#define LOG_BOOKKEEP_LIMIT_Q 0

/*
 * The standard names and messages of some logfiles.
 *
 * Used in: /secure/master.c and /cmd/live/info.c
 */
#define LOG_BUG_ID	1
#define LOG_TYPO_ID	2
#define LOG_IDEA_ID	3
#define LOG_PRAISE_ID	4
#define LOG_SYSBUG_ID	5

#define LOG_BUG_FILE	"/bugs"
#define LOG_TYPO_FILE	"/typos"
#define LOG_IDEA_FILE	"/ideas"
#define LOG_PRAISE_FILE	"/praise"
#define LOG_SYSBUG_FILE ""

#define LOG_ABORT_MSG(msg) "Aborted " + msg + ".\n"
#define LOG_THANK_MSG(msg) "Thanks for " + msg + ".\n"

#define LOG_BUG_MSG	"your bug report"
#define LOG_TYPO_MSG	"noticing the typo"
#define LOG_IDEA_MSG	"sharing your ideas"
#define LOG_PRAISE_MSG	"your compliments"
#define LOG_SYSBUG_MSG	"your system bug report"

#include "/config/sys/log2.h"
#endif
