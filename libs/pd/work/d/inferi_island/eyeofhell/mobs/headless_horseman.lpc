#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Headless Horseman");
    set("id", ({ "headless horseman", "horseman", "monster" }) );
    set_level( 70 );
    set("short", "Headless Horseman" );
    set("long", "%^BOLD%^%^RED%^Incredibly tall, even without his head, this Horseman can still sense your presence.  He holds a pumpkin, lit with fire, in his hand.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    remove_limb("head");
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 55);
    new(HELLARM+"fire_armour")->move(this_object());
    new(HELLARM+"ring_of_fire")->move(this_object());
    new(HELLWEP "pumpkin")->move(this_object());
    new(HELLWEP "pumpkin")->move(this_object());
    force_me("wear ring");
    force_me("wear armour");
    force_me("wield pumpkin");
    force_me("wield pumpkin 2");
    set_alignment(-750);
    set_undead(1);
}
