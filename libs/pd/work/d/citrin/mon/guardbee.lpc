//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void force(string who) { this_object()->force_me("kill "+who); }

void create() {
    ::create();
    set_name("guardian bee");
    set_short("guardian bee");
    set_long("This bee seems to be one of the many that protect the "
      "queen.  Its tail has a long,  sharp looking stinger on it.");
    set_race("bee");
    set_swarm(1);
    set_body_type("insect");
    set_level(30);
    if(random(2)) 
	set_gender("male");
    else set_gender("female");
    set_id(({ "guardian bee", "bee" }));
}


