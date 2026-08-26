// Header added by Mobydick@TMI-2, 8-24-93.
// This is a powered weapon, and has a limited charge. It can be turned
// on or off. When on, it's a pretty good weapon, and runs its charge down.
// When off, or out of power, it's a pretty lousy weapon. :)
// Cyanide modified to befit the current lib.
// Taken by rehnbi and modified into his own personal weapon at
// /u/r/rehnbi/items/sabre1.c


#include <mudlib.h>

inherit WEAPON ;

void create() {

set_bonus(9);
set("id", ({ "saber", "sabre", "lightsaber", "lightsabre", "light-saber", "light-sabre"}));
set("short", "Rehnbi's Light-Sabre");
set("long", @Fart
Rehnbi worked late at night designing the specs of this thing,
and now he will be pissed if it doesn't work.  It is a lightsabre
that has been modified to be very powerful.  
Fart
);
set_weapon_type("sword/short");
set("material_type", "Light");
    set ("value", "@@query_value");
set("value", "1000000000");
set("damage", ({8,7}));
set("prevent_drop", 1);
set ("name", "Rehnbi's Lightsabre");
set_verbs( ({ "attack", "slash at", "swing at", "charge at", "swipe at", "slice"}) );
}

