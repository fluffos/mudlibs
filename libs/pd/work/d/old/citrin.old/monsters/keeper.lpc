// Coded by Whit
// Coded for Primal Darkness
// keeper.c

#include <std.h>
#include <citrin.h>
inherit MONSTER;

void create() {
::create();
    set_name("keeper");
    set_short("the keeper of the forest is here.");
    set_long("This is the keeper of the forest.  He is dressed in a light "
	     "green shirt and is very happy going about his work.");
    set_id(({"gnome", "explorer"}));
    set_level(10);
    set_race("gnome");
    set_body_type("human");
    set_gender("male");
    set_patrol(4, 
	({"west", "west", "north", "east", "east", "south",}) 
    );    
    set_languages( ({"Giarrok"}) );
    set_speech(5, "Giarrok", 
	({"How dare you attack me in my own forest."}),
	1);
 }
