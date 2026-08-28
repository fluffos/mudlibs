#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("will-o-wisp");
    set_id( ({ "wisp", "will-o-wisp" }) );
    set("race","wisp");
    set_short("A Will-o-Wisp floats about");
    set("aggressive", 1);
    set_speed(60);
    set_moving(1);
    set_level(10);
    set_stats("intelligence", 100);
    set_property("melee damage", ([ "cold" : 40 ]));
    set("race", "wisp");
    set("long", "The Will-o-Wisp takes the form of a bright sphere dancing about in the "+
	"air.");
    set_body_type("sphere");

    set_property("physical resistance", ([ "iron" : 35, "default" : 35,
					  "wood" : 35, "steel" : 35 ]));
    set_property("magic resistance", 30);
    set_max_hp(570);
    set_hp(570);
    set_wimpy(10);
    set_emotes(10, ({ "The wisp floats about.", "The wisp flashes brightly at you" }) );
    set_property("light", 1);
}

