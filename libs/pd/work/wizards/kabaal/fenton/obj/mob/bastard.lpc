#include <std.h>
#include <fenton.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("bastard");
   set_short("A Little Bastard");
   set_id(({"bastard", "little bastard"}));
   set_long("This little kid is quite the bastard.  He spends his free time vandalizing "
            "anything within the reach of his spraycan.");
  set_class("mage");
  set_subclass("wizard");   
  set_level(20);
    set_spell_chance(50);    
    set_spells(({"bolt", "missile"}));
   set_gender("male");
   set_race("leprechaun");
   set_heart_beat(1);
   set_body_type("human");
    add_money("gold", 150);
   new("/wizards/kabaal/fenton/obj/wep/can")->move(this_object());
   new("/wizards/kabaal/fenton/obj/wep/can")->move(this_object());
   this_object()->force_me("wield can");
   this_object()->force_me("wield can 2");
 }

void heart_beat()
{
 ::heart_beat();
 i++;
 if (i > 10) {
    i = 5;
    this_object()->force_me("emote makes sure the coast is clear.");
    this_object()->force_me("emote spray paints a letter.");
    this_object()->force_me("emote grins like the little bastard that he is.");
   }
}
