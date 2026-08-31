//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void force(string who) { this_object()->force_me("kill "+who); }

void create() {
    ::create();
    set_name("bee");
    set_short("an angry bee");
    set_long("The bee has long,  red stripes on it.  It is buzzing around "
      "very ferouciously.");
    set_swarm(1);
    set_race("bee");
    set_body_type("insect");
    set_level(10);
    if(random(2))
	set_gender("male");
    else set_gender("female");
    set_id(({"bee", "angry bee"}));
}


