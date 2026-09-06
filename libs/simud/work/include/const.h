/* This file contains constants that can be adjusted to modify the world.
 */

#ifndef _CONST_H_
#define _CONST_H_

#include "/include/sys/files.h"
#include "/include/const/battconst.h"
#include "/include/const/classification.h"
#include "/include/const/varconst.h"


// Stuff that you should be careful modifying
#define NUM_TITLES    4
#define VERSION       "SIMud v0.9.6"
#define MUD_TITLE     "Walraven"
#define PASSWD_LEN    6

#define SERVER_NAME   "Tiffany"

#ifdef __TLS__
#define SSL_PORT 2424
#endif

// Note that all constants ending in _DIR *MUST* have a "/"
// the end, or they will not work!

// Stuff that would wreak havoc if you modify it (be careful)
#define PLAYER_DIR    "/players/"
#define TEXT_DIR      "/text/"
#define HELP_DIR      "/help/"
#define LOG_DIR       "/log/"
#define HOME_DIR      "/home/"
#define DOC_DIR       "/doc/"
#define EXITS_DIR     "/world/exits/"
#define AI_DIR        "/ai/"
// The rm command on the MUD will move rm'd files to this
// directory, which allows for undelete capabilities.
// If this constant is set to 0, rm will work by simply
// deleting the files.
#define RM_DIR        "/.rm/"
// security levels
#define WIZLEVEL      100
#define WIZ2LEVEL     500
#define ADMLEVEL      1000
#define PLAYER_OBJ    "/obj/player"
// The max string size I believe
#define MAX_READ_SIZE 50000
#define ENTRY_LOG     "entrylog"
#define EXIT_LOG      "exitlog"
#define ERRORS_LOG    "errors"
#define MASTER_UID    "root"
#define FLEX_UID      "flex"
// Fully qualified filenames for common daemons.
#define WALK_DAEMON   "/daemon/walk"
#define RECIPE_DAEMON "/daemon/recipe.lpc"
#define AUDIO_DAEMON  "/daemon/audio"
#define PARTY_DAEMON  "/daemon/party"
// If a player's environment gets dested, where to send them?
#define DEST_PLACE    ";wizarea;reception"
// How many commands to remember for command history
#define COMMAND_HISTORY_SIZE 10
// #define WORLD_SAVE_TIME 1800   // 30 minutes
// #define WORLD_SAVE_TIME 3180   // 53 minutes
#define WORLD_SAVE_TIME 10740   // 179 minutes
// The prepositions which objects may use as standard
#define STD_PREPOSITIONS ({ "at", "on", "under", "in", "inside", "behind" })
// These give the size of 'overworld' style rooms, in cells.
// Only change these before you have maps you care about, because
// it shuffles the rooms around dreadfully.
#define OVERWORLD_WIDTH 10
#define OVERWORLD_HEIGHT 6
#define MAX_ACTIONS_PER_HEARTBEAT 5
// Objects 'decay' values must reach this before disintegrating. Lower values
// = faster decay. Faster decay is one way to cope with object bloat.
#define MAX_DECAY 10000

// Maximum delay after a buffered message is sent until it is received.
#define BUFFER_MSG_DELAY  2
// Amount of time that a 'doing' message sticks.
#define DOING_DELAY       20

// input_to -- useful constants
#define INPUT_NOECHO      1
#define INPUT_CHARMODE    2
#define INPUT_IGNORE_BANG 128

// pad -- Justifiction constants
#define JUST_LEFT   0
#define JUST_RIGHT  1
#define JUST_CENTER 2

#define PREP_EXP "\\bon top of\\b|\\bon\\b|\\bunder\\b|\\bunderneath\\b|\\bin\\b|\\binside of\\b|\\binside\\b|\\bbehind\\b|\\binto\\b"

#define WIZ_CHECK if(this_player()->query_level()<WIZLEVEL){notify_fail("==> [Error] Access Denied\n");return 0;}
#define BUILD_CHECK if(this_player()->query_level()<WIZLEVEL && !this_player()->query_env_var("builder")){notify_fail("==> [Error] Access Denied\n");return 0;}
#define ADM_CHECK if(this_player()->query_level()<ADMLEVEL){notify_fail("==> [Error] Access Denied\n");return 0;}

