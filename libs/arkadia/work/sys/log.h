/*
 * sys/log.h
 *
 * This file defines all LOG_ defines relevant to the standard mudlib.
 * It also includes the configurable file /config/sys/log2.h
 * into which you can put more defines.
 */

#ifndef LOG_DEF
#define LOG_DEF

/*
 * Define this flag if you want to log when a player is killed, and by what.
 *
 * Used in: /std/player/death_sec.c
 */
#define LOG_KILLS "KILLS"

/*
 * Define this flag if you want to have a separate log made of playerkills.
 * If you undefine this log, playerkills will be logged among the 'normal'
 * kills.
 *
 * Used in: /std/player/death_sec.c
 */
#define LOG_PLAYERKILLS "PKILLS"

/*
 * Logowanie zmieniania tytulu gracza
 *
 * Uzywane w: /std/player/savevars_sec.c
 */
#define LOG_TITLE "SET_TITLE"

/*
 * Logowanie zmieniania przymiotnikow gracza
 *
 * Uzywane w: /std/player/savevars_sec.c
 */
#define LOG_ADJ "SET_TITLE"

/*
 * Define this flag if you want to log when a players aligment title 
 * is changed.
 *
 * Used in: /std/living/savevars.c
 */
#define LOG_AL_TITLE "SET_AL_TITLE"

/*
 * Define this flag if you want to log when changes are made to a players
 * skills.
 *
 * Used in: /std/living/savevars.c
 */
#define LOG_SET_SKILL "SET_SKILL"

/*
 * Define this flag if you want to log when the game shuts down.
 *
 * Used in: /secure/master.c
 */
#define LOG_SHUTDOWN "SHUTDOWN"

/*
 * Define this flag if you want to log when a players hitpoints are
 * reduced.
 *
 * Used in: /std/living/savevars.c
 */
#define LOG_REDUCE_HP "REDUCE_HP"

/*
 * Define this flag if you want to have a log of all snoop-actions.
 *
 * Used in: /secure/master.c
 */
#define LOG_SNOOP "SNOOP"

/*
 * Define this flag if you want to have all ftp actions logged. Note that
 * there is no argument to this definition.
 *
 * Used in : /secure/master.c
 */
#define LOG_FTP

/*
 * LOG_BOOKKEEP
 *
 * If defined, the file where all xp given by domains to mortals are logged
 * if bigger then a certain limit.
 *
 * Used in: /secure/master/fob.c
 */
#define LOG_BOOKKEEP "DOMAIN_XP"
#define LOG_BOOKKEEP_LIMIT_C 5000
#define LOG_BOOKKEEP_LIMIT_Q 1

/*
 * LOG_BOOKKEEP_ERR
 *
 * If defined, the file where all exp that cannot be put on the account of
 * domains is put. For instance if the function add_exp is called into a
 * mortal directly.
 *
 * Used in: /secure/master/fob.c
 */
#define LOG_BOOKKEEP_ERR "STRANGE_XP"

/*
 * LOG_ECHO
 *
 * Logowanie wszystkich uzyc komend 'echo' i 'echoto'.
 *
 * Uzyte w: /cmd/wiz/normal.c
 */
#define LOG_ECHO "ECHO"

/*
 * The standard names and messages of some logfiles.
 *
 * Used in: /secure/master.c and /cmd/live/info.c
 */
#define LOG_BUG_ID		1
#define LOG_IDEA_ID		2
#define LOG_PRAISE_ID		3
#define LOG_SYSBUG_ID		4
#define LOG_SYSIDEA_ID		5
#define LOG_SYSPRAISE_ID	6

#define LOG_ABORT_MSG(msg)	("Decydujesz sie nie zglaszac niczego.\n")
#define LOG_THANK_MSG(msg)	("Czarodzieje sa ci wdzieczni za " + (msg) + \
					".\n")

#define LOG_TYPES ([	"blad"       : LOG_BUG_ID,       \
			"pomysl"     : LOG_IDEA_ID,      \
			"pochwale"   : LOG_PRAISE_ID ])

#define LOG_MSG(t) ( ({ "ten komentarz",				\
			"raport o bledzie",				\
			"podzielenie sie z nami swymi pomyslami",	\
			"komplementy",					\
			"raport o globalnym bledzie",			\
			"podzielenie sie z nami swymi ogolnymi pomyslami", \
			"twe pochwaly" })[(t)])

#define LOG_PATH(t) ( ({ "report", \
			"/bugs",   \
			"/ideas",  \
			"/praise", \
			"BUGS",    \
			"IDEAS",   \
			"PRAISE" })[(t)])

#include "/config/sys/log2.h"

/* No definitions beyond this line. */
#endif LOG_DEF
