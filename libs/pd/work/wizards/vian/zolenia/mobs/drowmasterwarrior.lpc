#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow master warrior");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ master warrior");
    set_long("This master warrior, fit and buff, teaches the training warriors to be guards of the city or the palace.");
    set_id(({"drow", "warrior", "master", "drowmaster", "drow master warrior", "drowmasterwarrior", "drowwarrior", "drow warrior"}));
    set_level(90+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_alignment("-500");
    set_class("fighter");
    set_subclass("warrior");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
   new(ARM"darkhelm")->move(this_object());
     force_me("wear helm");
   new(ARM"darkboots")->move(this_object());
     force_me("wear boots");
   new(ARM"darkgloves")->move(this_object());
     force_me("wear gloves");
   new(ARM"darkarmour")->move(this_object());
     force_me("wear armour");
   new(ARM"darkring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(1000));
    set_spell_chance(25);   
    set_spells(({"slash", "warblade"}));   
}

