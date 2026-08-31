#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow maid");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ maid");
    set_long("This young black elf with white haired teen is, as a sort of punishment, carrying out service as a maid in the academy.");
    set_id(({"drow", "maid", "drowmaid", "drow maid"}));
    set_level(30+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_alignment(-500);
    set_class("fighter");
    set_subclass("warrior");
   new(ARM"darkshirt")->move(this_object());
     force_me("wear shirt");
    add_money("gold", random(200));
    set_spell_chance(25);   
    set_spells(({"jab"}));   
}

