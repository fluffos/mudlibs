#include <std.h>
inherit MONSTER;
int ran; 
void create() {
 ::create();
   set_name("goblin child");
   set_id(({"child", "goblin", "goblin child"}));
   set_short("goblin child");
   set_long("A child, this young goblin only stands around 2 foot tall and has a green skin.");
   set_gender("male");
  set_race("goblin");
   set_body_type("human");
 ran = random(100);
    if (ran < 20) set_level(5); else
    if (ran < 40) set_level(6); else
    if (ran < 60) set_level(7); else
    if (ran < 80) set_level(8); else
    if (ran < 101) set_level(9);
}
