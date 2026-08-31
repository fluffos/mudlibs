#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Siren");
    set("id", ({ "siren", "monster" }) );
    set_level( 70 );
    set("short", "Siren" );
    set("long", "%^BOLD%^%^RED%^The Siren is beautiful and with the irresistible charm of song she may lure you into her trap.  Beware of her paralyzing dances and songs.%^RESET%^" );
    set("race", "nymph" ); 
    set_gender( "female" );
    set_body_type("nymph");
    set_class("wanderer");
    set_subclass("bard");
    set("aggressive", 55);
    set_spell_chance(20);
    set_spells( ({ "sing song of darkness", "sing fugue of woes", "sing anathema au vengeance" }) );
    new(HELLARM+"red_diamond_amulet")->move(this_object());
    new(HELLARM+"harp")->move(this_object());
    force_me("wear amulet");
    set_alignment(-550);
}
