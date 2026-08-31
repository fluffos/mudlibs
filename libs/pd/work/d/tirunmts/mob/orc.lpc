#include <std.h>
inherit MONSTER;
int ran; 
create() {
    ::create();
    set_name("orc");
    set_id( ({ "orc" }) );
    set_short("orc");
    set("aggressive", 10);
 ran = random(100);
    if (ran < 20) set_level(8); else
    if (ran < 40) set_level(9); else
    if (ran < 60) set_level(10); else
    if (ran < 80) set_level(11); else
    if (ran < 101) set_level(12);
    set_long("Standing about 6 foot tall this orc is a yellowish green color and seems to be enjoying a walk.\n");
    set_alignment(-500);
 ran = random(100);
    if (ran < 50) set_gender("female"); else
    if (ran < 101) set_gender("male");
    set_race("orc");
    set_body_type("human");
    set_property("no bump", 1);
}
