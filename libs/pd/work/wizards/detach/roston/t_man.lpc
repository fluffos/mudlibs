#include <std.h>
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
    new("/wizards/detach/roston/axe")->move(this_object());
    new("/wizards/detach/roston/axe")->move(this_object());
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
 
 if (!wielded_sword)
   {                    
    this_object()->force_me("wield axe");
    this_object()->force_me("wield axe 2");
    wielded_sword = 1;
   }
}
                                   
