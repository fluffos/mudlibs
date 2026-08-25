#define ROOM_DEST 0
#define ROOM_MESS 1
#define ROOM_OBV  2
#define ROOM_SIZE 3
#define ROOM_FUNC 4
#define ROOM_ENTER 5
#define ITEM_OBJECT "/std/room/item"
#define DOOR_OBJECT "/std/room/door"
/* Only move one room a round.  Hmm.... Make it two */
#define EXIT_TIME 10
#define ROOM_HAND "/obj/handlers/room_handler"
#define LOCK_HAND "/obj/handlers/lock_handler"
#define EXIT_HAND "/std/room/exit_handler"
#define DIG_HAND "/std/room/dig_handler"
#define STD_ORDERS ({\
"north", ({ -1, 0, 0 }), "south", ({ 1, 0, 0 }), "east", ({ 0, -1, 0 }),\
"west", ({ 0, 1, 0 }), "up", ({ 0, 0, -1 }), "down", ({ 0, 0, 1 }),\
"northeast", ({ -1, -1, 0 }), "northwest", ({ -1, 1, 0 }),\
"southwest", ({ 1, 1, 0 }), "southeast", ({ 1, -1, 0 }), })
#define SHORTEN ([\
"north":"n", "south":"s", "west":"w", "east":"e", "northeast":"ne",\
"northwest":"nw", "southeast":"se", "southwest":"sw", "up":"u",\
"down":"d" ])
 
