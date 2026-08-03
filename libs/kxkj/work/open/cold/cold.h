// cold.h -- reconstructed. Missing from the raw archive entirely (not
// present under any name/casing in raw/ either); every /open/cold/*.lpc
// file in this zone references COLD_ROOM/COLD_NPC via #include "../cold.h"
// but the header itself was never shipped. Rebuilt using the exact
// per-zone macro-naming convention already established by the sibling
// /open/open.h file (XXX_ROOM/XXX_NPC/XXX_OBJ per zone) -- only the two
// macros actually referenced anywhere in open/cold/*.lpc are defined here
// (grepped for \bCOLD[A-Z_]*\b across the zone; no COLD_OBJ use found, and
// no obj/ subdirectory exists under open/cold/ either, so it's omitted
// rather than guessed).
#define COLD_ROOM	"/open/cold/"
#define COLD_NPC	"/open/cold/npc/"
