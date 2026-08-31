#include <std.h>
inherit MONSTER;
int ran; 
void create() {
 ::create();
   set_name("bear cub");
   set_id(({"bear", "cub", "bear cub"}));
   set_short("bear cub");
   set_long("A cub, this young bear only stands around 2 foot tall and looks lost.");
   set_race("bear");
   set_body_type("feline");
 ran = random(100);
    if (ran < 20) set_level(8); else
    if (ran < 40) set_level(9); else
    if (ran < 60) set_level(10); else
    if (ran < 80) set_level(11); else
    if (ran < 101) set_level(12);
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
}
