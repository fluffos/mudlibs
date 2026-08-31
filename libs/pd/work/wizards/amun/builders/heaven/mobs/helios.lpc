#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Helios");
    set("id", ({ "helios", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Helios%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Helios is the sun god. He is the one who controls night and day.%^RESET%^" );
    set("race", "god" ); 
    set_gender( "male" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 60);
    set_spells( ({ "rush" }) );
    set_spell_chance(60); 
    new(HEVARM "silver_breastplate")->move(this_object());
    new(HEVARM "cloak_of_the_light")->move(this_object());
    new(HEVARM "helm_of_clouds")->move(this_object());
    new(HEVARM "belt_of_clouds")->move(this_object());
    new(HEVWEP "crystalline_blade")->move(this_object());
    new(HEVWEP "crystalline_blade")->move(this_object());
    force_me("wear armour");
    force_me("wear cloak");
    force_me("wear helm");
    force_me("wear belt");
    force_me("wield blade");
    force_me("wield blade 2");
    set_max_hp(9500);
    set_exp(200000);
}
