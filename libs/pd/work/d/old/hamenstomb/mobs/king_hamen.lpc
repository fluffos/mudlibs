#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("King Hamen");
    set("id", ({ "king", "hamen", "monster" }) );
    set_level( 75 );
    set("short", "%^BOLD%^%^YELLOW%^King Hamen" );
    set("long", "%^BOLD%^%^YELLOW%^Proud and strong, the King stands before you with pride.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set("aggressive", 40);
    set_emotes(1, ({"King Hamen Holds his dagger over his heart and bows to his noble opponent."}), 0);
    new(ARM+"royal_cloak")->move(this_object());
    new(ARM+"gold_plated_gauntlets")->move(this_object());
    new(ARM+"gold_plated_armour")->move(this_object());
    new(ARM+"gold_plated_boots")->move(this_object());
    if(random(100) > 90)
	new(ARM+"golden_tunic")->move(this_object());
    new(WEP+"golden_dagger")->move(this_object());
    new(ARM+"golden_corselet")->move(this_object());
    force_me("wear cloak");
    force_me("wear gloves");
    force_me("wear armour");
    force_me("wear boots");
    force_me("wear tunic");
    force_me("wear leggings");
    force_me("wield dagger");
}
