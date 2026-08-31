#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("Valsharess");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^The Valsharess of the Drow");
    set_long("This is the Valsharess of the Drow, the Queen.  She is a very strong looking dark skinned elf, with more muscle and power in a single finger than anyone else in all of Zolenia.  She is adorned in ruby encrusted robes and jewelry, and her white hair is covered in a ruby encrusted helm, which acts as her crown.");
    set_id(({"drow", "priest", "valsharess", "drowvalsharess", "drow valsharess", "the valsharess of the drow", "valsharess of the drow"}));
    set_level(145+random(10));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment(-1500);
    set_gender("female");
    set_class("clergy");
    set_subclass("cleric");
   new(ARM"rubyencrustedrobes")->move(this_object());
     force_me("wear robes");
   new(ARM"rubyencrustedring")->move(this_object());
     force_me("wear ring");
   new(ARM"rubyencrustedbracelet")->move(this_object());
     force_me("wear bracelet");
   new(ARM"rubyencrustedhelm")->move(this_object());
     force_me("wear helm");

    add_money("gold", random(2000));
    set_spell_chance(25);   
    set_spells(({"lifewarp", "pain", "unknit", "shield", "wound"}));   
}

