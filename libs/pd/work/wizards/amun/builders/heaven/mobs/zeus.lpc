#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Zeus");
    set("id", ({ "zeus", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Zeus%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Zeus is the the supreme god. Originally a sky deity associated with rain and agriculture, he developed into the great father god, prime protector of the state, concerned with all aspects of life. At his temple on the Capitol, triumphant generals honored him with their spoils and magistrates paid homage to him with sacrifices.%^RESET%^" );
    set("race", "god" ); 
    set_gender( "male" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("clergy");
    set("aggressive", 60);
    set_spells( ({ "rush" }) );
    set_spell_chance(60); 
    new(HEVARM "silver_breastplate")->move(this_object());
    new(HEVARM "cloak_of_the_light")->move(this_object());
    new(HEVARM "helm_of_clouds")->move(this_object());
    new(HEVARM "belt_of_clouds")->move(this_object());
    new(HEVWEP "lightening_bolt")->move(this_object());
    new(HEVWEP "lightening_bolt")->move(this_object());
    force_me("wear armour");
    force_me("wear cloak");
    force_me("wear helm");
    force_me("wear belt");
    force_me("wield bolt");
    force_me("wield bolt 2");
    set_max_hp(9500);
    set_exp(200000);
}
