#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow merchant");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ merchant");
    set_long("This drow trader isn't the strongest looking fella, although his pockets do look fairly fat..");
    set_id(({"drow", "merchant", "drowmerchant", "drow merchant"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment("-500");
    set_gender("male");
    set_class("wanderer");
    set_subclass("jester");
   new(ARM"darkshirt")->move(this_object());
     force_me("wear shirt");
   new(ARM"darkring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(1100));
    set_spell_chance(25);   
    set_spells(({"flick", "strike"}));   
}

