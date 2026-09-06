// With this you can use standard "group npc" (npc that can belong to a
// group of npc fighting together) as your base monster. Just include this
// file with '#include "group_npc.h"'. Do _NOT_ inherit it directly;
// if you have to clone it, use constant GROUP_NPC_FILE defined in
// <npc_defs.h>.

#include "npc_defs.h"

inherit GROUP_NPC_FILE;
