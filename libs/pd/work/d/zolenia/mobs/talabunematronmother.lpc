#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("talabune matron mother");
    set_short("%^RESET%^%^YELLOW%^Talabune%^RESET%^ Matron Mother");
    set_long("The Talabune Matron Mother is the largest of the Talabune house.  She is very strong and agile looking, and a very formidable opponent.  Her white hair is covered in a circle of flames.");
    set_id(({"drow", "mother", "talabunematronmother", "talabune mother", "matron mother"}));
    set_level(115+random(6));
    set_race("drow");
    set_alignment(-1200);
    set_body_type("drow");
    set("aggressive",30);
    set_gender("female");
    set_class("mage");
    set_subclass("pyromancer");
   new(ARM"flaminghelm")->move(this_object());
     force_me("wear helm");
   new(ARM"flamingboots")->move(this_object());
     force_me("wear boots");
   new(ARM"flaminggloves")->move(this_object());
     force_me("wear gloves");
   new(ARM"flamingarmour")->move(this_object());
     force_me("wear armour");
   new(ARM"flamingring")->move(this_object());
     force_me("wear ring");
   if(random(100) < 10)
   new(OBJ"flamingbag")->move(this_object());

    add_money("gold", random(1000));
    set_spell_chance(25);   
    set_spells(({"scorch", "flamebraid"}));   
}

