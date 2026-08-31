#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("Mountain Troll");
         set_id(({ "troll", "mountain troll" }));
         set_short("A large, ugly Mountain Troll");
         set_long("This Troll is huge! His green skin is scarred and"
                 " rough. He lives in this mountain and hunts the animals"
                 " that cross his path.");
         set_race("troll");
         set_body_type("human");
         set("aggressive", 49);
         set_skill("attack", 500);
         set_skill("blunt", 300);
         set_stats("strength", 250);
         set_gender("male");
         set_level(68);
         set_spell_chance(35);
         set_spells(({"rush","jab"}));
    new("/wizards/smoke/mountain/items/weapon/club")->move(this_object());
    force_me("wield club");
    new("/wizards/smoke/mountain/items/weapon/club")->move(this_object());
    force_me("wield club");
    new("/wizards/smoke/mountain/armour/helmet")->move(this_object());
    force_me("wear helmet");

}
