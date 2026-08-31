#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("giant");
    set_short("a %^RED%^%^BOLD%^red crystal%^RESET%^ giant");
    set_long("This large giant is completely crystalline, you can see straight through him.  The crystal is many shades of %^RED%^red %^RESET%^and %^YELLOW%^yellow%^RESET%^, creating an illusion of fire..");
    set_id(({"giant", "crystal giant"}));
    set_level(55);
    set_race("giant");
    set_body_type("giant");
    set("aggressive",30);
    set_gender("male");
    set_class("mage");
    add_money("gold", random(300));
    set_subclass("pyromancer");
    set_spell_chance(25);   
    set_spells(({"inferno", "fireball"}));   
}
