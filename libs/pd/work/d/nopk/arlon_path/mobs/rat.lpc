#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("rat");
   if (random(10) > 5)
     {
      set_short("fat rat");
      set_level(random(5)+9);
     }
    else 
     { 
      set_short("small rat");
      set_level(random(5)+6);
     }
   set_race("rat");
   set_body_type("feline");
if (random(10) > 5)
     {
      set_gender("female");
     }
    else 
     { 
      set_gender("male");
     }
   set_class("animal");
   set_subclass("fast");
   set_id(({ "rat", query_short() }));
   set_long("A small furry rodent.");
}
