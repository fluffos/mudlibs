/*
**  File: boots.c
**  Purpose: You figure it out, duh...
**  Yet another random note: Bite me.
**  Credits: Nightmask the Fresh Breaker.
**    8 Oct 97 Cyanide added the init/remove thing to clean up the mud!
*/

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;
void create() {
    seteuid(getuid());
    set("short", "combat boots");
    set("long", @EndText
Black military surplus combat boots.
EndText
    );
    set("id", ({ "boots", "newbie_equipment" }) ) ;
    set_armor_type("boots");
    set("value", 0);
    set("size", -1);
}

void init() {
    if (!living(environment(this_object())))
	call_out("remove", 1);
}

void remove() {
    if (environment())
	tell_room(environment(this_object()), 
	  "The newbie item crumbles to dust and blows away.\n");
    ::remove();
}

