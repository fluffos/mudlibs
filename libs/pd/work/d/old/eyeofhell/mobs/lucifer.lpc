#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Lucifer");
    set("id", ({ "lucifer", "monster" }) );
    set_level( 115 );
    set("short", "Lucifer" );
    set("long", "%^BOLD%^%^RED%^Your eyes lay upon Lucifer himself.  His dark sunken eyes, bright with fire, glare at you with hate.%^RESET%^" );
    set("race", "demon" ); 
    set_gender( "male" );
    set_body_type("demon");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 60);
    set_element_attack("fire", 10);
    set_spell_chance(20);
    set_spells( ({ "gore", "massacre" }) );
    set_emotes(20, ({"%^BOLD%^%^RED%^How dare you attack me!%^RESET%^","%^BOLD%^%^RED%^The eye is MINE!%^RESET%^"}), 1);
    new(HELLARM+"cloak_of_evil")->move(this_object());
    new(HELLARM+"satanic_shield")->move(this_object());
    new(HELLARM+"master_ring")->move(this_object());
    new(HELLWEP+"lava_dagger")->move(this_object());
    force_me("wear cloak");
    force_me("wear shield");
    force_me("wear ring");
    force_me("wield dagger");
}
