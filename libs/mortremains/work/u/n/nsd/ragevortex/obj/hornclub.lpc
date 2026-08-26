/*
** File: hornclub.c
** Author: Lady Nsd
** Purpose: Rage mentions in her minocow code that she has a club.
**          So I guess she needs one ;)
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "nsd");
    set("name", "hornclub");
    set_weapon_type("club");
    set_material_type("stone");
    set("id", ({ "club", "stone club" }) );
    set("short", "a hornclub");
    set("long", @EndText
This is a mystical club made of stone. It has the shape of
a giant minotaur horn, and it's pretty solid.
EndText);
    set_bonus(5,3,5);
    set("nosecond", 0);
    set_verbs( ({ "hit", "smash", "crush" }) );
    set_verbs2( ({ "hits", "smashes", "crushes" }) );
    set("value", 800);
}
