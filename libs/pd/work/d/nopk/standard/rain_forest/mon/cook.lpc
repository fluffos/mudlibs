#include <std.h>
#include <rain.h>
inherit MONSTER;

void create(){
   object ob;
 ::create();
   set_name("cook");
   set_short("A small elven cook");
   set_id(({"elf", "cook", "elven cook"}));
   set_long("This small cook seems to busy himself cooking things.");
   set_level(3);
   set_gender("male");
   set_race("elf");
   set_body_type("human");
   ob = new("/std/food");
   ob->set_short("a loaf of bread");
   ob->set_name("loaf of bread");
   ob->set_id(({ "bread", "loaf", "loaf of bread" }));
   ob->set_strength(10);
   ob->set_weight(1);
   ob->set_long("A warm loaf of bread.");
   ob->move(this_object());
   new(WEA"spatula")->move(this_object());
   this_object()->force_me("wield spatula");
 }
