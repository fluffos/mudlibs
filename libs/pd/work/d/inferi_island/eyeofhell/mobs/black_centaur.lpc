#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Black Centaur");
    set("id", ({ "black centaur", "centaur", "monster" }) );
    set_level( 70 );
    set("short", "Black Centaur" );
    set("long", "%^BOLD%^%^RED%^The centaur has blood dripping down its body.  He looks up and snuffs at you, causing black blood to drip from his nose.%^RESET%^" );
    set("race", "centaur" ); 
    set_gender( "male" );
    set_body_type("centaur");
    set_class("fighter");
    set("aggressive", 55);
    new(HELLARM+"black_centaur_leggings")->move(this_object());
    new(HELLARM+"black_horseshoes")->move(this_object());
    new(HELLARM+"black_saddle")->move(this_object());
    new(HELLWEP+"inferi_bow")->move(this_object());
    force_me("wear leggings");
    force_me("wear horseshoes");
    force_me("wear saddle");
    force_me("wield bow");
    set_alignment(-1100);
}
