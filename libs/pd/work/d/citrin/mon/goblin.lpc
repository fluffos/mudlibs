//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("dark goblin");
    set_long("Almost nothing of the goblin can be seen.  "
      "It is wearing some type of light shielding making "
      "it appear almost invisible.");
    set("agressive", 25);
    set_short("dark goblin");
    set_id(({"goblin","dark goblin"}));
    set_race("goblin");
    set_body_type("goblin");
    if(random(2))
	set_level(70);
    else set_level(40);
    if(random(2))
	set_gender("male");
    else set_gender("female");
    this_object()->add_money("electrum", random(500));
}


