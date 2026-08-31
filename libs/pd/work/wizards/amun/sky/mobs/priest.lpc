#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Priest");
    set_id( ({ "priest" }) );
    set_level( 60 );
    set_short("Priest" );
    set_long("This priest is here on missionary work, getting to know the monk way of life and aid those coming to the temple. He has a strong belief in the good way of life." );
    set_race( "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_spells( ({ "pain", "wound", "turn", "lifewarp" }) );
    set_spell_chance(60); 
    set_skill("melee", 250);
    set_class("clergy");
    set_subclass("cleric");
    set_aggressive(40);
    set_alignment(1000);
    new(SKYARM "black_pants")->move(this_object());
    new(SKYARM "black_shirt")->move(this_object());
    new(SKYARM "white_collar")->move(this_object());
    force_me("wear pants");
    force_me("wear shirt");
    force_me("wear collar");
}
