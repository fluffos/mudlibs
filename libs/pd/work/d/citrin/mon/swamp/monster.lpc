//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("swamp monster");
    set_long("The swamp monster inhabits the swamp.");
    set_short("a swamp monster");
    set_id(({"swamp monster","monster"}));
    set_race("swamp monster");
    set_body_type("squid");
    if(random(2))
	set_level(50);
    else set_level(60);
    if(random(2))
	set_gender("male");
    else set_gender("female");
   this_object()->add_money("gold", 50);
}


