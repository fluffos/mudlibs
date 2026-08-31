#include <std.h>
#include <rain.h>
inherit MONSTER;

void create(){
   ::create();
   set_name("elf");
   set_short("An Elven warrior");
   set_id(({"elf", "warrior", "elven warrior"}));
   set_long("This elven warrior has mud streaks across his face and a very sharp spear in his hand.");
   set_level(7);
   set_class("fighter");
   set_gender("male");
    set_race("elf");
    set_body_type("elf");
   set_spells(({"whirl"}));
   set_spell_chance(10);
   set_heart_beat(1);
   new(WEA"aspear")->move(this_object());
   this_object()->force_me("wield spear");
 }
