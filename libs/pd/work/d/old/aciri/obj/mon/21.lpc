#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("berserker");
   set_short("a raging berserker");
   set_long("A tall, strong, and generally powerful half-giant "
     "berserker. The berserker has learned how to channel all its "
     "anger and power into a furious attack.");
   set_level(38);
   set_id(({ "berserker", "half-giant", "giant" }));
   set_auto(21);
   set_race("half-giant");
   set_body_type("human");
   set_class("fighter");
   set_spell_chance(25);
   set_spells(({ "bloodlust" }));
  if (random(10) >= 7)
   set_gender("female");
  else
   set_gender("male");
}
