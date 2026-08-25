/* Do not remove the headers from this file! see /USAGE for more info. */

/*************************************************************************
 **                                                   									**
 **   Configuration file for the Lima Mudlib				                    **
 **                                                   									**
 **   Many things in the Lima Mudlib are configurable to make the game	**
 **   more like what you desire.  					                            **
 ** 									                                                  **
 **   It is recommended that you examine these options carefully.	      **
 ** 									                                                  **
 *************************************************************************/

#ifndef __CONFIG_H__
#define __CONFIG_H__

/*************************************************************************
 ** 									                                                  **
 **  Options which have moved to other files.  All of these should 	    **
 **  be read through.							                                      **
 ** 									                                                  **
 *************************************************************************/

/*
 * Combat options.
 */
#include "combat_modules.h"

/*************************************************************************
 ** 									                                                  **
 **  Options which affect gameplay.					                            **
 ** 									                                                  **
 *************************************************************************/

/* The players start room.
 * This is the default for where players start when they log in. */
#define START "/domains/std/Wizroom"

/* NOTE: if you define this, you have to modify the lib to save the correct
 * variables.*/
#define EVERYTHING_SAVES

/* The default level of light for a room. */
#define DEFAULT_LIGHT_LEVEL 1

/* Players start where they log off */
#define PLAYERS_START_WHERE_THEY_QUIT

/* Do players keep their equipment when they die, or does
** it drop to the corpse.
*/
#undef PLAYERS_DROP_EQUIPMENT_AT_DEATH

/* The default frame style and theme for new players
** can be defined here. See /obj/mudlib/frame.c for the
** entire list of themes.
*/
#define DEFAULT_FRAMES_THEME "dusk"
#define DEFAULT_FRAMES_STYLE "single"

#define USE_QUESTS

/* This only implements races for PC's.*/
#define USE_RACES
#define USE_GUILDS
#define USE_TITLES

/* If you define this option, you should also look at <bodyslots.h> and decide
 * which body slots you want to support.*/
#undef USE_BODYSLOTS

/* Levelling up, how does that happen.
**  define AUTO_LEVEL to level up automatically.
**  define TRAIN_FOR_LEVEL to halt levelling when next one is reached
**  define XP_FACTOR to suit for appetite for speed (default 250)
**  define CAN_LOSE_LEVELS if people can lose experience that levels them down
*/
#define AUTO_LEVEL
#undef TRAIN_FOR_LEVEL
#define XP_FACTOR 250
#define CAN_LOSE_LEVELS

/* Size or Mass?
 * One or the other of these should be defined, but not both.  They should
 * do essentially the same thing. */
#undef USE_SIZE
#ifndef USE_SIZE
#define USE_MASS
#endif

/* If you want weight to be calculated in metric (kilo) rather than imperial (lbs)
   Only works use USE_MASS is defined.
*/
#define METRIC

/* Use skills or not*/
#define USE_SKILLS

/*
 * This is the "maximum" skill level that players are compared against.
 * Their evaluation percentage will be computed as a total of all their
 * skill values relative to this value.  This value should be somewhere
 * between 0 and /std/body/skills.c::MAX_SKILL_VALUE * <number of skills>.
 * Typically, it wouldn't change but a mud that is just starting out might
 * adjust this (causing a reevaluation of everybody) if a number of players
 * are reaching or exceeding this value (which is quite legal).  This value
 * is simply an aid for players to measure progress against (setting it to
 * the maximum would mean that players wouldn't really ever budge anywhere).
 */
#define EVALUATION_SKILL_LEVEL 50000

/*************************************************************************
 ** 									                                                  **
 **  Options affecting the appearance of the game.			                **
 ** 									                                                  **
 *************************************************************************/

/* WELCOME_FILE is the file displayed when someone connects to the game before
 * the login promopt is displayed.
 * If WELCOME_DIR is defined it is assumed that there is a directory of
 * welcome screens and WELCOME_FILE will be ignored. */
#define WELCOME_FILE "/data/config/WELCOME"
#undef WELCOME_DIR "/data/config/welcome_files"

/* The file displayed to new players before the character generation process
 * starts.*/
#define NEW_PLAYER "/data/config/NEW_PLAYER"

/* The file displayed immediatly after login. */
#define MOTD_FILE "/data/config/MOTD"
#define LOGIN_PROMPT "What is your name? "

