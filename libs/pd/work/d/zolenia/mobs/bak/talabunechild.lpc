#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("talabune child");
    set_short("%^RESET%^%^YELLOW%^%^BOLD%^Talabune%^RESET%^ child");
    set_long("This young drow boy is fairly strong looking for his age, although he still has some growing up to do to be a formidable opponent.  His eyes are %^YELLOW%^yellow%^RESET%^ with fiery fury.  His white hair is covered in a circle of flames.");
    set_id(({"drow", "child", "talabunechild", "talabune child"}));
    set_level(30+random(6));
    set_race("drow");
    set_body_type("drow");
    set_alignment("-500");
    set("aggressive",30);
    set_gender("male");
    set_class("mage");
    set_subclass("pyromancer");
   new(ARM"flamingshirt")->move(this_object());
     force_me("wear shirt");
   new(WEP"toysword")->move(this_object());
     force_me("wield sword");

    add_money("gold", random(200));
    set_spell_chance(25);   
    set_spells(({"flamewall", "burn"}));   
}

