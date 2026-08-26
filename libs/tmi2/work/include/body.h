 
//  File  :  /include/body.h
//
//  The general user body defines (used by USER, GHOST, and MONSTER)
//  ----------------------------------------------------------------
 
//  Define DEBUG if you wish to get a debug output of various
//  user processes, particularily during setup()
 
//#define DEBUG
 
//  Define LOGOUT_MSG to be the message displayed to users as they
//  logout from the mud.

#define LOGOUT_MSG 	"See you again soon!\n"
 
//  Define IDLE_DUMP to equal the number of seconds a player 
//  may be idle before call_idle_dump() is initiated within the player.
 
#define IDLE_DUMP 	30 * 60

//  Define LINKDEAD_DUMP to equal the number of seconds a linkdead
//  statue can exist before it is removed.

#define LINKDEAD_DUMP 	30 * 60
 
//  Define AUTOSAVE to the number of seconds in the interval between
//  the auto save of character data.
 
#define AUTOSAVE 	10 * 60
 
//  Define GHOST_START_LOCATION to where you want the ghost of a player
//  to appear after their death.  Simply undefine it if you want it to
//  stay with the player's corpse.

#define GHOST_START_LOCATION	"/d/Fooland/cemetery"
 
 
//  Define BAD_FORCE_VERBS to be an array of verbs that you do not wish
//  called by the body.c's force_me() - command() combination.
 
#define BAD_FORCE_VERBS ({ "at",      "banish",    "call",   "changepath",  \
                           "clone",   "cp",        "demote", "dest",        \
                           "dewiz",   "eval",      "find",   "force",       \
                           "from",    "hibernate", "in",     "mail",        \
                           "makewiz", "master",    "mkdir",  "mv",          \
                           "nuke",    "passwd",    "pipe",   "rm",          \
                           "rmdir",   "shutdown",  "snoop",  "spew",        \
                           "sponsor", "student",   "su",     "to",          \
                           "times",   "trace",     "tsh",    "wall",        \
			})
 

// Define REAPPEAR_AT_QUIT if you want players to reappear at the place
// they were when they quit, next time they log in.

// #define REAPPEAR_AT_QUIT 1
 
 
// Define MESSAGE_BUFFER if you wish to allow users to store incoming messages
// in a buffer while they are busy (ie: writing a board/mail note)

#define MESSAGE_BUFFER

