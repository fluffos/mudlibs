#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Fallen Angel");
    set("id", ({ "fallen angel", "monster", "angel" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^BLACK%^%^Fallen Angel%^RESET%^" );
    set("long", "%^BOLD%^%^BLACK%^This is an ex angel who has lost the Father's favour because of disobedience.This is an ex angel who opposed the Father and is a follower of the Devil.%^RESET%^" );
    set("race", "archangel" ); 
    set_gender( "male" );
    set_body_type("archangel");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 60);
    set_spells( ({ "rush" }) );
    set_spell_chance(60); 
    new(HEVARM "black_earrings")->move(this_object());
    new(HEVARM "torn_white_pants")->move(this_object());
    new(HEVARM "black_wings")->move(this_object());
    new(HEVARM "blackened_halo")->move(this_object());
    new(HEVARM "torn_white_shirt")->move(this_object());
    new(HEVARM "torn_white_robes")->move(this_object());
    new(HEVWEP "firey_ember")->move(this_object());
    new(HEVWEP "firey_ember")->move(this_object());
    force_me("wear earrings");
    force_me("wear pants");
    force_me("wear wings");
    force_me("wear halo");
    force_me("wear shirt");
    force_me("wear robes");
    force_me("wield ember");
    force_me("wield ember");
    set_max_hp(9000);
    set_exp(180000);
}
