#include <std.h>
#include "unalom.h"
inherit MONSTER;

void create()
{
  object key;
 ::create();

        set_name("parrot");
        set_id(({"shadowy parrot" }));
        set_short("a %^BOLD%^BLACK%^shadowy%^RED%^ parrot");
        set_long("This parrot seems to have had its feathers "
        "somehow changed to a shadowy black color.  Its eyes "
        "glow red, making it look demonic.");
        set_alignment(-200);
	set_race("parrot");
        if(random(10) < 5) {
        set_gender("male");
        } else {
        set_gender("female");
        }
        set_body_type("fowl");
        set_level(42+random(8));
        set_swarm(1);
 
}
