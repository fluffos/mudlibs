//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("guardian");
    set_long("This guardian is one of "
      "the many guardians of the forest.");
    set("agressive", 25);
    set_heart_beat(1);
    set_speed(4);
    set_short("forest guardian");
    set_moving(1);
    set_id(({"goblin","dark goblin"}));
    set_race("goblin");
    set_invis();
    set_body_type("goblin");
    set_swarm(1);
    if(random(2))
	set_level(70);
    else set_level(70);
    if(random(2))
	set_gender("male");
    else set_gender("female");
}
void die() {
    this_object()->force_me("say You will not get away with this that easily!");
    ::die();
}

