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
    set("short", "shiny black boots");
    set("long", wrap("Shiny black boots with big gold buckles.") );
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
    if (environment(TO))
	tell_room(environment(this_object()), 
	  "The newbie item crumbles to dust and blows away.\n");
    ::remove();
}

