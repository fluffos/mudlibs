#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("talabune male");
    set_short("%^RESET%^%^YELLOW%^%^BOLD%^Talabune%^RESET%^ male");
    set_long("This drow is weak looking, simply used to fulfill the Matron Mother's needs and produce more children of the Talabune house.  His white hair is covered in a circle of flames.");
    set_id(({"drow", "male", "talabunemale", "talabune male"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment(-500);
    set_gender("male");
    set_class("mage");
    set_subclass("pyromancer");
   new(ARM"flamingshirt")->move(this_object());
     force_me("wear shirt");
   new(ARM"flamingring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(400));
    set_spell_chance(25);   
    set_spells(({"shroud", "flamewall"}));   
}

