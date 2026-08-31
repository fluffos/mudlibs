#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow master sorcerer");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ master %^BLUE%^sorcerer");
    set_long("This drow sorcerer is very strong looking, both in the body and mind.  He seems to be an instructor of the other students.");
    set_id(({"drow", "drow sorcerer", "master", "sorcerer", "drowmastersorcerer", "drow master sorcerer"}));
    set_level(90+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_class("mage");
    set_alignment(-1000);
    set_subclass("sorceror");
   new(ARM"darkrobes")->move(this_object());
     force_me("wear robes");
   new(ARM"darkring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(400));
    set_spell_chance(25);   
    set_spells(({"psiblades", "mindlance", "mindlance", "mindshock", "suppress", "amnesia"}));   
}

