#include <std.h>
#include <rain.h>
inherit MONSTER;

void create(){
   ::create();
   set_name("guard");
   set_short("A small elven guard");
   set_id(({"elf", "guard", "elven guard"}));
   set_long("This elven guard is training with a wooden sword for future battles");
   set_level(7);
   set_class("fighter");
   set_gender("male");
   set_race("elf");
   set_body_type("human");
   set_spells(({"whirl"}));
   set_spell_chance(10);
   set_heart_beat(1);
   new(WEA"wsword")->move(this_object());
   this_object()->force_me("wield sword");
 }
