#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Riddle");
    set("id", ({ "riddle", "monster" }) );
    set_level( 110 );
    set("short", "Riddle" );
    set("long", "%^BOLD%^%^RED%^Riddle is the most feared Warlock of all times.  He stands tall, and pierces you with his snake-like eyes.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 55);
    new(HELLARM+"snakeskin_armour")->move(this_object());
    new(HELLARM+"snakeskin_boots")->move(this_object());
    new(HELLARM+"snakeskin_pants")->move(this_object());
    new(HELLARM+"snakeskin_shirt")->move(this_object());
    new(HELLWEP+"wand")->move(this_object());
    force_me("wear armour");
    force_me("wear boots");
    force_me("wear shirt");
    force_me("wear pants");
    force_me("wield wand");
}
