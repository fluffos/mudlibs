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
"norte", ({ -1, 0, 0 }), "sur", ({ 1, 0, 0 }), "este", ({ 0, -1, 0 }),\
"oeste", ({ 0, 1, 0 }), "arriba", ({ 0, 0, -1 }), "abajo", ({ 0, 0, 1 }),\
"noreste", ({ -1, -1, 0 }), "noroeste", ({ -1, 1, 0 }),\
"sudoeste", ({ 1, 1, 0 }), "sudeste", ({ 1, -1, 0 }), })
#define SHORTEN ([\
"norte":"n", "sur":"s", "oeste":"o", "este":"e", "noreste":"ne",\
"noroeste":"no", "sudeste":"se", "sudoeste":"so", "arriba":"ar",\
"abajo":"ab", "fuera":"fu", "dentro":"de"])
