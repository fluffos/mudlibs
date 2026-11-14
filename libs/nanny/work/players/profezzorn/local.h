/*********************************************************************\
* All configuration to  the  shell should be possible to make in this *
* file. If this is not possible then please report this to me so that *
* I can make it possible to put all configurations here.  Besides, It *
* will make  it easier for  you when  you import  next version of the *
* shell.                               Profezzorn.                    *
\*********************************************************************/

/*
 *  Driver-specific configuration
 */

/* Define this to 1 if you mud run native-mode */
#define NATIVE 0

/* This should be 0 if you don't have mappings in your driver */
#define mappings 1

/* Are you mappings really alists? */
#define dworkins_mappings 1

/* does your driver have alists? */
#define alists 1

/* wouldn't it be simple to just include config.h from the driver?
 * If you have this, it should be defined to the type that RUSAGE
 * returns. supported types are: T_STRING, T_MAPPING, T_MIXED or
 * T_POINTER
 */
#define RUSAGE T_MIXED

/* What is your query_actions() called (if you have one...)*/
#define my_query_actions _query_action

/* How to find the next clone with the same program. */
#define NEXT_CLONE(X) _next_clone(X)

/* How to find all clones of a given master */
/* #define CHILDREN(X) children(X) */

/* Do you have an efun that tells you how much cpu an object has used? */
#define OBJECT_CPU(X) _object_cpu(X)

/* Do you have an efun that tells you when an object was created? ? */
#define OBJECT_CREATED(X) (_object_stat(X)[0])

/* Do you have an efun that tells you how much memory an object has used? */
#define OBJECT_MEMORY(X) _object_memory(X)

/* Do you have a way to find the datestamp of a file?
 * note that it must be the modificaton date, not creation date.
 */
#define FILE_DATE(X) (_file_stat(X)[3])

/* Does your mud have an identd? If so, this marco should
 * return the username of the player using that object.
 */
#define IDENT(X) _query_ident(X)

/* How do we find out who is REALLY buggin us? */
#define this_interactive() this_player(1)

/* does you mud have a replace efun? mine has (now) */
/* #define replace(X,Y,Z) implode(my_explode(X,Y),Z) */

/* Does YOUR save object fix backslash in strings in arrays if so,
 * define this (if you're not sure, don't)
 */
#define PERFECT_SAVE_OBJECT

/* does your driver have a silly explode?
 * if sizeof(explode("ac","c"))==2 then you should define this:
 */
/* #define PERFECT_EXPLODE */

/* do YOU have trace() and traceprefix() ? */
/* #define TRACE */



/*
 *  Mudlib-specific configuration
 */

/* These are used when local patches are nessesary */
#define NANNY 1
#define DISCWORLD 0
#define AA 0
#define TUBMUD 0
#define SHADOWRUN 0
#define KINGDOMS 0
#define PANDORA 0
#define RIFTS 0

/* Does the shell have to inherit something? */
/* #define STD_OBJECT "std/object" */

/* This is the function that _always_ squeezes out the real name from the
 * playerobject!
 */
#define REAL_NAME_FUNC "query_real_name"

/* do we call a remove() or somthing instead of destructing?  */
/* #define REMOVE_FUNC remove */
/* #define REMOVE_FUNC_NAME "remove" */

/* This is how the shell recogize a wizard */
#define WIZARD_P(X) ((X)->query_level() > 20)

/* how do we make the_bearer() do something? */
#define INTERNAL_COMMAND(X) command(X,the_bearer())

/* Where are everybody else? */
#define WIZDIR "players"
#define OPENDIR "open"
#define MONSTERFILE "obj/monster"
#define TREASUREFILE "obj/treasure"
#define WEAPONFILE "obj/weapon"
#define ARMOURFILE "obj/armour"
#define DRINKFILE "obj/drink"
#define FOODFILE "obj/food"
#define VOID "room/room"
#define ERRORLOG ("/log/"+bearer)
#define MASTER "/obj/master"
#define OBJ_DUMP "/syslog/OBJ_DUMP"
#define DEBUG_LOG ("/syslog/"+query_host_name()+".debug.log")
#define LPMUD_LOG ("/lpmud.log")
/* Just comment this out if shout curse isn't an object */
#define SHOUTCURSE "obj/shout_curse"

/* Just check that this isn't too small */
#define MAX_USERS 80

/* If you define alt_name, then the shell will try to give shells from
 * that filename to people other than the person who has the files.
 * A good way of doing it is putting a file in /obj/ or /local/ that
 * inherits the shell itself and then defining alt_name to that file.
 * Note that the filename should start with a leading slash.
 * The NO_ALT_SHELL(X) is a test that should return 1 for people who
 * shouldn't have a shell from alt_name, but can clone any shell they
 * please, typial such people are: arches, quality chekers, your friends
 * or whatever is aproperiate. NO_ALT_SHELL must be defined if alt_name
 * is.
 */
#define alt_name "/std/tools/brainloader"
#define NO_ALT_SHELL(X) ((string)(X)->query_real_name()=="albert")


/*
 *  Our own paths
 */

/* Where the shell is located */
#define BRAINFILE "/players/profezzorn/brain"

/* Where my library is located */
#define BRAINLIB "/players/profezzorn/brainlibrary"

/* Where do we save people? */
/* don't define to use query_auto_load() */
/* use leading / ONLY in native mode */
#define BRAINSAVE "players/profezzorn/brainsave/"

/* If we save in a special dir we need a database object.. */
#define BRAINBASE "/players/profezzorn/brainbase"

/* Where does 'id' get it's functions from? */
#define BRAINQUERYLIST "/players/profezzorn/brain_query_list"

/* Undefine this if you can't shadow player.c */
#define BRAINSHADOW "/local/brain_page_shadow"

/* define where userdata should be saved. */
#define USERDATA "brain.userdata"

/* This is the path to the object all modules should inherit */
#define MODULE "/players/profezzorn/module"

/* Undefine what you do not wish to log */
#define PATCHLOG "/players/profezzorn/brainlog"
#define EVALLOG "/players/profezzorn/brainlog"
#define ECHOLOG "/players/profezzorn/brainlog"
#define UNDOLOG "/players/profezzorn/brainlog"
#define CLONELOG "/players/profezzorn/brainlog"
#define RMLOG "/players/profezzorn/brainlog"
#define MOVELOG "/players/profezzorn/brainlog"

/*
 *  Options
 */

/* Do you want to use profiling? (check it out with PROFILE) */
/* uses some cpu, it's not for permanent use. */
#define PROF 0

/* Define some maximums */
#define MAX_ALIASES 100
#define MAX_NICKNAMES 50

/* Never define this to anything but a constant */
#define HISTORY_SIZE 21

/* Does your mud accept that a player got both a shell and a quicktyper? */
/* Watch those double negations :) */
#define NO_QUICKTYPER 0

/* Do we want theese commands or are they too good for your arches? */
#define AUTO
#define WALK
#define PEOP
#define SCAN
#define ECHO
#define BUGD /* bug-daemon */
#define TIME 1 /* should be the timezone or undefined */

/* Give these modules to wizards by default */
#define DEFAULT_WIZMODULES ({"/players/profezzorn/default_module"})

/* how many files should the shell use to save in ? */
/* 0 means one file / player */
#define HASHSIZE 0

