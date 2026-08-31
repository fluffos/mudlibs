#include <std.h>
#include "unalom.h"
inherit MONSTER;

void create()
{
  object key;
 ::create();

        set_name("snake");
        set_id(({"forest snake" }));
        set_short("a %^BOLD%^BLACK%^forest%^RED%^ snake");
        set_long("This is one of the poisonous snakes of the "
        "forest.  Its scales seem to have been magically transformed "
        "to be jet black, and its eyes glow red with a strange "
        "magical light.");
        set_alignment(-200);
	set_property("bite", 1);
        set_race("snake");
        if(random(10) < 5) {
        set_gender("male");
        } else {
        set_gender("female");
        }
        set_body_type("snake");
        set_level(44+random(8));
        set_spell_chance(20);
        set_spells(({ "bite" }));
        set_swarm(1);
 
}
