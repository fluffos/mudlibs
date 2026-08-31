#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow warrior");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ warrior");
    set_long("Very slender yet muscular, this drow guards the palace of Zolenia.  He is well equipped and ready to guard his city.");
    set_id(({"drow", "guard", "palaceguard", "palace guard", "drow guard"}));
    set_level(55+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_alignment(-500);
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
    set_spells(({"slash", "headbutt"}));   
}

