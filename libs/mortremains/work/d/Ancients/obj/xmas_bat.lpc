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
    set("author", "Nightmask the fresh maker");
    set("name", "candy cane");
    set_weapon_type("quarterstaff");
    set("damage", ({ 1,4 }) );
    set("size", 2);
    set("id", ({ "newbie_equipment", "cane", "candy cane" }) );
    set("short", "a giant candy cane");
    set("long", wrap("This is a great big candy cane given "+
	"to you by Alucard Claus. You could probably 'wield' it "+
	"as a weapon.") );
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
