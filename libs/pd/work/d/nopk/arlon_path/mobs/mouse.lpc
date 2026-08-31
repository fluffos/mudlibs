#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("mouse");
   if (random(10) > 5)
     {
      set_short("fat mouse");
      set_level(random(5)+8);
     }
    else 
     { 
      set_short("small mouse");
      set_level(random(5)+5);
     }
   set_race("mouse");
   set_body_type("feline");
   set_gender("male");
    set_class("animal");
    set_subclass("fast");
   set_id(({ "mouse", query_short() }));
   set_long("A small furry rodent.");
}
