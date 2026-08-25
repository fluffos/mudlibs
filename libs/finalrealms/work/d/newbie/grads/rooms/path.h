/* FluffOS PORT NOTE: ROOM was missing from this header (every sibling
 * newbie-zone path.h in this codebase defines it, e.g. d/newbie/elf/
 * rooms/path.h) -- add_exit(...) calls throughout this zone's rooms use
 * ROOM+"file.lpc" and hard-errored with "Undefined variable 'ROOM'"
 * without it. Added to match the zone's own room directory. */
#define ROOM "/d/newbie/grads/rooms/"
#define CAVE1 "/d/newbie/grads/rooms/cave1"
#define VALLEY "/d/newbie/grads/rooms/valley/"
#define WEAPON "/d/newbie/drow/weapons/"
#define ARMOUR "/d/newbie/drow/armour/"
#define CHAR "/d/newbie/grads/npcs/"
