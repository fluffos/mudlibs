/*
** File: bat.c
** Other Notes: I like camels.
** Credits:
**    Created by Nightmask and shit.
**    8 Oct 97 Cyanide added the init/remove thing to clean up the mud!
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "nightmask");
    set("name", "bat");
    set_weapon_type("quarterstaff");
    set("size", 2);
    set("id", ({ "bat", "newbie_equipment", "cricket bat" }) ) ;
    set("short", "a generic baseball bat");
    set("long", @EndLong
A generic wooden baseball bat. The name "Alucard" is etched
into the handle.
EndLong
    );
    set("nosecond", 1);
    set_verbs( ({ "swing at", "try to thwap", "attack", "try to bash", "bat at" }));
    set_verbs2(({ "swings at", "tries to thwap", "attacks", "tries to bash",
      "bats at" })) ;
    set("value", 0);
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
