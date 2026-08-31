#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Repenting Cleric");
    set_id( ({ "repenting cleric" "repent", "repenting", "cleric" }) );
    set_level( 60 );
    set_short("Repenting Cleric" );
    set_long("This cleric has come to the sky temple to repent his sins and form a new life. He is currently praying to his higher power." );
    set_race( "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_spells( ({ "pain", "wound", "turn", "lifewarp" }) );
    set_spell_chance(60); 
    set_skill("melee", 250);
    set_class("clergy");
    set_subclass("cleric");
    set_aggressive(40);
    set_alignment(600);
    new(SKYARM "white_robes")->move(this_object());
    force_me("wear robes");
}
