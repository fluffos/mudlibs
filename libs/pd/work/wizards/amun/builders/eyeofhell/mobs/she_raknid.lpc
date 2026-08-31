#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("She Raknid");
    set("id", ({ "she raknid", "raknid", "monster" }) );
    set_level( 70 );
    set("short", "She Raknid" );
    set("long", "%^BOLD%^%^RED%^The She Raknid towers over you with her stomach showing.  Her eyes beating down on you, and 4 of her arms have piercing blades at the ends of them.%^RESET%^" );
    set("race", "raknid" ); 
    set_gender( "female" );
    set_body_type("raknid");
    set_wielding_limbs( ({ "first hand" }) );
    set_ac("first hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 55);
    new(HELLARM+"spider_gauntlets")->move(this_object());
    new(HELLARM+"recluse_bracers")->move(this_object());
    new(HELLARM+"ring_of_raknids")->move(this_object());
    new(HELLARM+"widow_armour")->move(this_object());
    new(HELLWEP+"black_sword")->move(this_object());
    new(HELLWEP+"black_sword")->move(this_object());
    new(HELLWEP+"black_sword")->move(this_object());
    new(HELLWEP+"black_sword")->move(this_object());
    force_me("wear gauntlets");
    force_me("wear bracers");
    force_me("wear ring");
    force_me("wear armour");
    force_me("wield sword");
    force_me("wield sword 2");
    force_me("wield sword 3");
    force_me("wield sword 4");
    set_max_hp(9500);
    set_exp(190000);
}
