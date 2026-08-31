#include <std.h>
inherit MONSTER;
int ran; 
void create() {
 ::create();
   set_name("tak'dar");
   set_id(({"tak'dar", "takdar"}));
   set_short("tak'dar");
   set_long("This creature only stands around 5 foot tall, has wild unkept hair, one eye, and wears rudementery cloths.");
   set_gender("male");
   set_race("tak'dar");
   set_body_type("human");
 ran = random(100);
    if (ran < 20) set_level(7); else
    if (ran < 40) set_level(8); else
    if (ran < 60) set_level(9); else
    if (ran < 80) set_level(10); else
    if (ran < 101) set_level(11);
}
