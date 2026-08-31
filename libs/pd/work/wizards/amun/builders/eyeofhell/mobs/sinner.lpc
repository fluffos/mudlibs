#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Sinner");
    set("id", ({ "sinner", "monster" }) );
    set_level( 70 );
    set("short", "Sinner" );
    set("long", "%^BOLD%^%^RED%^This human, is one of the fallen from the mortal realm.  He is engulfed in fire.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "female" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("rogue");
    set("aggressive", 55);
    set_element_attack("fire", 10);
    new(HELLARM+"helm_of_fire")->move(this_object());
    new(HELLARM+"ring_of_fire")->move(this_object());
    new(HELLWEP+"demonic_knife")->move(this_object());
    new(HELLWEP+"demonic_knife")->move(this_object());
    force_me("wear helm");
    force_me("wear ring");
    force_me("wield knife");
    force_me("wield knife 2");
    set_max_hp(9500);
    set_exp(180000);
}
