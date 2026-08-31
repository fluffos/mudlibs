#include <std.h>
#include <roston.h>

inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("wizard");
    set_short("Snow Wizard");
    set_long("This Wizard is the man of the snow, he lives down "
             "in the cavern cause the people of town where going "
             "to kill him.");
    set_id(({"wizard","snow wizard"}));
    set_alignment(1500);
    set_level(35);
    set_skill("magic attack" ,150);
    set_skill("nature", 150);
    set_class("mage");
    set_subclass("wizard");
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");     
    set_spell_chance(35);
    set_spells( ({ "manamissile", "pillar", "coalesce", "fog" }) );
    set_heart_beat(1);          
     new(ARM "w_robes")->move(this_object()); 
}
void heart_beat()
{
 ::heart_beat();
  if (!this_object()) return;
 if (!wielded_sword)
   {
    this_object()->force_me("wear robes");
    wielded_sword = 1;
   }

}        
