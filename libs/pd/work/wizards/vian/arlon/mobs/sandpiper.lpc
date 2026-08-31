#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("sandpiper");
    set_short("a little sandpiper");
    set_long("This sandpiper chirps along the beach, pecking at worms and small crabs in the sand.  He is a small white bird with a brown back and brown spots on his belly.  He has dazzling black eyes, and a short black beak.");
    set_id(({"sandpiper", "sand piper", "piper", "little sandpiper"}));
    set_level(6+random(3));
    set_race("sandpiper");
    set_body_type("fowl");
    set_gender("male");
    set_class("animal");
    set_subclass("fast");
    add_money("gold", 5+random(60));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
    set_emotes(4,({ "The sandpiper chirps." }),0);
}


