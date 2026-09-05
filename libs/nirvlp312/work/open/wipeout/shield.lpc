#include "/players/fred/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("shield");
  set_short("A small shield");
  set_long(
  "  A small shield made of old wood.\n");
  set_type("shield");
  set_ac(1);
  set_weight(1);
  set_value(100);
}

do_special(owner){
  if(!worn) return;
  if(random(20) < 4)
  {
    write("The shield absorbs some of the attack!\n");
    owner->add_hit_point(random(5));
    return 1;
  }
  return;
}
