#include <std.h>
inherit MONSTER;
int ran; 
void create() {
 ::create();
   set_name("tak'dar elder");
   set_id(({"tak'dar elder", "tak'dar", "takdar", "elder"}));
   set_short("tak'dar elder");
   set_long("Standing at around 5 foot, this wild Tak'Dar elder seems to be wise and experienced. Having only a single eye, large ears, and unkept hair, the Tak'dar seem to be nothing more than cave dwelling people.");
   set_gender("male");
   set_race("tak'dar");
   set_body_type("human");
 ran = random(100);
    if (ran < 20) set_level(9); else
    if (ran < 40) set_level(10); else
    if (ran < 60) set_level(11); else
    if (ran < 80) set_level(12); else
    if (ran < 101) set_level(13);
}
