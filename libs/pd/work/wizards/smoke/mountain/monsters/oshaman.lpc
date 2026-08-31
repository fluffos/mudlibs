#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("Ogre shaman");
         set_id(({ "ogre", "shaman", "ogre shaman" }));
         set_short("primitive Ogre shaman");
         set_long("This Ogre looks like he's lived in this mountain"
                 " his entire life and never stepped foot outside of it. "
                 "His armor is very crude since he is barred from the outs"
		"ide world and the technologies of today.");
         set_race("ogre");
         set_body_type("human");
         set("aggressive", 59);
         set_skill("faith", 300);
         set_stats("wisdom", 250);
         set_gender("male");
         set_level(65);
         set_spell_chance(30);
         set_spells(({"solarflare"}));
    new("/wizards/smoke/mountain/armour/mask")->move(this_object());
    force_me("wear mask");
}
