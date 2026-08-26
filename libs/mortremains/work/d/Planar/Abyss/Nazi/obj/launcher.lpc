/*
**File: launcher.c
**Date: Jan 21, 2000
**Purpose: To launch gas grenades to the enemies.
**Other Notes: NAZI hell layer...
**
** This is an example of a long comment.
*/

// This is an example of a short comment.

#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
    // Don't worry about this, just make sure its there.
    seteuid(getuid());

    // "author" should be set in all objects and rooms you code.
    // It should be a lowercase name - very simple.
    set("author", "nsd");

    // "name" makes it an axe, and not "0"
    set("name", "grenade launcher");

    // This makes it what it is, the other types can be found in
    // the dir /doc/properties
    set_weapon_type("gun/heavy");

    set("ammo_used", 2);

    // The "id" is all the things you can call it.
    set("id", ({ "launcher", "grenade launcher" }) );

    //short is what you see when it's on the floor or in an inventory
    // Make sure any "a" or "an" is lowercased!
    set("short", "a grenade launcher");

    //long is what ya get when a player examines it
set("long", "This launcher is made of steal.\n"+
"It loads with gas grenades that are dangerous.\n");

    set("damage", ({ 5, 10 }) );

    set("ammo_type", "gas grenade");

    set("damage_type", "poison");
    // another weapon wielded with it
set("nosecond", 1);

    //verbs are what you see when you attack. They are optional.
set_verbs( ({ "shoot at", "poison", "asphyxiate" }) );
    //verbs2 is what the other players in the room see
set_verbs2( ({ "shoots at", "poisons", "asphyxiates" }) );

    set("value", 1500);
 set("ammo", ([ "gas grenade" : 20 ]) );
}
