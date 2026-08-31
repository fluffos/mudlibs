//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("slimy rat");
    set_long("The entire length of the rats body is covered in slime.  "
      "A foul odor comes from it as you near him.");
    set("agressive", 25);
    set_short("slimy rat");
    set_id(({"rat","rat"}));
    set_race("rat");
    set_body_type("rat");
    if(random(2))
	set_level(50);
    else set_level(40);
    if(random(2))
	set_gender("male");
    else set_gender("female");
    this_object()->add_money("electrum", 500);
}

