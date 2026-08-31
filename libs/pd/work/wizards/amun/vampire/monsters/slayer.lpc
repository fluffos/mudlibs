#include <std.h>
#include <vampq.h>

inherit MONSTER;

void create()  {
::create();
    set_name("The Slayer");
    set_short("%^BOLD%^%^BLACK%^Tall Dark Woman%^RESET%^");
    set_id(({"monster", "slayer"}));
    set_long("%^RESET%^A %^BOLD%^%^BLACK%^sword%^RESET%^ in one hand, a %^ORANGE%^wooden stake%^RESET%^ in the other and dressed thightly in %^ORANGE%^tough %^BOLD%^%^BLACK%^dark leather armour%^RESET%^, this woman means busniess. Her busniess today just happens to be %^BOLD%^%^RED%^you!%^RESET%^");
    set_level(53);
    set("aggressive", 10000);
    set_swarm(1);
    set_gender("female");
    set_race("human");
    set_heart_beat(1);
    set_class("fighter");
    set_subclass("warrior");
    set_body_type("human");
    set_spell_chance (100);
    set_spells(({"warblade"}));
  
    new(VW"slayer_sword") ->move(this_object());
    force_me("wield sword");
    new(VW"slayer_stake") ->move(this_object());
    force_me("wield stake");
    new(VA"slayer_armour") ->move(this_object());
    force_me("wear armour");
}
