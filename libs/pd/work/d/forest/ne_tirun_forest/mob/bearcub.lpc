#include <std.h>

inherit MONSTER;
int ran;
void create() {
::create();
    set_name("bear");
    set_short("a bear cub");
    set_long("A small brown bear. It looks very young.");
    set_id(({"bear"}));
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7);
    set_race("bear");
    set_body_type("canine");
    set_gender("male");
    set_spell_chance(35);
    set_spells( ({ "slash", }) );
}

