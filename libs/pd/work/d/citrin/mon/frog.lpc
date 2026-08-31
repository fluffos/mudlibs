//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("frog");
    set_short("a green frog");
    set_long("The frog likes to jump back and forth.  It is "
      "slightly greenish in color.");
    set_race("frog");
    set_id(({ "green frog", "frog" }));
    set_body_type("canine");
    set_level(30);
    if(random(2))
	set_gender("male");
    else set_gender("female");
    set_emotes(5, 
      ({
	"The frog sticks it's tongue out and catches a fly.",
	"The frog hops around a bit.",
	"The frog goes: Ribbit!  Ribbit!",
      }), 0);
}
