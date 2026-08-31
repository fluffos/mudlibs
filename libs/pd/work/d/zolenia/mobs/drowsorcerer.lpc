#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow sorcerer");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ %^BLUE%^sorcerer");
    set_long("This drow sorcerer isn't weak looking, nor strong.  He is deep in thought, a master of the mind.");
    set_id(({"drow", "sorcerer", "drowsorcerer", "drow sorcerer"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment(-500);
    set_gender("male");
    set_class("mage");
    set_subclass("sorceror");
   new(ARM"darkrobes")->move(this_object());
     force_me("wear robes");
   new(ARM"darkring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(400));
    set_spell_chance(25);   
    set_spells(({"fracture", "mindlance", "mindshock"}));   
}

