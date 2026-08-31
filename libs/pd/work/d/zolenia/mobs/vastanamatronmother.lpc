#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("vastana matron mother");
    set_short("%^RESET%^%^RED%^Vastana%^RESET%^ Matron Mother");
    set_long("The Vastana Matron Mother is the largest of the Vastana house.  She is very strong and agile looking, and a very formidable opponent.  Her dark skin is covered in blood.");
    set_id(({"drow", "mother", "vastanamatronmother", "vastana mother", "matron mother"}));
    set_level(115+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment(-1200);
    set_gender("female");
    set_class("fighter");
    set_subclass("antipaladin");
   new(WEP"bloodyblade")->move(this_object());
     force_me("wield blade");
   new(WEP"bloodyblade")->move(this_object());
     force_me("wield blade");
   new(ARM"bloodyhelm")->move(this_object());
     force_me("wear helm");
   new(ARM"bloodyboots")->move(this_object());
     force_me("wear boots");
   new(ARM"bloodygloves")->move(this_object());
     force_me("wear gloves");
   new(ARM"bloodyarmour")->move(this_object());
     force_me("wear armour");
   new(ARM"bloodyring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(1000));
    set_spell_chance(25);   
    set_spells(({"slash", "shadowburst"}));   
}

