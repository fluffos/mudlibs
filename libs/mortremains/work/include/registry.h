// This is all the stuff required for player registry. Very, very important.

// These are the BASE registered chars, in case of disaster.
#define BASE_REGISTERED = ([ "law@keeper.mudservices.com" : ({ "nightmask" }), \
	"ilzarion@erols.com" : ({ "ilzarion" }), \
	])

// Move this to logs.h?
#define REG_DUMP_LOG "/log/adm/registry_dump"
#define REG_LOG "adm/registry"


#define SAVE_PATH_MAIN "/adm/etc/"
#define SAVE_PATH_ATTIC SAVE_PATH_MAIN+"attic/"
#define SAVE_NAME "registry"

// This is the number of total characters one person can have.
// Wizards have one more; admin have 2 more.

#define MAX_CHARS 2

// Status levels

#define ERROR   -1
#define INACTIVE 0
#define ACTIVE   1

// Error messages

#define OKAY 0
#define NAME_IN_USE 1
#define TOO_MANY_NAMES 2
#define NO_SUCH_NAME 3
#define DAEMON_NOT_ACTIVE 4

