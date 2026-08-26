// dagger.c
// An example weapon. It is an acceptable second weapon, so it sets its
// "second" property to 1. For full comments on weapon properties, see
// sword.c which should be in the same directory as this file.
// Cyanide soft-coded second weapons, so we don't use the "second"
// property.  This version is compatible with the new lib.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set("id", ({ "staff", "quarterstaff" }) );
	set("short", "a magic staff");
	set("long", "A magical quarterstaff.\n");
	set_weapon_type("quarterstaff");
	set_bonus(3);
	set ("name", "magic staff");
	set_verbs( ({ "pound on", "crush", "beat" }) );
set("nosecond", 1);
set("value", 1400);
}
