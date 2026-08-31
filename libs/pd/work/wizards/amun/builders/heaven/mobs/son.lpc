#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Son");
    set("id", ({ "son", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^WHITE%^%^Son%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^This is the son of the Father. He is his Father's right hand man and helps him do all of his good work. The Son is very important to all around the Heavenly grounds.%^RESET%^" );
    set("race", "Higher Being" ); 
    set_gender( "male" );
    set_body_type("archangel");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_alignment(200);
    set_class("fighter");
    set("aggressive", 60);
    set_spells( ({ "rush" }) );
    set_spell_chance(60); 
    new(HEVARM "white_pants")->move(this_object());
    new(HEVARM "white_robes")->move(this_object());
    new(HEVARM "white_shirt")->move(this_object());
    new(HEVARM "wings_of_light")->move(this_object());
    new(HEVARM "holy_halo")->move(this_object());
    force_me("wear pants");
    force_me("wear wings");
    force_me("wear halo");
    force_me("wear shirt");
    force_me("wear robes");
    set_max_hp(9750);
    set_exp(220000);
}
