#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("sluggish snail");
    set_short("%^RESET%^%^ORANGE%^a sluggish snail%^RESET%^");
    set_long("This very slow-moving snail is very sluggish in actions, and if it were not for his shell, it would be hard to tell that he is a snail.  He is too fat to fit into his shell, and pops out of it at every opening.");
    set_id(({"sluggish snail", "snail", "a sluggish snail", "sluggishsnail"}));
    set_level(5+random(3));
    set_race("snail");
    set_body_type("blob");
    set_gender("male");
    set_class("animal");
    set_subclass("strong");
    add_money("gold", 5+random(50));
    set_spell_chance(10);   
    set_spells(({"jab"}));  
}


