#include <std.h>
inherit MONSTER;
int ran; 
void create() {
 ::create();
   set_name("orc child");
   set_id(({"child", "orc", "orc child"}));
   set_short("orc child");
   set_long("A child, this young orc only stands around 3 foot tall and has a green yellowish skin.");
   set_gender("male");
   set_race("orc");
   set_body_type("human");
 ran = random(100);
    if (ran < 20) set_level(5); else
    if (ran < 40) set_level(6); else
    if (ran < 60) set_level(7); else
    if (ran < 80) set_level(8); else
    if (ran < 101) set_level(9);
}
