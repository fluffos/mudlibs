// File copied from /d/forest/mob/coon.c to test a population thing
// --Randalar
#include <std.h>
 
#if 0 // Want to test my monster --Randalar
inherit MONSTER;
#else
inherit "/wizards/randalar/island/std/rmonster";
#endif
int ran; 
void create() {
    ::create();
 set_name("raccoon");
 set_id( ({"raccoon"}) );
 set_short("a raccoon");
 set_long(
 "A medium sized furry animal, grey in color with black rings on it's "
 "tail and a black mask around it's eyes. They have been know to collect shiney objects. "
 );
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7);
    set_level(30);
 set_gender("male");
 set_alignment(35);
 set_body_type("canine");
 set_race("raccoon");
    add_money("gold", random(20));
 set_emotes(9, ({"The raccoon wobbles around."}),0);
  add_friend("raccoon"); // Hope this works... 
}
