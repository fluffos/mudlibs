
#include <std.h>
#include <fenton.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("zombie");
   set_short("Zombie");
   set_id(({"zombie"}));
   set_long("These zombies protect their lord, Isbar the powerful necromancer
with their lives");
  set_class("mage");
  set_subclass("wizard");   
  set_level(20);
    set_spell_chance(25);    
    set_spells(({"missile"}));
   set_gender("male");
   set_race("zombie");
   set_heart_beat(1);

   set_body_type("human");
    add_money("gold", 17);
 }
void heart_beat()
{
 ::heart_beat();
 i++;
 if (i > 10) {
    i = 5;
    this_object()->force_me("emote groans loudly.");
   }
}
