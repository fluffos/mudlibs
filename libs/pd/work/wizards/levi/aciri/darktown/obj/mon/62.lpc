#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("trapper");
   set_short("a shadow trapper");
   set_long("As human trappers set deadly traps for their prey, the shadow "
     "trapper waits and ambushes it's prey. In this case, though, the trapper's "
     "prey is usually human.");
   set_level(44);
   set_id(({ "shadow", "trapper", "shadow trapper" }));
   set_auto(13);
   set_class("fighter");
   set_race("shadow");
   set_body_type("human");
  if (random(5) >= 2)
   set_gender("female");
  else
   set_gender("male");
   set_skill("knife", 50);
   make(WEA"shdagger");
   command("wield dagger");
   make(ARM"shmask");
   command("wear mask");
}
