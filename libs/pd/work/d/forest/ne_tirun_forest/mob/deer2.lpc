#include <std.h>;

inherit MONSTER;
int ran;
void create() {
  ::create();
  set_name("deer");
  set("id",({"deer"}));
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
  set("short","a large deer");
  set("long","A large male deer with a rack of horns on it's head.");
  set("race","deer");
  set_gender("male");
  set_body_type("equine");
  set("aggressive",4);
}