#define WALK_ACTION( readiness, target ) WALK_DAEMON->init_walk_action( target->query_border()?target->query_border():WALK_DAEMON->shape_adjacent(), target->query_coord(), ({ readiness, this_object(), target, ST_STANDING, 0 }) )
#define WALK_ACTION_PARAM( readiness, target, param ) WALK_DAEMON->init_walk_action( target->query_border()?target->query_border():WALK_DAEMON->shape_adjacent(), target->query_coord(), ({ readiness, this_object(), target, ST_STANDING, param }) )

#define NUMBERS_MAP ([ "one": 1, "two": 2, "three": 3, "four": 4, "five": 5, \
   "six": 6, "seven": 7, "eight": 8, "nine": 9, "ten": 10, \
   "eleven": 11, "twelve": 12, "thirteen": 13, "fourteen": 14, \
   "fifteen": 15, "sixteen": 16, "seventeen": 17, "eighteen": 18, \
   "nineteen": 19, "twenty": 20, "first": -1, "second": -2, \
   "third": -3, "fourth": -4, "fifth": -5, "sixth": -6, \
   "seventh": -7, "eighth": -8, "ninth": -9, "tenth": -10, \
   "eleventh": -11, "twelfth": -12, "thirteenth": -13, \
   "fourteenth": -14, "fifteenth": -15, "sixteenth": -16, \
   "seventeenth": -17, "eighteenth": -18, "nineteenth": -19, \
   "twentieth": -20, "both": 2, "zero": 0, "no": 0])

#define NUMBER_WORDS_MAP ([ 1: "one", 2: "two", 3: "three", 4: "four", \
   5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine", 10: "ten", \
   11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen", \
   15: "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen", \
   19: "nineteen", 20: "twenty", -1: "first", -2: "second", -3: "third", \
   -4: "fourth", -5: "fifth", -6: "sixth", -7: "seventh", -8: "eighth", \
   -9: "ninth", -10: "tenth", -11: "eleventh", -12: "twelfth", \
   -13: "thirteenth", -14: "fourteenth", -15: "fifteenth", -16: "sixteenth", \
   -17: "seventeenth", -18: "eighteenth", -19: "nineteenth", \
   -20: "twentieth", 0: "zero" ])

#include "const/raceconst.h"

// These flags are used for get, drop, put, give, etc.
// They are passed back by on_get, on_drop, etc. to specify what happened.

// There is a *reason* this is commented out. If your code is using
// MOVE_FAIL_FLAG, your *code* is broken, not this file. Return 0 if
// there is a problem with movement, it'll avoid a LOT of confusion.
//#define MOVE_FAIL_FLAG 0x0

// If OR'ing by this flag is true, then the move succeeded (object is allowed to move).
#define MOVE_OK_FLAG 0x1

// If OR'ing by this flag is true, then do not print a message.
#define MOVE_SILENCE_FLAG  0x2

// Maximum amount of says to be saved in the player's sayhist
#define MAX_SAY_HISTORY    15

// Maximum amount of tells to be saved in the player's tellhist
#define MAX_TELL_HISTORY   15

#define ICON( sym, color, height ) \
void on_paint( object painter ) { \
   painter->paint( query_x(), query_y(), sym, color, height ); \
}

// Macro to query metal type for current object
#define METAL_TYPE "/daemon/material"->get_metal_type(query_aspects())
#define A_METAL_TYPE "/daemon/material"->get_a_metal_type(query_aspects())

// Call a function either in a mirror object or this object, depending on context.
#define MCALL(f) (previous_object() && previous_object()->query_is_mirror()?previous_object()->f:f)
// Either the mirror object or this one, depending on who received the call.
#define MOBJ (previous_object() && previous_object()->query_is_mirror()?previous_object():this_object())

// Coordinates are stored as integers. Any coordinate value can be interpreted as signed or unsigned,
// depending on context. The method for making the signed version is a simple range shift ... unsigned
// 0 corresponds to signed -4096. This is slightly awkward, in that you must know which representation
// you are using, but is how it worked out :-P.

