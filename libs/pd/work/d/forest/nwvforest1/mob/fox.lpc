#include <std.h>

inherit MONSTER;
int ran;
void create() {
::create();
    set_name("fox");
    set_short("a large fox");
    set_long("A medium sized canine with redish fur and a fluffy tail.");
    set_id(({"fox","snowfox"}));
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
    set_race("fox");
    set_body_type("canine");
    set_gender("male");
}                            
