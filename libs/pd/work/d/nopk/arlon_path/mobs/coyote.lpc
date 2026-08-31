#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("coyote");
   if (random(10) > 5)
     {
      set_short("large coyote");
      set_level(random(5)+10);
     }
    else 
     { 
      set_short("small coyote");
      set_level(random(5)+7);
     }
   set_race("coyote");
   set_body_type("canine");
   set_gender("male");
    set_class("animal");
    set_subclass("strong");
   set_id(({ "coyote", query_short() }));
   set_long("A wild hungry canine.");
}