#define CX(c) ((c)&0x1FFF)
#define CY(c) (((c)>>13)&0x1FFF)
#define CZ(c) (((c)>>26)&0x3F)
#define SCX(c) (((c)&0x1FFF)-4096)
#define SCY(c) ((((c)>>13)&0x1FFF)-4096)
#define SCZ(c) ((((c)>>26)&0x3F)-32)
// Coordinates are numbered 0..8191 on x, y, and 0..63 on z,
// Signed coordinates are -4096..4095 on x & y, and -32..31 on z.
// The two types are not directly interchangable; you have to know
// which type is being used for each function that takes coordinates.
// In general, offsets and shapes use signed coords, and absolute
// positions on a map use unsigned.
#define MAKE_C(x,y,z) (((x)&0x1FFF)|(((y)&0x1FFF)<<13)|(((z)&0x3f)<<26))
// This is the 'signed' version of coordinates. Coordinates are -4096..4095 on x,y and -32..31 on z.
#define SMAKE_C(x,y,z) (((x+4096)&0x1FFF)|(((y+4096)&0x1FFF)<<13)|(((z+32)&0x3f)<<26))
// Invert (negate) a signed coordinate: (10,11,-4)->(-10,-11,4)
#define SINVERT_C(c) SMAKE_C(4096-CX(c), 4096-CY(c), 32-CZ(c))
#define MAKE_CSTR(c) ("(" + CX(c) + ", " + CY(c) + ", " + CZ(c) + ")")
#define SMAKE_CSTR(c) ("(" + SCX(c) + ", " + SCY(c) + ", " + SCZ(c) + ")")
// c is a signed or unsigned coordinate; delta is a signed coordinate.
// Adds delta to c. Overflow ought to wrap in fairly predictable fashion.
#define OFFSET_C(c, delta) MAKE_C(CX(c)+CX(delta)-4096, CY(c)+CY(delta)-4096, CZ(c)+CZ(delta)-32)

// Layers, with attendant values. Update the FLOOR_CHARS mapping if you change them.
// 0: Can walk over, Normal cost
#define LAYER_TERRAIN   0
// 1: Terrain/ground ... I'm using this for shallow water.
#define LAYER_GROUND    1
// 2: Can walk over. Lowest cost.
#define LAYER_ROAD      2
// 4: Can walk over, higher terrain cost (potentially)
#define LAYER_ROUGH     4
// 6: Can't walk over. Might be able to climb over.
#define LAYER_FENCES    6
#define LAYER_FURNITURE 6
// 7: Cannot walk over. Can sail or fly over (boats).
#define LAYER_WATER     7
// 8: Bridges over water. Can walk and fly over.
#define LAYER_BRIDGE    8
// 9: Items. Sits on top of water, bridges, and most landscaping.
#define LAYER_ITEMS     9
// 10: Cannot walk over. Can fly over (high walls).
#define LAYER_WALL      10
// 11: Same as layer wall, except that mountains may be excavated (mined), walls may not.
#define LAYER_MOUNTAIN   11
// 12: Drawn on top of just about everything. Currently set to be walk-overable, for various reasons.
#define LAYER_LIVING    12
// 16: Overlays (players walk UNDER them)
#define LAYER_OVERLAY   16
// 17: Solid overlays (bugfix for overlay "bridging")
#define LAYER_OVERLAY_S   17
// 18: Totally impassable (room boundaries)
#define LAYER_INVALID   18

// A mapping of walk-on-able characters for path-finding.
// Note that I'm currently ignoring cost, because ...
// well, it turns out that actually paying too much
// attention to cost really messes up the run time.
// Can't win. The '@' is for overlays, which you can walk 'under'.
// The '<' is for living things (LAYER_LIVING).
#define FLOOR_CHARS ([ '0':1, '1':1, '2':1, '4':1, '8': 1, '9': 1, '<': 1, '@':1 ])

#define DEP(oldf, newf) debug( oldf + " is deprecated, use " + newf + " this_object="+as_string(this_object())+", previous_object()="+as_string(previous_object())+", this_player="+as_string(this_player())+", verb="+query_verb() )

#define QBODY( var, val ) if( this_object()->query_has_var(var) ) return this_object()->query_var(var); else return val;
#define SBODY( var, x ) this_object()->set_var( var, x );

// The length of a game day, in RL seconds.
// 2880 = 48 minutes, or 30 days per real day.
#define DAY_LENGTH 2880

// In days
#define YEAR_LENGTH 365

// quest constants
#define QUEST_UNSTARTED 0
#define QUEST_STARTED   1
#define QUEST_FINISHED  2

// for descriptions
#define HAIR_COLOR   0
#define HAIR_STYLE   1
#define HAIR_LENGTH   2

#define EYE_COLOR   0
#define EYE_ADJ      1
#define EYE_COUNT   2

#define SKIN_COLOR   0
#define SKIN_ADJ   1

#define ADJ_PRIMARY   0
#define ADJ_SECONDARY   1

#define NEUTER 0
#define MALE 1
#define FEMALE 2

#endif
