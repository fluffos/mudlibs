#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("wall archer");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ wall archer");
    set_long("Very slender yet muscular, this large black elf with white hair specializes in speed and accuracy.  His mission in life is to guard the walls of the Drow city.");
    set_id(({"drow", "archer", "wallarcher", "wall archer"}));
    set_level(55+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_alignment("-500");
    set_class("fighter");
    set_subclass("ranger");
   new(ARM"darkquiver")->move(this_object());
     force_me("wear quiver");
   new(WEP"darkbow")->move(this_object());
     force_me("wield bow");
   new(WEP"darkbow")->move(this_object());
     force_me("wield bow");
    add_money("gold", random(1000));
    set_spell_chance(25);   
    set_spells(({"shoot", "jab"}));   
}

