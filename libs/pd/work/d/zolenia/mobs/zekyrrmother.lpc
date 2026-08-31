#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("zekyrr mother");
    set_short("%^RESET%^%^BLUE%^%^BOLD%^Zekyrr%^RESET%^ mother");
    set_long("This drow is fairly frail looking, although she might have some tricks up her sleeves.  Her eyes are %^BLUE%^blue%^RESET%^ with magical fury.  She has many scars covering her body, about the size of a dragon's claw.");
    set_id(({"drow", "mother", "zekyrrmother", "zekyrr mother"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment(-500);
    set_gender("female");
    set_class("mage");
    set_subclass("sorceror");
   new(ARM"dragonscaledress")->move(this_object());
     force_me("wear dress");
   new(ARM"dragonscalering")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(200));
    set_spell_chance(25);   
    set_spells(({"mindlance", "amnesia", "fracture"}));   
}

