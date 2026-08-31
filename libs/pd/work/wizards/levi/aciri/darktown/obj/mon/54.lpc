#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("wasp");
   set_short("a monsterous wasp");
   set_long("The wasp's body has been transformed to a monsterous size. It's "
     "stinger alone is about three feet long, and half a foot thick. It's "
     "long, clear wings beat up and down.");
   set_level(43);
   set_id(({ "wasp", "giant wasp", "monsterous wasp" }));
   set_auto(7);
   set_race("wasp");
   set_body_type("insctwgd");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"stinger");
   command("wield stinger");
}
