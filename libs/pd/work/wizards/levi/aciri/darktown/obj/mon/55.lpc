#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("lancer");
   set_short("a faith lancer");
   set_long("A priest of a lost religion, the lancer uses a lance of spiritual "
     "faith in battle. The priest has spent many years practicing the arts "
     "of the faith.");
   set_level(45);
   set_id(({ "lancer", "faith lancer" }));
   set_auto(3);
   set_race("elf");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   set_skill("faith", 55);
   make(WEA"faith_lance");
   command("wield lance");
   make(ARM"browncape");
   make(ARM"lgloves");
   command("wear gloves");
   command("wear cape");
}
