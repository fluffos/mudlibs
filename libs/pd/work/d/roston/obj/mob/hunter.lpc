#include <std.h>
#include <roston.h>
inherit MONSTER;
  
int wielded_sword=0;
void create() {
::create();
    set_name("Hunter");
    set_short("Dwarven Hunter");
    set_long("This is one of the great dwarven hunter. He "
             "stands 6 feet tall, and is very big and strong.");

    set_id(({"hunter","dwarven hunter"}));
    set_level(36);
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    set_spell_chance(35);
    set_spells( ({ "whirl", }) );
    set_heart_beat(1);             
    new(ARM"h_shield")->move(this_object());
    new(ARM"armour")->move(this_object());
      new(WEP"axe")->move(this_object());

}

void heart_beat()
{
 ::heart_beat();
  if (!this_object()) return;
 if (!wielded_sword)
   {
    this_object()->force_me("wield axe");
    this_object()->force_me("wear shield");
    this_object()->force_me("wear armour"); 
    wielded_sword = 1;       
   }

}
