#include <std.h>
#include "unalom.h"
inherit MONSTER;

void create()
{
  object key;
 ::create();

        set_name("imp");
        set_id(({"forest imp" }));
        set_short("a %^BOLD%^BLACK%^forest%^RED%^ imp");
        set_long("This is one of the imps that makes its home "
        "in the forests here.  It stands about a meter tall "
        "with jet black skin and glowing red eyes.  It looks "
        "nervous about something.");
        set_alignment(-200);
        set_race("imp");
	set_class("mage");
	set_subclass("pyromancer");
        if(random(10) < 5) {
        set_gender("male");
        } else {
        set_gender("female");
        }
        set_body_type("imp");
        set_level(42+random(8));
	set_spell_chance(20);
        set_spells(({ "scorch", "sear" }));
        set_swarm(1);
 
}
