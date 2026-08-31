#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Erinyes");
    set("id", ({ "erinyes", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Erinyes%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Erinyes is a daughter of Mother Earth. She was a powerful divinity that personified conscience and punished crimes against kindred blood, especially matricide. She is represented as winged women with serpent hair.%^RESET%^" );
    set("race", "goddess" ); 
    set_gender( "female" );
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
    force_me("wear armour");
    force_me("wear cloak");
    force_me("wear helm");
    force_me("wear belt");
    set_max_hp(9500);
    set_exp(200000);
}
