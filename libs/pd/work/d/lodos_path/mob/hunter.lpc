#include <std.h>
inherit MONSTER;
int ran; 
void create() {
 ::create();
   set_name("human hunter");
   set_id(({"human", "hunter", "human hunter"}));
   set_short("human hunter");
   set_long("A mid sized human slinking through the forest hunting.");
   set_race("human");
   set_body_type("human");
 ran = random(100);
    if (ran < 20) set_level(15); else
    if (ran < 40) set_level(16); else
    if (ran < 60) set_level(17); else
    if (ran < 80) set_level(18); else
    if (ran < 101) set_level(19);
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
}
