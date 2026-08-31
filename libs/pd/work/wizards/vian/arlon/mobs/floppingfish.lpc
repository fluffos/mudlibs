#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("a flopping fish");
    set_short("%^RESET%^%^BLUE%^%^BOLD%^a flopping fish%^RESET%^");
    set_long("This small blue fish flops around in the sand.  It seems like it should be dead by now, but it finds its way into a puddle every once in a while.");
    set_id(({"fish", "floppingfish", "blue fish", "flopping fish"}));
    set_level(1+random(2));
    set_race("fish");
    set_body_type("fish");
    set_gender("male");
    set_class("animal");
    set_subclass("fast");
    add_money("gold", 5+random(20));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
    set_emotes(1,({ "%^BLUE%^%^BOLD%^The blue fish flops on the sand.%^RESET%^" }),0);

}