/* File player referrals are written into */
#define REFERRALS_LOG "/data/referrals"

/* Define where the obvious exits should appear if at all.
 * OBVIOUS_EXITS displays the exits above the long description,
 * OBVIOUS_EXITS_BOTTOM displays them after the long description. */
#undef OBVIOUS_EXITS
#define OBVIOUS_EXITS_BOTTOM

/* Define this if you wish closed doors to show up as an obvious exit */
#undef CLOSED_DOORS_ARE_OBVIOUS_EXITS

/* Define where the obvious exits should appear if at all.
 * in the bodies.  If you save to rooms, then anyone can walk in and read the
 * last part of a say conversation.  */
#define SAY_HISTORY_IN_ROOMS

/* Define the message that playes see when they run into an error. */
#define BUG_MSG "You have just encountered a bug.  Please use the bug command to report it.\n"

/*************************************************************************
 **                                                   									**
 **  Other options which affect users, but not gameplay.            		**
 ** 									                                                  **
 *************************************************************************/

/* Define the character which allows you to call up previous command history.
 * ! will give you problems since it's used as input escape. */
#define HISTORY_CHAR '%'

/* Define the character which allows you to comment out a line in the shell
 * # recommended as default for other shells. */
#define COMMENT_CHAR '#'

/* Define this if players are allowed to have a plan as well as wizards. */
#define EVERYONE_HAS_A_PLAN

/* Define this if names, email addresses and similar data are to be available
 * to I3 and users via finger */
#undef PLAYER_INFO_IS_PUBLIC

/* These defines are the maximum number of seconds to wait at their respective
 * prompts. */
#define LOGIN_NAME_WAIT 300
#define LOGIN_PASSWORD_WAIT 180

/* Disallow new character creation */
#undef NO_NEW_PLAYERS

/* Define this next one to limit how many aliases a person can have. */
#undef MAX_NUMBER_OF_ALIASES 30

/* Define the max number of entries in the channel history (the /last command)
 * This will also be used in say and tell histories */
#define CHANNEL_HISTORY_SIZE 20

/*************************************************************************
 ** 									                                                  **
 **  Wizard/builder handling.      					                            **
 ** 									                                                  **
 *************************************************************************/

/* Define this if you have a lot of wizards */
#undef HANDLE_MANY_WIZARDS

/* Define where your wizards start in the game by default. */
#define WIZARD_START "/domains/std/Wizroom"

/* Auto wiz means guest wizard only.  You still have to use the admtool
 * command to make the person a full wizard w/ a directory. */
#define AUTO_WIZ

/* Wizard Positions are merely a descriptive field to describe what the
 * wizard does.  Define this if you want to use it. */
#define USE_WIZ_POSITION

/* Allow wizards to see hidden exits? */
#define WIZARDS_SEE_HIDDEN_EXITS

/*************************************************************************
 ** 									                                                  **
 **  Options affecting game news and logging.				                    **
 ** 									                                                  **
 *************************************************************************/

/* Define this if you want bug, typo and idea commands to log to /log instead
 * of posting news. */
#undef LOG_DONT_POST

#define BUG_NEWSGROUP "reporter.bugs"
#define TYPO_NEWSGROUP "reporter.typos"
#define IDEA_NEWSGROUP "reporter.ideas"
#define TODO_NEWSGROUP "reporter.todo"
#define QUESTION_NEWSGROUP "reporter.question"
#define FEEDBACK_NEWSGROUP "reporter.discussion"

/*************************************************************************
 ** 									                                                  **
 **  Other stuff. 							                                        **
 ** 									                                                  **
 *************************************************************************/

/* Max file size for editing etc (eg "ulimit -H -d 1200") */
#define MAX_FILE_SIZE 1000000

/* The status of your game.*/
#define lib_status() "mudlib development"

/* What's the IP of your game?*/
#define __HOST__ "localhost"

/* The administrator(s)' email address(es).
 * NOTE: This is required to be changed in order to have a working
 * I3 system. Must be changed for anything to work!
 */
#define ADMIN_EMAIL "billg@microsoft.com"

/* If this is undefined, anonymous ftp is allowed - undef it to prevent.
  Anon ftp users are limited to /ftp/pub.*/
#define ALLOW_ANON_FTP

