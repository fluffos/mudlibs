#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("spider");
    set_short("a sneaky looking spider");
    set_long("This large and very hairy spider has a glint of %^BOLD%^%^BLACK%^black%^RESET%^ in his eyes, as if stealth has filled his life.");
    set_id(({"spider", "sneaky spider"}));
    set_level(35+random(6));
    set_race("spider");
    set_body_type("arachnoid");
    set("aggressive",30);
    set_gender("male");
    set_class("rogue");
    set_subclass("assassin");
   new(WEP"fangs")->move(this_object());
     force_me("wield fangs");
    set_spell_chance(25);   
    set_spells(({"jab", "stab"}));   
}
