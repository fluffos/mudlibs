#include <std.h>
#include <roston.h>
inherit MONSTER;
  int wielded_sword=0; 
void create() {
::create();
    set_name("Snake");
    set_short("Snow Snake");
    set_long("The snake is 7 foot long, he has "
             "white spots all over his brown body.");
    new(WEP"fangs")->move(this_object());
    set_id(({"snake","snow snake"}));
    set_level(35);
    set_race("snake");
    set_body_type("human");
    set_gender("male");
    set_swarm("Snake");
    set_spell_chance(35);
    set_spells( ({ "whirl", }) );            
    set_heart_beat(1); 

::init();
}

void heart_beat()
{
 ::heart_beat();
  if (!this_object()) return;
 if (!wielded_sword)
   {
    this_object()->force_me("wield fangs");
    wielded_sword = 1;
   }
}                                 
