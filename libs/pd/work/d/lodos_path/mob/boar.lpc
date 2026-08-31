#include <std.h>
inherit MONSTER;
int ran; 
create() {
    ::create();
    set_name("wild boar");
    set_id( ({ "wild boar", "boar", "pig" }) );
    set_short("wild boar");
    set("aggressive", 10);
 ran = random(100);
    if (ran < 20) set_level(12); else
    if (ran < 40) set_level(13); else
    if (ran < 60) set_level(14); else
    if (ran < 80) set_level(15); else
    if (ran < 101) set_level(16);
    set_long("Standing about 2 foot tall this wild pig is all muscle and tusks.\n");
    set_alignment(-500);
    if (ran < 50) set_gender("female"); else
    if (ran < 101) set_gender("male");
    set_race("boar");
    set_body_type("quadrupe");
}
