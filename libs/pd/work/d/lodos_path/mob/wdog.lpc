#include <std.h>
inherit MONSTER;
int ran; 
create() {
    ::create();
    set_name("wild dog");
    set_id( ({ "dog", "wild dog" }) );
    set_short("wild dog");
    set("aggressive", 20);
 ran = random(100);
    if (ran < 20) set_level(18); else
    if (ran < 40) set_level(19); else
    if (ran < 60) set_level(20); else
    if (ran < 80) set_level(21); else
    if (ran < 101) set_level(22);
    set_long("An large dog, standing about 4 foot tall and foaming at the mouth.\n");
    set_alignment(-500);
 ran = random(100);
    if (ran < 50) set_gender("female"); else
    if (ran < 101) set_gender("male");
    set_race("wild dog");
    set_body_type("canine");
    set_property("no bump", 1);
}
