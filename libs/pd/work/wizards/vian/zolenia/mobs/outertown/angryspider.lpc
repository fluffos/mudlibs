#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("spider");
    set_short("a angry looking spider");
    set_long("This large and very hairy spider has a glint of %^RED%^red%^RESET%^ in his eyes, as if anger has filled his life.");
    set_id(({"spider", "angry spider"}));
    set_level(40);
    set_race("spider");
    set_body_type("arachnoid");
    set("aggressive",30);
    set_gender("male");
    set_class("fighter");
    set_subclass("berserker");
   new(WEP"claws")->move(this_object());
     force_me("wield claws");
    set_spell_chance(25);   
    set_spells(({"jab", "rage"}));   
}
