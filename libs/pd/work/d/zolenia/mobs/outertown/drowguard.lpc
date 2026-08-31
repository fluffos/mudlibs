#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow");
    set_short("%^RESET%^a %^BLACK%^%^BOLD%^drow%^RESET%^ guard");
    set_long("Standing tall and looking mean, this drow guard scouts the forest for escaped prisoners and banished Drow who are still alive.");
    set_id(({"drow", "guard", "drow guard"}));
    set_level(55+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_class("rogue");
    set_subclass("assassin");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
    add_money("gold", random(750));
    set_spell_chance(25);   
    set_spells(({"stab", "jab"}));   
}
