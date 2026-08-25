/*
 * sys/log.h
 *
 * This file defines all LOG_ defines relevant to the standard mudlib.
 * It also includes the configurable file /config/sys/log2.h
 * into which you can put more defines.
 */

#ifndef LOG_DEF
#define LOG_DEF

/* Some definitions to measure log sizes. */
#define LOG_SIZE_100K  100000
#define LOG_SIZE_1M   1000000

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
 * Define this flag if you want to have a separate log made of all attacks from
 * players to players.
 *
 * Used in: /std/player/pcombat.c
 */
#define LOG_PLAYERATTACKS "PATTACKS"

/*
 * Define this flag if you want to log when a players title is changed.
 *
 * Used in: /std/living/savevars.c
 */
#define LOG_TITLE "SET_TITLE"

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
#undef LOG_SET_SKILL "SET_SKILL"

/*
 * Define this flag if you want to log when the game shuts down.
 *
 * Used in: /secure/master.c
 */
#define LOG_SHUTDOWN "SHUTDOWN"

/*
 * Log of the saved recovery string when a player (auto)saves.
 *
 * Used in: /std/player/cmd_sec.c
 */
#define LOG_RECOVER_LIST "RECOVER_LIST"

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
 * Define this flag if echo and echoto should be logged.
 *
 * Used in: /cmd/wiz/normal.c
 */
#define LOG_ECHO "ECHO"

/*
 * Define this flag if pinfo actions should be logged.
 *
 * Used in: /cmd/wiz/apprentice.c and helper.c
 */
#define LOG_PINFO "PINFO"

/*
 * Define this flag if you want to have a log of all wizards registering
 * seconds.
 *
 * Used in: /std/player/savevars_sec.c
 */
#define LOG_SECONDS "SECOND"

/*
 * Define this flag if you want to have a log of all people manipulating
 * the guild definitions.
 *
 * Used in: /secure/master.c
 */
#define GUILD_CMD_LOG "GUILDS"

/*
 * Define this flag if you want to log banishments.
 *
 * Used in: /secure/master.c
 */
#define LOG_BANISH "BANISHED"

/*
 * Define this flag if you want to have all ftp actions logged. Note that
 * there is no argument to this definition.
 *
 * Used in : /secure/master.c
 */
#define LOG_FTP

/*
 * Define this flag if you want to have all ed actions logged. Note that it
 * will not log when there is no file argument to ed.
 *
 * Used in : /secure/master.c
 */
#define LOG_ED_EDIT "ED_EDIT"

/*
 * Define this if you want to have a log of so-called lost UDP messages, i.e
 * those that cannot be handled by the UDP manager.
 *
 * Used in: /secure/master.c
 */
#undef LOG_LOST_UDP
//#define LOG_LOST_UDP "LOST_UDP"

/*
 * Define this flag to create a log of all mail generated automatically be
 * code.
 *
 * Used in: /secure/mail_reader.c
 */
#define LOG_GENERATED_MAIL "GENERATED_MAIL"

/*
 * LOG_BOOKKEEP - If defined, the file where all xp given by domains to mortals
 * are logged if bigger then a certain limit.
 *
 * Used in: /secure/master/fob.c
 */
#define LOG_BOOKKEEP "DOMAIN_XP"
#define LOG_BOOKKEEP_LIMIT_Q  1000
#define LOG_BOOKKEEP_LIMIT_G  2500
#define LOG_BOOKKEEP_LIMIT_C 10000
#define LOG_BOOKKEEP_ROTATE "domain_xp/XP"

/*
 * LOG_BOOKKEEP_ERR - If defined, the file where all exp that cannot be put
 * on the account of domains is put. For instance if the function add_exp is
 * called into a mortal directly.
 *
 * Used in: /secure/master/fob.c
 */
#define LOG_BOOKKEEP_ERR "STRANGE_XP"

/*
 * LOG_SUSPENDED - If defined, it will log when players have been suspended by
 * the administration.
 *
 * Used in /cmd/wiz/arch.c
 */
#define LOG_SUSPENDED "SUSPENDED"

