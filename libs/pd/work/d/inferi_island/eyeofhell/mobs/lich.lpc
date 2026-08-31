#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Lich");
    set("id", ({ "lich", "monster" }) );
    set_level( 70 );
    set("short", "Lich" );
    set("long", "%^BOLD%^%^RED%^Once a human, the Lich slouches in front of you.  You notice that in place of eye sockets, two glowing fires burn with relentless anguish.%^RESET%^");
    set("race", "lich" ); 
    set_gender( "male" );
    set_body_type("lich");
    set_fingers(5); 
    set_class("mage");
    set("aggressive", 55);
    new(HELLARM+"inferi_belt")->move(this_object());
    new(HELLARM+"inferi_platemail")->move(this_object());
    new(HELLARM+"inferi_ring")->move(this_object());
    new(HELLWEP+"inferi_axe")->move(this_object());
    force_me("wear belt");
    force_me("wear platemail");
    force_me("wear ring");
    force_me("wield axe");
    set_alignment(-1400);
    set_spells( ({ "chilltouch" }) );
    set_spell_chance(25);
    set_undead(1);
}
