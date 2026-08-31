#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("talabune mother");
    set_short("%^RESET%^%^YELLOW%^%^BOLD%^Talabune%^RESET%^ mother");
    set_long("This drow is fairly frail looking, although she might have some tricks up her sleeves.  Her eyes are %^YELLOW%^yellow%^RESET%^ with fiery fury.  Her white hair is covered in a circle of flames.");
    set_id(({"drow", "mother", "talabunemother", "talabune mother"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment("-500");
    set_gender("female");
    set_class("mage");
    set_subclass("pyromancer");
   new(ARM"flamingdress")->move(this_object());
     force_me("wear dress");
   new(ARM"flamingring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(200));
    set_spell_chance(25);   
    set_spells(({"flamebraid", "burn"}));   
}

