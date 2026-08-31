#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Hades");
    set("id", ({ "hades", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Hades%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Hades is the god of the underworld. Not only a god of the dead, he is identified as a god of the earth's fertility.%^RESET%^" );
    set("race", "god" ); 
    set_gender( "male" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("mage");
    set_subclass("necromancer");
    set("aggressive", 60);
    set_spells( ({ "chaoswave", "deathtouch" }) );
    set_spell_chance(60); 
    new(HEVARM "silver_breastplate")->move(this_object());
    new(HEVARM "cloak_of_the_light")->move(this_object());
    new(HEVARM "helm_of_clouds")->move(this_object());
    new(HEVARM "belt_of_clouds")->move(this_object());
    force_me("wear armour");
    force_me("wear cloak");
    force_me("wear helm");
    force_me("wear belt");
    set_max_hp(9500);
    set_exp(200000);
}
