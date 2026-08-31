#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("Ogre hunteress");
         set_id(({ "ogre", "hunteress", "ogre hunteress" }));
         set_short("primitive Ogre hunteress");
         set_long("This Ogre looks like she's lived in this mountain"
                 " her entire life and never stepped foot outside of it. "
                 "Her armor is very crude since she is barred from the outs"
		"ide world and the technologies of today.");
         set_race("ogre");
         set_body_type("human");
         set("aggressive", 54);
         set_skill("projectile", 300);
         set_stats("dexterity", 150);
         set_gender("female");
         set_level(60);
         set_spell_chance(30);
         set_spells(({"headbutt"}));
   new("/wizards/smoke/mountain/items/weapon/spear")->move(this_object());
    force_me("wield spear");
}
