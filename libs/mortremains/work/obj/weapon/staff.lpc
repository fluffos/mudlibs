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
	set("short", "an oak staff");
	set("long", "A quarterstaff made of wood.\n");
	set_weapon_type("quarterstaff");
	set ("name", "staff");
	set_verbs( ({ "pound on", "crush", "beat" }) );
set("nosecond", 1);
}
