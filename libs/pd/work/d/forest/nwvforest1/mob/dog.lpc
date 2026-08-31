#include <std.h>

inherit MONSTER;
int ran;
void create() {
::create();
set_name("dog");
set("id",({"dog", "monster"}));
set_short("a wild dog");
set_long("A medium sized black mongrel. It looks very skittish.");
set_gender("female");
set("race", "canine");
set_body_type("canine");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
}
