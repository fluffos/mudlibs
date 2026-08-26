// Configuration file for the Lima Mudlib

#ifndef __CONFIG_H__
#define __CONFIG_H__


// Options which have moved to other files

// Combat options.
#include "combat_modules.h"


// Options which affect gameplay

// Rooms
#define START            "/d/coru/main"
#define NEW_PLAYER_START "/d/coru/main"
#define CREATE_ROOM      "/obj/mudlib/create_room"
#define LINKDEAD_FREEZER "/d/common/freezer"

// The default level of light for a room
#define DEFAULT_LIGHT_LEVEL     1

#define PLAYERS_START_WHERE_THEY_QUIT

#define USE_QUESTS

// This only implements races for player characters
#define USE_RACES

#define USE_STATS

#define USE_TITLES

// If you define this option, you should also look at <bodyslots.h>
#define USE_BODYSLOTS

// Monster race support
#define USE_MON_RACES

#define USE_MASS

/* If you want weight to be calculated in metric (kilo) rather than
   imperial (lbs) by default. Restored from the upstream Lima base this
   archive installs over -- swmud's own config.h dropped it, but
   secure/simul_efun/string.lpc's weight_to_string() (ported back in,
   see NOTES.md) and std/modules/m_companion.lpc both need it. */
#define METRIC
#define KG_TO_LBS 2.20462262
#define LBS_TO_KG 0.453592

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
#undef EVALUATION_SKILL_LEVEL  50000



// Options affecting the appearance of the game

// WELCOME_FILE is displayed before the login promopt when someone connects to the game
// If WELCOME_DIR is defined it is assumed that there is a directory of
// welcome screens and WELCOME_FILE will be ignored.
#define WELCOME_FILE             "/data/config/WELCOME"
#undef WELCOME_DIR              "/data/config/welcome_files"

// The file displayed to new players before the character generation process starts
#define NEW_PLAYER              "/data/config/NEW_PLAYER"

// The file displayed immediatly after login
#define MOTD_FILE               "/data/config/MOTD"

#define LOGIN_PROMPT            "Player name: "

// Define where the obvious exits should appear if at all
// OBVIOUS_EXITS displays the exits above the long description,
// OBVIOUS_EXITS_BOTTOM displays them after the long description.
#undef OBVIOUS_EXITS
#define OBVIOUS_EXITS_BOTTOM

// Define this if you wish closed doors to show up as an obvious exit
#undef CLOSED_DOORS_ARE_OBVIOUS_EXITS

#undef SAY_HISTORY_IN_ROOMS


// Define the message that players see when they run into an error
#define BUG_MSG \
"You have just encountered a bug.  Please use the bug command to report it.\n"

// Define this to use an Infocom-like Status line.
#define USE_STATUS_LINE


// Other options which affect users, but not gameplay

// Define the character which allows you to call up previous command history
// ! will give you problems since it's used as input escape
#define HISTORY_CHAR            '%'

// Define this if players are allowed to have a plan as well as wizards
#undef EVERYONE_HAS_A_PLAN

// Define this if names, email addresses and similar data are to be available to users via finger
#undef PLAYER_INFO_IS_PUBLIC

// These defines are the maximum number of seconds to wait at their respective prompts
#define LOGIN_NAME_WAIT         300
#define LOGIN_PASSWORD_WAIT     180

// Disallow new character creation
// Disabled for this project: this deployment exists so site visitors can
// register and actually play the mudlib, so a closed-beta gate that
// rejects all new registrations would defeat the point. Not a program
// bug fix -- a deliberate deployment config change. See NOTES.md.
#undef NO_NEW_PLAYERS

// Define these to limit how many aliases and nicknames a person can have
#define MAX_NUMBER_OF_ALIASES    150
#define MAX_NUMBER_OF_NICKNAMES  150

// Define the max number of entries in the channel history (the /last command)
// This will also be used in say and tell histories
#define CHANNEL_HISTORY_SIZE    30


// Wizard/builder handling

