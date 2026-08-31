//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("swamp dragon");
    set_long("The swamp dragon inhabits the swamp.");
    set_short("a swamp dragon");
    set_id(({"swamp dragon","dragon"}));
    set_race("swamp dragon");
    set_body_type("dragon");
    if(random(2))
	set_level(50);
    else set_level(60);
    if(random(2))
	set_gender("male");
    else set_gender("female");
    this_object()->add_money("gold", random(50));
}