/* Whether anon ftp users can *put* files.  Only works if ALLOW_ANON_FTP is
 * defined. */
#undef ANON_CAN_PUT

/* The following are to set directory names and short mudname used by
 * the autodoc daemon.
 * You will need to make a dir of MUD_AUTODOC_DIR in /help/autodoc
 * If you plan to make use of this feature. */
#define AUTODOC_MUDNAME "LIMA"
#define MUD_AUTODOC_DIR "lima"

/* Metric definitions */
#define KG_TO_LBS 2.20462262
#define LBS_TO_KG 0.453592

/*************************************************************************
 ** 									                                                  **
 **  Directory specifications.						                              **
 ** 									                                                  **
 *************************************************************************/

/* Where do you want your wizard's shell files to save? */
#ifdef HANDLE_MANY_WIZARDS
#define WSHELL_PATH(x) sprintf("/data/wshells/%c/%s", x[0], x)
#else
#define WSHELL_PATH(x) sprintf("/data/wshells/%s", x)
#endif

/* Define the location of wizards home directories. */
#define WIZ_DIR "/wiz"

/* Define this if you want expanded wizard directories (i.e. /wiz/f/foo) */
#undef EXPANDED_WIZ_DIR

/* Any files listed in this file will be loaded when the game starts. */
#define PRELOAD_FILE "/data/config/preload"

/* It's probably not a good idea to change these. */
#define LINK_PATH(x) sprintf("/data/links/%c/%s", x[0], x)
#define USER_PATH(x) sprintf("/data/players/%c/%s", x[0], x)
#define PSHELL_PATH(x) sprintf("/data/pshells/%c/%s", x[0], x)

#endif __CONFIG_H__

/*
 * runtime_config.h
 *
 * Copy this file to your mudlib include dir for use with the
 * get_config() efun.
 *
 * See Config.Example describing most of these settings.  Some are actually
 * in options.h, but the mudlib doesn't have to know...
 *
 * Note for backwards compatibility:
 *   Neither the name or the number can be changed, or reused, avoid breaking mudlib code.
 */

#ifndef RUNTIME_CONFIG_H
#define RUNTIME_CONFIG_H

#define RC_BASE_CONFIG_STR 0
#define CFG_STR(x) ((x) + RC_BASE_CONFIG_STR)
/*
 * These config settings return a string
 */

#define __MUD_NAME__ CFG_STR(0)
#define __RC_STR_1__ CFG_STR(1)
#define __MUD_LIB_DIR__ CFG_STR(2)
#define __BIN_DIR__ CFG_STR(3)
#define __LOG_DIR__ CFG_STR(4)
#define __INCLUDE_DIRS__ CFG_STR(5)
#define __RC_STR_2__ CFG_STR(6)
#define __MASTER_FILE__ CFG_STR(7)
#define __SIMUL_EFUN_FILE__ CFG_STR(8)
#define __SWAP_FILE__ CFG_STR(9)
#define __DEBUG_LOG_FILE__ CFG_STR(10)
#define __DEFAULT_ERROR_MESSAGE__ CFG_STR(11)
#define __DEFAULT_FAIL_MESSAGE__ CFG_STR(12)
#define __GLOBAL_INCLUDE_FILE__ CFG_STR(13)
#define __MUD_IP__ CFG_STR(14)
#define __RC_WEBSOCKET_HTTP_DIR__ CFG_STR(15)

#define RC_LAST_CONFIG_STR CFG_STR(255)
/*
 * These config settings return an int (ie number)
 */
#define RC_BASE_CONFIG_INT (RC_LAST_CONFIG_STR + 1)
#define CFG_INT(x) ((x) + RC_BASE_CONFIG_INT)

