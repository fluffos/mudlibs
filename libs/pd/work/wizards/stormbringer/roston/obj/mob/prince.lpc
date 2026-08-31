#include <std.h>
#include <roston.h>

inherit MONSTER;

void create() {
::create();
    set_name("Prince");
    set_short("%^BLUE%^Royal Prince %^RESET%^");
    set_long("A young dwarf with hardly a chinhair.");
    set_id(({"prince", "royal prince"}));
    set_class("clergy");
    set_subclass("monk")
    set_alignment(10000);
    set_level(30+random(10));
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    set_spell_chance(35);
    set_spells( ({ "snapkick","furystrike","manaburn","heal me" }) );
    set_say(5, ({"I will reward the first one to bring me proof of a spy in our town.",
                 "I have been trying to fortify my keep, I fear an invasion force draws near.",
                 "There has been talk of a dark stranger sneaking about Roston, I seek proof.",
                 "This is my first campaign away from my homeland."}), 0);
}   
                                   
