// This defs.h just points to the one in the BASE DIR, thus maintaining
// our precious portability.
#include "../defs.h"

#undef ROOMS
#define ROOMS(x) BASE + "catacombs/rooms/" + "x"
#undef MON
#define MON(x) BASE + "catacombs/mon/" + "x"
