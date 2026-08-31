#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ tower guard");
    set_long("Standing tall and looking mean, this drow is guarding the archer tower outside of the city.");
    set_id(({"drow", "guard", "tower guard"}));
    set_level(55+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_class("fighter");
    set_subclass("warrior");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
    add_money("gold", random(1000));
    set_spell_chance(25);   
    set_spells(({"slash", "whirl"}));   
}

