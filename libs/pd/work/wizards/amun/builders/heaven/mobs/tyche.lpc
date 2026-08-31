#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Tyche");
    set("id", ({ "tyche", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Tyche%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Tyche is the goddess of fortune. Worshiped under several forms, she appears to have originally been a goddess of fertility.%^RESET%^" );
    set("race", "goddess" ); 
    set_gender( "female" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 60);
    set_spell_chance(60); 
    new(HEVARM "silver_breastplate")->move(this_object());
    new(HEVARM "cloak_of_the_light")->move(this_object());
    new(HEVARM "helm_of_clouds")->move(this_object());
    new(HEVARM "belt_of_clouds")->move(this_object());
    new(HEVARM "diamond_earrings")->move(this_object());
    force_me("wear armour");
    force_me("wear cloak");
    force_me("wear helm");
    force_me("wear belt");
    force_me("wear earrings");
    set_max_hp(9500);
    set_exp(200000);
}
