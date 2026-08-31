#include <std.h>
inherit MONSTER;
int ran; 
create() {
    ::create();
    set_name("netherman wanderer");
    set_id( ({ "netherman", "wanderer", "netherman wanderer" }) );
    set_short("netherman wanderer");
    set("aggressive", 20);
    ran = random(100);
    if (ran < 20) set_level(15); else
    if (ran < 40) set_level(16); else
    if (ran < 60) set_level(17); else
    if (ran < 80) set_level(18); else
    if (ran < 101) set_level(19);
    set_long("An ugly netherman, standing about 6 foot tall, wearing many patches on his clothes.\n");
    set_alignment(-1500);
    set_gender("male");
    set_class("mage");
    set_race("netherman");
    set_money("gold",250);
    set_mp(350);
    set_spell_chance(35);
    set_spells( ({ "missile", "shock" }) );
    set_body_type("netherman");
    set_property("no bump", 1);
}

