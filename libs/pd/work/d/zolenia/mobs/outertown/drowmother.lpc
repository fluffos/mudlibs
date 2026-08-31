#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow");
    set_short("%^RESET%^a %^BLACK%^%^BOLD%^drow%^RESET%^ mother");
    set_long("This is a fragile drow mother, who seems to have been banished from Zolenia for some sort of wrong doing.  Her body is covered in scars.");
    set_id(({"drow", "drow mother", "mother", "woman"}));
    set_level(36+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("female");
    set_class("mage");
    add_money("gold", random(300));
    set_subclass("necromancer");
    set_spell_chance(25);   
    set_spells(({"shadowburst", "disease"}));   
}
