/*
** FILE: obsword.c
** PURPOSE: Example of set_bonus() function.
** CREATOR: Cyanide@Nightfall's Keep
** CHANGES:
**    9 Apr 97    Cyanide    Created the file.
**   18 Jun 97    Cyanide    Updated the weapon to include the new
**                           set_weapon_type function.
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
    set_bonus(4);
    set_weapon_type("sword/long");
    set("value",   2100);
    set("id", ({ "planesword", "sword" }) );
    set("short", "sword of the planes");
    set("long", @LONG
This is a finely crafted planar sword.
LONG
    );
    set("name", "sword of the planes");
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("dest_at_sell", 1);
}
