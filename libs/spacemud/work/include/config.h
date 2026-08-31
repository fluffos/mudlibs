/* Do not remove the headers from this file! see /USAGE for more info. */

/*************************************************************************
 **                                                                     **
 **   Configuration file for the LIMA Mudlib                            **
 **                                                                     **
 **   Many things in the LIMA Mudlib are configurable to make the game  **
 **   more like what you desire.                                        **
 **                                                                     **
 **   It is recommended that you examine these options carefully.       **
 **                                                                     **
 *********************************************************************** */

#ifndef __CONFIG_H__
#define __CONFIG_H__

/* Driver's runtime config, don't touch */
#include <driver/runtime_config.h>

/*************************************************************************
 **                                                                     **
 **  Options which have moved to other files.  All of these should      **
 **  be read through.                                                   **
 **                                                                     **
 *********************************************************************** */

/* * Combat options. */
#include "combat_modules.h"

/*************************************************************************
 **                                                                     **
 **  Options which affect gameplay.                                     **
 **                                                                     **
 *********************************************************************** */

/* The players start room.
 * This is the default for where players start when they log in. */
#define START "/domains/std/room/Wizroom"

/* NOTE: if you define this, you have to modify the lib to save the correct
 * variables */
#define EVERYTHING_SAVES

/* The default level of light for a room. */
#define DEFAULT_LIGHT_LEVEL 1

/* Players start where they log off */
#define PLAYERS_START_WHERE_THEY_QUIT

/* Body stats modules -  do not these  */
#define BODY_STATS_LIMA 1
#define BODY_STATS_DND 2
#define BODY_STATS_RIFTS 3

/* But edit here:
** Edit body stats module to use. Only one option can be picked below. */
#define BODY_STATS BODY_STATS_LIMA

/* Do players keep their equipment when they die, or does
** it drop to the corpse. */
#undef PLAYERS_DROP_EQUIPMENT_AT_DEATH


#define USE_QUESTS

/* This only implements races for PC's */
#define USE_RACES
#define USE_GUILDS
#define USE_TITLES
#undef USE_INTRODUCTIONS

/* If you define this option, you should also look at <bodyslots.h> and decide
 * which body slots you want to support */
#undef USE_BODYSLOTS

/* Levelling up, how does that happen.
 * define AUTO_LEVEL to level up automatically.
 * define TRAIN_FOR_LEVEL to halt levelling when next one is reached
 * define XP_FACTOR to suit for appetite for speed (default 250)
 * define CAN_LOSE_LEVELS if people can lose experience that levels them down */
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
   Only works use USE_MASS is defined. */
#define METRIC

/* Use skills or no */
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
 **                                                                     **
 **  Options affecting the appearance of the game.                      **
 **                                                                     **
 *********************************************************************** */

/* Default screen width, when the user didn't set a width */
#define DEFAULT_SCREEN_WIDTH 79
#define DEFAULT_SCREEN_HEIGHT 40

/* The default frame style and theme for new players
 * can be defined here. See /obj/mudlib/frame.c for the
 * entire list of themes. */
#define DEFAULT_FRAMES_THEME "dusk"
#define DEFAULT_FRAMES_STYLE "single"

/* WELCOME_FILE is the file displayed when someone connects to the game before
 * the login promopt is displayed.
 * If WELCOME_DIR is defined it is assumed that there is a directory of
 * welcome screens and WELCOME_FILE will be ignored. */
#define WELCOME_FILE "/data/config/WELCOME"
#undef WELCOME_DIR "/data/config/welcome_files"

/* The file displayed to new players before the character generation process
 * starts */
#define NEW_PLAYER "/data/config/NEW_PLAYER"

/* The file displayed immediatly after login. */
#define MOTD_FILE "/data/config/MOTD"
#define LOGIN_PROMPT "What is your name? "

/* File player referrals are written into */
#define REFERRALS_LOG "/data/referrals"

/* Define where the obvious exits should appear if at all.
 * OBVIOUS_EXITS_TOP displays the exits top of the long description,
 * OBVIOUS_EXITS_BOTTOM displays them after the long description,
 * COUNT_EXITS counts the obvious exits in the description.
 */
#undef OBVIOUS_EXITS_TOP
#define OBVIOUS_EXITS_BOTTOM
#undef COUNT_EXITS

/* Define this if you wish closed doors to show up as an obvious exit */
#undef CLOSED_DOORS_ARE_OBVIOUS_EXITS

/* Define where the obvious exits should appear if at all.
 * in the bodies.  If you save to rooms, then anyone can walk in and read the
 * last part of a say conversation.  */
#define SAY_HISTORY_IN_ROOMS

/* Define the message that playes see when they run into an error. */
#define BUG_MSG \
  "You have just encountered a bug.  Please use the bug command to report it.\n"

/*************************************************************************
 **                                                                     **
 **  Other options which affect users, but not gameplay.                **
 **                                                                     **
 *********************************************************************** */

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
 **                                                                     **
 **  Wizard/builder handling.                                           **
 **                                                                     **
 *********************************************************************** */

/* Define this if you have a lot of wizards */
#undef HANDLE_MANY_WIZARDS

/* Define where your wizards start in the game by default. */
#define WIZARD_START "/domains/std/room/Wizroom"

/* Auto wiz means guest wizard only.  You still have to use the admtool
 * command to make the person a full wizard w/ a directory. */
#define AUTO_WIZ

/* Wizard Positions are merely a descriptive field to describe what the
 * wizard does.  Define this if you want to use it. */
#define USE_WIZ_POSITION

/* Allow wizards to see hidden exits? */
#define WIZARDS_SEE_HIDDEN_EXITS

/*************************************************************************
 **                                                                     **
 **  Options affecting game news and logging.                           **
 **                                                                     **
 *********************************************************************** */

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
 **                                                                     **
 **  Other stuff.                                                       **
 **                                                                     **
 *********************************************************************** */

/* Max file size for editing etc (eg "ulimit -H -d 1200") */
#define MAX_FILE_SIZE 1000000

/* Delay factor for DAEMON call_outs(). 
 * Some daemons may be a bit too greedy for your machine causing:
 * "Too long evaluation. Execution aborted."
 * If you are getting these increase this number to 5, or 10.
 * Otherwise, enjoy your powerful machine, and keep it at 1.
 */
#define TOO_GREEDY_DAEMONS 1

/* The status of your game */
#define lib_status() "mudlib development"

/* What's the IP of your game */
#define __HOST__ "localhost"

/* The administrator(s)' email address(es).
 * NOTE: This is required to be changed in order to have a working
 * I3/IMUD_D system. Must be changed for anything to work!
 */
#define ADMIN_EMAIL "tsathoqqua@gmail.com"

/* If this is undefined, anonymous ftp is allowed - undef it to prevent.
  Anon ftp users are limited to /ftp/pub */
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
 **                                                                     **
 **  Directory specifications.                                          **
 **                                                                     **
 *********************************************************************** */

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
