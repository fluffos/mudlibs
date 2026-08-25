/* FluffOS PORT NOTE: this directory's files #include "path.h" but no such
 * file shipped here (every other d/newbie/grads/* subdirectory has one) --
 * "Cannot #include path.h". Added, mirroring the sibling
 * d/newbie/grads/rooms/path.h content this zone already uses elsewhere. */
#define ROOM "/d/newbie/grads/rooms/"
#define CAVE1 "/d/newbie/grads/rooms/cave1"
#define VALLEY "/d/newbie/grads/rooms/valley/"
#define WEAPON "/d/newbie/drow/weapons/"
#define ARMOUR "/d/newbie/drow/armour/"
#define CHAR "/d/newbie/grads/npcs/"
/* wizard.lpc clones OBJ+"fr_arrow_learnable.lpc", which doesn't actually
 * exist anywhere in this archive (missing content, not this port's doing)
 * -- OBJ itself still needs SOME definition to compile; pointed at this
 * zone's own (currently nonexistent) obj/ dir per the convention other
 * zones' path.h files use, so the clone simply fails gracefully at
 * runtime exactly as it would have upstream with lost content. */
#define OBJ "/d/newbie/grads/obj/"
