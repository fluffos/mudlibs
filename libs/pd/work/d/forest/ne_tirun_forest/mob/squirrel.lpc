#include <std.h>

inherit MONSTER;
int ran;
void create() {
    ::create();
    set_name("squirrel");
    set_id ( ({"squirrel"}) );
    set_short("a small squirrel");
    set_long("The squirrel is a small brown rodent with a large bushy tail.");
    set_gender("female");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
    set_race("squirrel");
    set_body_type("feline");
    add_money("gold", random(10));
}
