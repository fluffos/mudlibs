#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("guard");
   set_short("a mounted guard");
   set_long("The guard rides a fierce beast of war into battle. The "
     "mounted guards protect the Acirian tower with their lives. All "
     "the battles for the greed and power of Aciri.");
   set_level(39);
   set_id(({ "guard", "mounted guard" }));
   set_auto(7);
   set_race("orc");
   set_body_type("human");
  if (random(6) >= 5)
   set_gender("female");
  else
   set_gender("male");
   make(MOB"mount");
   command("ride beast");
}