/*
 * LOG_RESTRICTED - If defined, it will log when players impose a playing
 * restriction on themselves or when the administration imposes a
 * restriction on the player
 *
 * Used in /std/player/savevars_sec.c
 */
#define LOG_RESTRICTED "RESTRICTED"

/*
 * LOG_FAILED_RECOVERY - Logs failed recovery / autoload entries
 *
 * Used in: /std/player.c
 */
#define LOG_FAILED_RECOVERY "FAILED_RECOVERY"

/*
 * LOG_ENTER - If defined, it will log whenever a player logs in, quits,
 * linkdies, revives from linkdeath or refreshes his/her link.
 *
 * Used in /secure/master/notify.c
 */
#define LOG_ENTER "enter/ENTER"

/*
 * LOG_STRANGE_LOGIN / LOG_SECOND_LOGIN - If defined, it will log whenever a
 * login is suspicious, and why. The SECOND_LOGIN depends on STRANGE_LOGIN
 * being defined.
 *
 * Used in /secure/login.c
 */
#define LOG_STRANGE_LOGIN "STRANGE_LOGIN"
#define LOG_SECOND_LOGIN  "SECOND_LOGIN"

/*
 * STEAL_EXP - If defined, it will log the experience awareded for the theft.
 *
 * Used in /cmd/live/thief.c
 */
#define STEAL_EXP_LOG "STEAL_EXP"

/*
 * LOG_GMCP - Logs any activity on the Generic MUD Communication Protocol.
 *
 * Used in: /secure/master.c
 */
#define LOG_GMCP "GMCP"

/*
 * AOP_TEAM_LOGS
 *
 * This definition contains a list of logs in /syslog/log that should
 * be visible to members of the AoP team.
 */
#define AOP_TEAM_LOGS ({ "enter",       \
                         "BADNAME",     \
                         "BANISHED",    \
                         "CRITICAL",    \
                         "CHANGE_STAT", \
                         "DELETED",     \
                         "KILLS",       \
                         "MONEY_LOG",   \
                         "PATTACKS",    \
                         "REDUCE_HP",   \
                         "RESTRICTED",  \
                         "PKILLS",      \
                         "STEAL_LOG",   \
                         "SUSPENDED",   \
                         "FAILED_RECOVERY" \
                      })

/*
 * The standard names and messages of some logfiles.
 *
 * Used in: /secure/master.c and /cmd/live/info.c
 */
#define LOG_BUG_ID		1
#define LOG_TYPO_ID		2
#define LOG_IDEA_ID		3
#define LOG_PRAISE_ID		4
#define LOG_DONE_ID 		5
#define LOG_SYSBUG_ID		6
#define LOG_SYSTYPO_ID		7
#define LOG_SYSIDEA_ID		8
#define LOG_SYSPRAISE_ID	9

#define LOG_ABORT_MSG(msg)	("Aborted " + (msg) + ".\n")
#define LOG_THANK_MSG(msg)	("Thanks for " + (msg) + ".\n")

#define LOG_TYPES ([	"bug"      : LOG_BUG_ID,       \
			"done"     : LOG_DONE_ID,      \
			"idea"     : LOG_IDEA_ID,      \
			"praise"   : LOG_PRAISE_ID,    \
			"sysbug"   : LOG_SYSBUG_ID,    \
			"sysidea"  : LOG_SYSIDEA_ID,   \
			"syspraise": LOG_SYSPRAISE_ID, \
			"systypo"  : LOG_SYSTYPO_ID,   \
			"typo"     : LOG_TYPO_ID ])

#define LOG_MSG(t) ( ({ "this special message",      \
			"your bug report",           \
			"reporting the typo",         \
			"sharing your ideas",        \
			"your compliments",          \
			"having done something",     \
			"your system bug report",    \
			"reporting the global typo",  \
			"sharing your global ideas", \
			"your global compliments" })[(t)])

#define LOG_PATH(t) ( ({ "report", \
			"/bugs",   \
			"/typos",  \
			"/ideas",  \
			"/praise", \
			"/done",   \
			"BUGS",    \
			"TYPOS",   \
			"IDEAS",   \
			"PRAISE" })[(t)])

/* No definitions beyond this line. */
#endif LOG_DEF
