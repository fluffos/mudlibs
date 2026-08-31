#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("seagull");
    set_short("a very large black-backed gull");
    set_long("This seagull is very large for a bird, and is almost all white except for his black back.  He has two small orange legs which connect to his webbed feet, and a long orange beak.");
    set_id(({"sea gull", "seagull", "gull", "black-backed gull"}));
    set_level(6+random(3));
    set_race("seagull");
    set_body_type("fowl");
    set_gender("male");
    set_class("animal");
    set_subclass("fast");
    add_money("gold", 5+random(50));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
    set_emotes(1,({ "The seagull lets out a harsh wailing call." }),0);
}


