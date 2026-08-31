#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("Ogre caveman");
         set_id(({ "ogre", "caveman", "ogre caveman" }));
         set_short("primitive Ogre caveman");
         set_long("This Ogre looks like he's lived in this hole in the wall"
                 " since the beginning of time. The little clothes he does "
                 "wear are tattered and seem pretty useless.");
         set_race("ogre");
         set_body_type("human");
         set("aggressive", 59);
         set_skill("attack", 500);
         set_skill("blunt", 300);
         set_stats("strength", 250);
         set_gender("male");
         set_level(58);
         set_spell_chance(35);
         set_spells(({"rush"}));
    new("/wizards/smoke/mountain/items/weapon/club")->move(this_object());
    force_me("wield club");
}
