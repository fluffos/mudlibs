#include <std.h>
inherit MONSTER;
int ran; 

void create() {
 ::create();
   set_name("elk");
   set_id(({ "elk" }));
   set_short("elk");
 ran = random(100);
    if (ran < 20) set_level(13); else
    if (ran < 40) set_level(14); else
    if (ran < 60) set_level(15); else
    if (ran < 80) set_level(16); else
    if (ran < 101) set_level(17);
   set_long("A tall, majetic, cloven beast with a great rack of antlers.");
   set_body_type("hornedequine");
   set_race("elk");
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
}
