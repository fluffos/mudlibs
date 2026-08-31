#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Queen Senamun");
    set("id", ({ "queen", "senamun", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Queen Senamun" );
    set("long", "%^BOLD%^%^YELLOW%^Both beautiful and strong is Queen Senamun.  She stands proud in hopes of saving her husband and King, King Hamen." );
    set("race", "human" ); 
    set_gender( "female" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set("aggressive", 40);
    set_emotes(1, ({"With spear in hand, the Queen stands waiting for a fight."}), 0);
    new(ARM+"menefret")->move(this_object());
    new(ARM+"menefret2")->move(this_object());
    if(random(100) > 90)
	new(ARM+"amulet")->move(this_object());
    new(ARM+"golden_collar")->move(this_object());
    new(ARM+"golden_silk_robes")->move(this_object());
    new(WEP+"split_spear")->move(this_object());
    new(WEP+"split_spear")->move(this_object());
    force_me("wear menefret");
    force_me("wear menefret 2");
    force_me("wear amulet");
    force_me("wear collar");
    force_me("wear robes");
    force_me("wield spear");
    force_me("wield spear 2");
}
