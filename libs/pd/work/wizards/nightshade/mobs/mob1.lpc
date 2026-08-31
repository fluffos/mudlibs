#include <std.h>

inherit UNDEAD;

void create() {
  ::create();
  set_short("%^BOLD%^%^BLACK%^A zombie%^RESET%^");
  set_long("The zombie stumbles about looking for more brains.");
  set_race("zombie");
  set_id(({"zombie", "QOmonster"}));
  set_body_type("human");
  if(random(2) == 0)
    set_gender("male");
  else
    set_gender("female");
  set_level(3 + random(5));
  set_name("zombie");
}
