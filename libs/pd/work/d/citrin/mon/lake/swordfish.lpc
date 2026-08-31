#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("sword fish");
    set_short("a sword fish");
    set_long("The sword fish looks pretty mean.  It has a sword "
      "for its nose.");
    if(random(2)) set_level(40); else
	set_level(50);
    if(random(2)) set_gender("male"); else
	set_gender("female");
    set_race("sword fish");
    set("aggressive",30);
    set_body_type("fish");
    set_id(({ "fish", "sword fish" }));
}


