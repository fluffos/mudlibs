#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("vastana male");
    set_short("%^RESET%^%^RED%^%^BOLD%^Vastana%^RESET%^ male");
    set_long("This drow is weak looking, simply used to fulfill the Matron Mother's needs and produce more children of the Vastana house.  His dark skin is covered in blood.");
    set_id(({"drow", "male", "vastanamale", "vastana male"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set_alignment(-500);
    set("aggressive",30);
    set_gender("male");
    set_class("mage");
    set_subclass("sorceror");
   new(ARM"bloodyshirt")->move(this_object());
     force_me("wear shirt");
   new(ARM"bloodyring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(400));
    set_spell_chance(25);   
    set_spells(({"mindstab", "fracture"}));   
}