#define __MUD_PORT__ CFG_INT(0)
#define __RC_INT_1__ CFG_INT(1)
#define __TIME_TO_CLEAN_UP__ CFG_INT(2)
#define __TIME_TO_RESET__ CFG_INT(3)
#define __TIME_TO_SWAP__ CFG_INT(4)
#define __COMPILER_STACK_SIZE__ CFG_INT(5)
#define __EVALUATOR_STACK_SIZE__ CFG_INT(6)
#define __INHERIT_CHAIN_SIZE__ CFG_INT(7)
#define __MAX_EVAL_COST__ CFG_INT(8)
#define __MAX_LOCAL_VARIABLES__ CFG_INT(9)
#define __MAX_CALL_DEPTH__ CFG_INT(10)
#define __MAX_ARRAY_SIZE__ CFG_INT(11)
#define __MAX_BUFFER_SIZE__ CFG_INT(12)
#define __MAX_MAPPING_SIZE__ CFG_INT(13)
#define __MAX_STRING_LENGTH__ CFG_INT(14)
#define __MAX_BITFIELD_BITS__ CFG_INT(15)
#define __MAX_BYTE_TRANSFER__ CFG_INT(16)
#define __MAX_READ_FILE_SIZE__ CFG_INT(17)
#define __RC_INT_18__ CFG_INT(18)
#define __SHARED_STRING_HASH_TABLE_SIZE__ CFG_INT(19)
#define __OBJECT_HASH_TABLE_SIZE__ CFG_INT(20)
#define __LIVING_HASH_TABLE_SIZE__ CFG_INT(21)
#define __RC_INT_22__ CFG_INT(22)
#define __RC_INT_23__ CFG_INT(23)
#define __RC_GAMETICK_MSEC__ CFG_INT(24)
#define __RC_HEARTBEAT_INTERVAL_MSEC__ CFG_INT(25)
#define __RC_SANE_EXPLODE_STRING__ CFG_INT(26)
#define __RC_REVERSIBLE_EXPLODE_STRING__ CFG_INT(27)
#define __RC_SANE_SORTING__ CFG_INT(28)
#define __RC_WARN_TAB__ CFG_INT(29)
#define __RC_WOMBLES__ CFG_INT(30)
#define __RC_CALL_OTHER_TYPE_CHECK__ CFG_INT(31)
#define __RC_CALL_OTHER_WARN__ CFG_INT(32)
#define __RC_MUDLIB_ERROR_HANDLER__ CFG_INT(33)
#define __RC_NO_RESETS__ CFG_INT(34)
#define __RC_LAZY_RESETS__ CFG_INT(35)
#define __RC_RANDOMIZED_RESETS__ CFG_INT(36)
#define __RC_NO_ANSI__ CFG_INT(37)
#define __RC_STRIP_BEFORE_PROCESS_INPUT__ CFG_INT(38)
#define __RC_THIS_PLAYER_IN_CALL_OUT__ CFG_INT(39)
#define __RC_TRACE__ CFG_INT(40)
#define __RC_TRACE_CODE__ CFG_INT(41)
#define __RC_INTERACTIVE_CATCH_TELL__ CFG_INT(42)
#define __RC_RECEIVE_SNOOP__ CFG_INT(43)
#define __RC_SNOOP_SHADOWED__ CFG_INT(44)
#define __RC_REVERSE_DEFER__ CFG_INT(45)
#define __RC_HAS_CONSOLE__ CFG_INT(46)
#define __RC_NONINTERACTIVE_STDERR_WRITE__ CFG_INT(47)
#define __RC_TRAP_CRASHES__ CFG_INT(48)
#define __RC_OLD_TYPE_BEHAVIOR__ CFG_INT(49)
#define __RC_OLD_RANGE_BEHAVIOR__ CFG_INT(50)
#define __RC_WARN_OLD_RANGE_BEHAVIOR__ CFG_INT(51)
#define __RC_SUPPRESS_ARGUMENT_WARNINGS__ CFG_INT(52)
#define __RC_ENABLE_COMMANDS_CALL_INIT__ CFG_INT(53)
#define __RC_SPRINTF_ADD_JUSTFIED_IGNORE_ANSI_COLORS__ CFG_INT(54)
#define __RC_APPLY_CACHE_BITS__ CFG_INT(55)
#define __RC_CALL_OUT_ZERO_NEST_LEVEL__ CFG_INT(56)
#define __RC_TRACE_CONTEXT__ CFG_INT(57)
#define __RC_TRACE_INSTR__ CFG_INT(58)
#define __RC_ENABLE_MXP__ CFG_INT(59)
#define __RC_ENABLE_GMCP__ CFG_INT(60)
#define __RC_ENABLE_ZMP__ CFG_INT(61)
#define __RC_ENABLE_MSSP__ CFG_INT(62)
#define __RC_ENABLE_MSP__ CFG_INT(63)

#define RC_LAST_CONFIG_INT CFG_INT(255)
#endif /* RUNTIME_CONFIG_H */