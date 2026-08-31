#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Hell Demon");
    set("id", ({ "hell demon", "demon", "monster" }) );
    set_level( 70 );
    set("short", "Hell Demon" );
    set("long", "%^BOLD%^%^RED%^With the skin that feels like leather, souless black eyes that pierce into you, large black horns and enormous wings, the Hell Demon is one of the most feared in the Oculus Inferi.%^RESET%^" );
    set("race", "demon" ); 
    set_gender( "male" );
    set_body_type("demon");
    set_fingers(5); 
    set_class("rogue");
    set_spell_chance(25);
    set_spells( ({ "gore" }) );
    set("aggressive", 55);
    new(HELLARM+"lava_mask")->move(this_object());
    new(HELLARM+"lava_bracers")->move(this_object());
    new(HELLARM+"lava_leggings")->move(this_object());
    new(HELLWEP+"demonic_knife")->move(this_object());
    new(HELLWEP+"demonic_knife")->move(this_object());
    force_me("wear mask");
    force_me("wear bracers");
    force_me("wear leggings");
    force_me("wield knife");
    force_me("wield knife 2");
    set_alignment(-1500);
}
