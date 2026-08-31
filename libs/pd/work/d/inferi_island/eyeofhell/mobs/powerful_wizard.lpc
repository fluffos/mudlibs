#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("riddle");
    set("id", ({ "wizard", "monster" }) );
    set_level( 70 );
    set("short", "Powerful Wizard" );
    set("long", "%^BOLD%^%^RED%^This wizard is the most feared Warlock of all time.  He stands tall, and pierces you with his snake-like eyes.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_class("mage");
    set_subclass("wizard");
    set_spell_chance(80);
    set_spells( ({ "manablast", "manabolt", "pressure", "coalesce", "mercurial me" }) );
    set_skill("wizardry", 70*6);
    set_skill("magic attack", 70*5);
    set_skill("attack", 70*2);
    set_skill("melee", 70*2);
    set("aggressive", 55);
    new(HELLARM+"snakeskin_armour")->move(this_object());
    new(HELLARM+"snakeskin_boots")->move(this_object());
    new(HELLARM+"snakeskin_pants")->move(this_object());
    new(HELLARM+"snakeskin_shirt")->move(this_object());
    //new(HELLWEP+"wand")->move(this_object());
    force_me("wear armour");
    force_me("wear boots");
    force_me("wear shirt");
    force_me("wear pants");
    //force_me("wield wand");
    set_alignment(-1200);
}
