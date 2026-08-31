#include <std.h>
#include <roston.h>
inherit MONSTER;
  int wielded_sword=0;
void create() {
::create();
    set_name("Bear");
    set_short("Polar Bear");
    set_long("A huge white bear, that stands 6 feet tall. "
             "He has great white fur, with no spots.");
    new(WEP"claw")->move(this_object());
    new(WEP"claw")->move(this_object());
    set_id(({"bear","polar bear"}));
    set_level(35);
    set_race("bear");
    set_body_type("human");
    set_swarm("Bear");
    set_gender("male");
    set_spell_chance(35);
    set_spells( ({ "slash", }) );
    set_heart_beat(1);                   
 
::init();
}

void heart_beat()
{
 ::heart_beat();
  if (!this_object()) return;
 if (!wielded_sword)
   {
    this_object()->force_me("wield claw");              
      this_object()->force_me("wield claw 2");
    wielded_sword = 1;
    }

}     
