#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("tunnel guard");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ tunnel guard");
    set_long("Very slender yet muscular, this black elf with white hair guards the tunnel inside of the gates that leads to the drow city, Zolenia..");
    set_id(({"drow", "guard", "tunnelguard", "drow guard"}));
    set_level(55+random(6));
    set_race("drow");
    set_body_type("drow");
    set_alignment("-500");
    set("aggressive",30);
    set_gender("male");
    set_class("fighter");
    set_subclass("ranger");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
    add_money("gold", random(1000));
    set_spell_chance(25);   
    set_spells(({"slash", "throw"}));   
}

