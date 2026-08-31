#include <std.h>
inherit MONSTER;
int ran; 
void create() {
 ::create();
   set_name("tak'dar hunter");
   set_id(({"takdar hunter", "tak'dar hunter", "tak'dar", "takdar", "hunter"}));
   set_short("tak'dar hunter");
   set_long("Standing at around 5 foot, this wild Tak'Dar seems to be hunting. Having only a single eye, large ears, and unkept hair, the Tak'dar seem to be nothing more than cave dwelling people.");
   set_race("tak'dar");
   set_body_type("human");
 ran = random(100);
    if (ran < 20) set_level(17); else
    if (ran < 40) set_level(18); else
    if (ran < 60) set_level(19); else
    if (ran < 80) set_level(20); else
    if (ran < 101) set_level(21);
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
}
