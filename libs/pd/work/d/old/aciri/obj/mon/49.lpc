#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("hero");
   set_short("a solitary hero");
   set_long("The hero has infiltrated the Acirian troops, and continually heads "
     "further and further into the tower, destroying evil along the way. " 
     "The hero or heroine as it may be battles in solitude, but the group "
     "of heros invaded the tower together.");
   set_level(44);
   set_id(({ "hero", "heroine" }));
   set_auto(0);
   set_race("human");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"bplate");
   make(ARM"herohelm");
   command("wear all");
}
