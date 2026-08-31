//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("slave bee");
    set_short("slave bee");
    set_long("This slave has been punished for a wrong doing and thus "
      "is now a slave to the queen.");
    if(random(2)) 
	set_level(30);
    else set_level(35);
    if(random(2)) 
	set_gender("male");
    else set_gender("female");
    set_race("bee");
    set_body_type("insect");
    set_id(({"slave", "slave bee", "bee"}));
}

