#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("Ogre caveman");
         set_id(({ "ogre", "cavewoman", "ogre cavewoman" }));
         set_short("primitive Ogre cavewoman");
         set_long("This Ogre looks like she's lived in this hole in the wall"
                 " since the beginning of time. The little clothes she does "
                 "wear are tattered and seem pretty useless.");
         set_race("ogre");
         set_body_type("human");
         set("aggressive", 59);
         set_skill("blunt", 300);
         set_gender("female");
         set_level(55);
         set_spell_chance(35);
         set_spells(({"headbutt"}));
    new("/wizards/smoke/mountain/items/weapon/club")->move(this_object());
    force_me("wield club");
}
