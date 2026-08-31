#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Ares");
    set("id", ({ "ares", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Ares%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Ares is the Olympian god of war. He is usually said to be the son of Zeus and Hera; but in some legends he and Eris, his twin sister, were born when Hera touched a flower. A fierce warrior, he loved battle and often took part in conflicts between mortals.%^RESET%^" );
    set("race", "god" ); 
    set_gender( "male" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 60);
    set_spells( ({ "rush", "slash" }) );
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
