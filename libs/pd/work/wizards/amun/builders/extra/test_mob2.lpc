#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Lich");
    set("id", ({ "lich", "monster" }) );
    set_level( 70 );
    set("short", "Lich" );
    set("long", "%^BOLD%^%^RED%^Once a human, the Lich slouches infront of you.  You notice that in place of eye sockets, two glowing fires burn with relentless anguish.%^RESET%^" );
    set("race", "Lich" ); 
    set_gender( "male" );
    set_body_type("Lich");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 55);
    new(HELLARM+"inferi_belt")->move(this_object());
    new(HELLARM+"inferi_platemail")->move(this_object());
    new(HELLARM+"inferi_ring")->move(this_object());
    new(HELLWEP+"inferi_axe")->move(this_object());
    new("/wizards/amun/test_tunic")->move(this_object());
    force_me("wear belt");
    force_me("wear platemail");
    force_me("wear tunic");
    force_me("wear ring");
    force_me("wield axe");
    set_max_hp(9500);
    set_exp(190000);
}
