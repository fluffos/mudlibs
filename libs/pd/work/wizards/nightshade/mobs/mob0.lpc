#include <std.h>

inherit UNDEAD;

void create() {
  ::create();
  set_short("A ghost");
  set_long("The ghost hovers in the air silently.");
  set_body_type("human");
  set_id(({"ghost", "QOmonster"}));
  set_race("ghost");
  if(random(2) == 0)
    set_gender("male");
  else
    set_gender("female");
  set_level(2 + random(5));
  set_name("ghost");
}
