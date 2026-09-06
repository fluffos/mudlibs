// With this you can use standard "equipped group npc" (npc that is equipped
// with weapon(s)/armour(s)/other item(s), and can belong to a group of npcs
// fighting together) as your base monster. Just include this file with
//  '#include "equipped_group_npc.h"'. Do _NOT_ inherit it directly;
// if you have to clone it, use constant EQUIPPED_GROUP_NPC_FILE defined in
// <npc_defs.h>.

#include "npc_defs.h"

inherit EQUIPPED_GROUP_NPC_FILE;
