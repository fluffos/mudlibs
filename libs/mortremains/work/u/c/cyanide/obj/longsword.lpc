/*
** PURPOSE: Example of set_weapon() function.
** CREATOR: Cyanide@?Mud
** CHANGES:
**    9 Apr 97    Cyanide    Created the file.
*/

#include "/u/c/cyanide/debug.h"
#include <mudlib.h>

inherit WEAPON;

void create() {
    set("id", ({"longsword", "sword" }));
    set("short", "a longsword");
    set_weapon_type("sword/long"); 
    set_material_type("metal/green steel");
    set ("name", "sword");
    set_verbs(({ "slash", "stab", "cut" }));
}
void heart_beat() {
    DEBUG("Sword HB\n");
}

/* EOF */
