#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow");
    set_short("%^RESET%^a %^BLACK%^%^BOLD%^drow%^RESET%^ child");
    set_long("This is a small drow child, who seems to have been banished from Zolenia for some sort of wrong doing.  His body is covered in scars.");
    set_id(({"drow", "drow child"}));
    set_level(41);
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_class("mage");
    add_money("gold", random(300));
    set_subclass("necromancer");
    set_spell_chance(25);   
    set_spells(({"shadowburst", "disease"}));   
}

