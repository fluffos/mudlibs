#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Sauran Knight");
    set("id", ({ "sauran knight", "knight", "monster" }) );
    set_level( 70 );
    set("short", "Sauran Knight" );
    set("long", "%^BOLD%^%^RED%^With the black skin of a dragon, and lengthy horns, the sauran looks at you with the intent to kill.%^RESET%^" );
    set("race", "sauran" ); 
    set_gender( "female" );
    set_body_type("sauran");
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 55);
    new(HELLARM+"fire_boots")->move(this_object());
    new(HELLARM+"fire_armour")->move(this_object());
    new(HELLARM+"lava_gauntlets")->move(this_object());
    new(HELLWEP+"blade_of_fire")->move(this_object());
    new(HELLWEP+"blade_of_fire")->move(this_object());
    force_me("wear boots");
    force_me("wear armour");
    force_me("wear gauntlets");
    force_me("wield blade");
    force_me("wield blade 2");
    set_max_hp(9500);
    set_alignment(-(600+random(400)));
}
