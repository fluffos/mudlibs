/* File: armour.c 
**  Purpose: You figure it out, duh...
**  Date: July 30th, 1997
**  Yet another random note: Bite me.
**  Credits: Nightmask the Fresh Breaker.
**    8 Oct 97 Cyanide added the init/remove thing to clean up the mud!
**   18 Sep 99 Cyanide made it into a thick coat.
*/

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;

void create() {
    set("short", "a long black trenchcoat");
    set("long", @EndText
A heavy woolen crenchcoat.
It will protect you against minor attacks.
EndText
    );
    set("id", ({ "newbie_equipment", "armour", "armor", "coat",
      "trenchcoat" }) );
    set_armor_type("leather");
    set("size", -1);
    set("value", 0);
}

void init() {
    object env = environment(this_object());

    if (env && !living(env))
	call_out("remove", 1);
}

void remove() {
    object env = environment(this_object());

    if (env) tell_room(env,
	  "The newbie item crumbles to dust and blows away.\n");
    ::remove();
}
