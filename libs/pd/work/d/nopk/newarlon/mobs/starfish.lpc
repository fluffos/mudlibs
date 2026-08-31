#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("dazzling starfish");
    set_short("%^RESET%^a %^MAGENTA%^%^BOLD%^dazzling%^RESET%^ starfish");
    set_long("This starfish is a beautiful shade of purple.  She is merely a body with five legs in the shape of a star, but still beautiful to see.  She moves very slowly.");
    set_id(({"dazzling starfish", "starfish", "a dazzling starfish", "star fish"}));
    set_level(5+random(3));
    set_race("starfish");
    set_body_type("blob");
    set_gender("female");
    set_class("animal");
    set_subclass("sturdy");
    add_money("gold", 5+random(50));
    set_spell_chance(10);   
    set_spells(({"jab"}));  
}


