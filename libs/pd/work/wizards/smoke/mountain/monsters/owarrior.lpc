#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("Ogre warrior");
         set_id(({ "ogre", "warrior", "ogre warrior" }));
         set_short("primitive Ogre warrior");
         set_long("This Ogre looks like he's lived in this mountain"
                 " his entire life and never stepped foot outside of it. "
                 "His armor is very crude since he is barred from the outs"
		"ide world and the technologies of today.");
         set_race("ogre");
         set_body_type("human");
         set("aggressive", 59);
         set_skill("attack", 500);
         set_skill("blade", 300);
         set_stats("strength", 250);
         set_gender("male");
         set_level(62);
         set_spell_chance(50);
         set_spells(({"slash"}));
    new("/wizards/smoke/mountain/items/weapon/sword")->move(this_object());
    force_me("wield sword");
    new("/wizards/smoke/mountain/items/weapon/sword")->move(this_object());
    force_me("wield sword");
}
