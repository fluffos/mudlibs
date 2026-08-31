#include <std.h>
#include <roston.h>

inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("man");
    set_short("Townsman");
    set_long("This man lives in Roston, he is a very well "
             "cleaned man. He likes to hunt with his giant "
             "Axe.");
    set_id(({"man", "townsman", "dwarf"}));
    set_level(25);
    new(WEP"axe")->move(this_object());

    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    set_heart_beat(1);
}                                    
void init()
{
 ::init();
}

void heart_beat()
{
 ::heart_beat();

  if (!this_object()) return;
 
 if (!wielded_sword)
   {                    
    this_object()->force_me("wield axe");

    wielded_sword = 1;
   }
}
                                   
