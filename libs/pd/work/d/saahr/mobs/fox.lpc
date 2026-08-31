
#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("fox");
  set_race("fox");
  set_body_type("quadruped");
  set_gender(({"male","female"})[random(2)]);
  
  set_class("animal");
  set_subclass("fast");

  switch (random(5)) {
    case 0 :  case 1 :
      set_id(({"small fox"}));
      set_short("a small fox");
      set_long("The fox is small and fast. It looks around, searching for "
        "hares to eat.");
      set_level(18);
    break;
    case 2 :  case 3 :
      set_id(({"lean fox"}));
      set_short("a lean fox");
      set_long("A quick little fox with brown fur and a big fluffy tail.");
      set_level(19);
    break;
    case 4 :  default :
      set_id(({"fox","fox cub"}));
      set_short("a fox cub");
      set_long("This little brown fox looks as if it shouldn't be outside "
        "of its den just yet. It looks around fearfully.");
      set_level(7);
    break;
  }
  set_id( query_id() + ({ "fox_kill_id" }) );
}
    