// Define this if you have a lot of wizards
#undef HANDLE_MANY_WIZARDS

// Define where your wizards start in the game by default
// Upstream's own value here ("/domains/std/Wizroom", Lima's stock "Grand
// Hall" demo room) fails at runtime on this driver: its set_objects()
// places a virtual "map" object at /domains/std/map.lpc, which calls
// set_untouched_desc() -- a function that doesn't exist anywhere in this
// codebase (another instance of the same "swmud's own item/object API
// rewrite orphaned Lima's original demo content" pattern documented
// throughout NOTES.md, e.g. std/combat_spell.lpc, std/race/troll.lpc).
// Pointed at VOID_ROOM instead (a real, working room this archive DOES
// ship, /d/common/void.lpc) rather than at broken pre-existing demo
// content -- this is a deployment substitution, not a program fix, since
// the genuine Star Wars starting area (START/NEW_PLAYER_START below,
// "/d/coru/main") was never included in this archive at all; ordinary
// (non-wizard) players already fall through move_to_start()'s own
// fallback chain to this same VOID_ROOM for that reason. See NOTES.md.
// (VOID_ROOM's own macro isn't visible yet here -- config.h is included
// before mudlib.h defines it -- so its current value, "/d/common/void",
// is spelled out literally instead.)
#define WIZARD_START            "/d/common/void"

// Auto wiz means guest wizard only.  You still have to use the admtool command
// to make the person a full wizard w/ a directory
#undef AUTO_WIZ

// Wizard Positions are merely a descriptive field to describe what the wizard does
#define USE_WIZ_POSITION

// Allow wizards to see hidden exits?
#define WIZARDS_SEE_HIDDEN_EXITS


// Options affecting game news and logging

// Define this if you want bug, typo and idea commands to log to /log instead of posting news
#undef LOG_DONT_POST

// Define them if you want them to post news
#define BUG_NEWSGROUP "bug"
#define FEEDBACK_NEWSGROUP "feedback"
#define IDEA_NEWSGROUP "idea"
#define PRAISE_NEWSGROUP "praise"
#define QUESTION_NEWSGROUP "question"
#define TYPO_NEWSGROUP "typo"


// Other stuff

// The status of your game
#define lib_status()            "setup"

// What's the IP of your game?
#define __HOST__                "71.224.117.124"

// The administrator(s)' email address(es)
// NOTE: This is required to be changed in order to have a working I3 system
#define ADMIN_EMAIL             "starwarsmud@gmail.com"

// Anonymous ftp users are limited to /ftp/pub
#undef ALLOW_ANON_FTP

// Whether anon ftp users can *put* files.  Only works if ALLOW_ANON_FTP is defined
#undef ANON_CAN_PUT

// The following are to set directory names and short mudname used by the autodoc daemon.
// You will need to make a dir of MUD_AUTODOC_DIR in /help/autodoc
// if you plan to make use of this feature
#define AUTODOC_MUDNAME "lima"
#define MUD_AUTODOC_DIR "LIMA"

// Directory specifications

// Where do you want your wizard's shell files to save?
#ifdef HANDLE_MANY_WIZARDS
#define WSHELL_PATH(x)          sprintf("/data/wshells/%c/%s",x[0],x)
#else
#define WSHELL_PATH(x)          sprintf("/data/wshells/%s",x)
#endif

// Define the location of wizards home directories
#define WIZ_DIR                 "/wiz"

// Define this if you want expanded wizard directories (i.e. /wiz/f/foo)
#undef EXPANDED_WIZ_DIR

// Any files listed in this file will be loaded when the game starts
#define PRELOAD_FILE            "/data/config/preload"

// It's probably not a good idea to change these
#define LINK_PATH(x)            sprintf("/data/links/%c/%s",x[0],x)
#define USER_PATH(x)            sprintf("/data/players/%c/%s",x[0],x)
#define PSHELL_PATH(x)          sprintf("/data/pshells/%c/%s",x[0],x)

#endif __CONFIG_H__