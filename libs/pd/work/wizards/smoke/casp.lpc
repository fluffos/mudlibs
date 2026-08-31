#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("caspurrnia");
         set_id(({ "caspurrnia", "casp", "ogre caveman" }));
         set_short("Caspurrnia, the prettiest Ogre you ever did see");
         set_long("Caspurrnia bats her eyelashes at you and giggles!");
         set_race("ogre");
         set_body_type("human");
         set("aggressive", 1);
         set_skill("attack", 500);
         set_skill("blunt", 300);
         set_stats("strength", 250);
         set_gender("female");
         set_level(130);
         set_spell_chance(35);
         set_spells(({"rush"}));
    new("/wizards/smoke/mountain/items/weapon/club")->move(this_object());
    force_me("wield club");
}
