#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("sea turtle");
    set_short("%^RESET%^%^GREEN%^an ancient sea turtle");
    set_long("This sea turtle looks to be hundreds of years old.  She is mostly a very large shell, with a flipper coming from the top and bottom left and right sides.  She has a small tail, and a small head peeking out of her shell.");
    set_id(({"sea turtle", "seaturtle", "turtle", "ancient sea turtle"}));
    set_level(6+random(3));
    set_race("sea turtle");
    set_body_type("seamonster");
    set_gender("female");
    set_class("animal");
    set_subclass("sturdy");
    add_money("gold", 5+random(50));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
    set_emotes(2,({ "The sea turtle puts her head in and out of her shell." }),0);
}


