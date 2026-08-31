#include <std.h>
#include <zolenia.h>
inherit MONSTER;

void create() {
::create();
    set_name("zekyrr male");
    set_short("%^RESET%^%^BLUE%^Zekyrr %^RESET%^male");
    set_long("This drow is weak looking, simply used to fulfill the Matron Mother's needs and produce more children of the Zekyrr house.  He has many scars covering her body, about the size of a dragon's claw.");
    set_id(({"drow", "male", "zekyrrmale", "zekyrr male"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment(-500);
    set_gender("male");
    set_class("mage");
    set_subclass("sorceror");
   new(ARM"dragonscaleshirt")->move(this_object());
     force_me("wear shirt");
   new(ARM"dragonscalering")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(400));
    set_spell_chance(25);   
    set_spells(({"mindstab", "mindshock"}));   
}

