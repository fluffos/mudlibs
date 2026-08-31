#include <std.h>
inherit MONSTER;
int ran; 
create() {
    ::create();
    set_name("orc shaman");
    set_id( ({ "shaman", "orc", "orc shaman" }) );
    set_short("orc shaman");
    set("aggressive", 20);
 ran = random(100);
    if (ran < 20) set_level(11); else
    if (ran < 40) set_level(12); else
    if (ran < 60) set_level(13); else
    if (ran < 80) set_level(14); else
    if (ran < 101) set_level(15);
    set_long("An old Orc, standing about 6 foot tall, wearing many talismans and other items of magic.\n");
    set_alignment(-500);
 ran = random(100);
    if (ran < 50) set_gender("female"); else
    if (ran < 101) set_gender("male");
    set_class("mage");
    set_race("orc");
    set_mp(350);
    set_spell_chance(35);
    set_spells( ({ "missile", "shock" }) );
    set_body_type("human");
    set_property("no bump", 1);
}
