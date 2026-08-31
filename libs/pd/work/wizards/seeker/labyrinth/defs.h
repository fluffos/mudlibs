// *** Directory Pathnames ***
#define LABYRINTH "/wizards/seeker/labyrinth/"
#define MONS_DIR LABYRINTH+"mons/"
#define OBJ_DIR LABYRINTH+"obj/"
#define ROOM_DIR LABYRINTH+"room/"
#define WANDERING_MONS MONS_DIR+"wandering_mons/"
#define ENTRANCES ROOM_DIR+"entrances/"
#define UNIQUES ROOM_DIR+"uniques/"

// *** File Pathnames ***
#define LABRYS LABYRINTH+"labrys"
#define DATA LABYRINTH+"data"
#define BASE_ROOM ROOM_DIR+"base_room"
#define BASE_MONSTER MONS_DIR+"base_monster"
#define BASE_OBJECT OBJ_DIR+"base_object"
#define BASE_WEAPON OBJ_DIR+"base_weapon"
#define BASE_ARMOUR OBJ_DIR+"base_armour"
#define LABRYS_MASTER LABYRINTH+"master_daemon"
#define LABRYS_STORAGE LABYRINTH+"storage_daemon"
#define ITEM_DAEMON ROOM_DIR+"item_daemon"
#define NUMBER_DAEMON LABYRINTH+"number_daemon"
#define WANDERER_DAEMON MONS_DIR+"wanderer_daemon"
#define CLEANUP_DAEMON LABYRINTH+"cleanup_daemon"
#define DARK_CHAMBER LABYRINTH+"dark_chamber"
#define WANDERER MONS_DIR+"wanderer"
#define GUARDIAN MONS_DIR+"guardian"
#define ROOM_TEMPLATE LABYRINTH+"room.template"

// *** Labyrinth Specs ***
#define CONTENTS 1
#define FULL_ITEMS 1
#define DIMENSION 10

// *** Miscellaneous ***
#define DMODS (["north":({1,0,0}),"northeast":({1,1,0}),"east":({0,1,0}),"southeast":({-1,1,0}),"south":({-1,0,0}),"southwest":({-1,-1,0}),"west":({0,-1,0}),"northwest":({1,-1,0}),"up":({0,0,1}),"down":({0,0,-1})])
#define EXIT_ARR ({ "north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest","up","down" })
#define OPPOSITE_EXITS ([ "north" : "south", "south" : "north", "east" : "west", "west" : "east", "up" : "down", "down" : "up", "northeast" : "southwest", "southwest" : "northeast", "northwest" : "southeast","southeast" : "northwest" ])


