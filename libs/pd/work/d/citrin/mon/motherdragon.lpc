//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("mother dragon");
    set_long("The mother dragon protects its young.");
    set_swarm(1);
    set_short("mother dragon");
    set_id(({"mother dragon","dragon"}));
    set_race("dragon");
    set_body_type("dragon");
    if(random(2))
	set_subclass("red");
    else set_subclass("blue");
    set_class("dragon");
    if(random(2))
	set_level(40);
    else set_level(50);
    set_gender("female");
    set_emotes(5, ({"A large puff of smoke comes from the dragon's mouth."}), 0);
   this_object()->add_money("gold", random(150));
}

