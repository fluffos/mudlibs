#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("derranged Ogre");
         set_id(({ "ogre" }));
         set_short("crazy and derranged Ogre");
         set_long("This Ogre looks like he's seen a few battles in his day."
                 " His entire body is covered in scars, which he wears proud"
                 "ly. He looks about as solid as a brick house; huge for even"
		" an Ogre.");
         set_race("ogre");
         set_body_type("human");
         set("aggressive", 124);
         set_skill("attack", 500);
         set_skill("blade", 300);
         set_stats("strength", 250);
         set_gender("male");
         set_level(62);
         set_spell_chance(50);
         set_spells(({"maul", "rage"}));
    new("/wizards/smoke/mountain/items/weapon/sword")->move(this_object());
    force_me("wield sword");
    new("/wizards/smoke/mountain/items/weapon/club")->move(this_object());
    force_me("wield club");
}
