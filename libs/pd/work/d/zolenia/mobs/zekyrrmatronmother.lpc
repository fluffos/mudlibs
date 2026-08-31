#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("zekyrr matron mother");
    set_short("%^RESET%^%^BLUE%^Zekyrr%^RESET%^ Matron Mother");
    set_long("The Zekyrr Matron Mother is the largest of the Zekyrr house.  She is very strong and agile looking, and a very formidable opponent.  She has many scars covering her body, about the size of a dragon's claw.");
    set_id(({"drow", "mother", "zekyrrmatronmother", "zekyrr mother", "matron mother"}));
    set_level(115+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment(-1200);
    set_gender("female");
    set_class("fighter");
    set_subclass("warrior");
   new(WEP"dragonsfury")->move(this_object());
     force_me("wield blade");
   new(WEP"dragonsfury")->move(this_object());
     force_me("wield blade");
   new(ARM"dragonscalehelm")->move(this_object());
     force_me("wear helm");
   new(ARM"dragonscaleboots")->move(this_object());
     force_me("wear boots");
   new(ARM"dragonscalegloves")->move(this_object());
     force_me("wear gloves");
   new(ARM"dragonscalearmour")->move(this_object());
     force_me("wear armour");
   new(ARM"dragonscalering")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(1000));
    set_spell_chance(25);   
    set_spells(({"slash", "warblade"}));   
}

