#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("wolverine");
    set_short("a %^BLUE%^%^BOLD%^magical%^RESET%^ wolverine");
    set_long("This large wolverine is completely blue, with a glint of fire in his face.  His head is many shades of %^RED%^red %^RESET%^and %^YELLOW%^yellow%^RESET%^, creating an illusion of being on fire..");
    set_id(({"wolverine", "magical giant"}));
    set_level(47+random(6));
    set_race("wolverine");
    set_body_type("human");
    set("aggressive",30);
    set_gender("male");
    set_class("mage");
    add_money("gold", random(300));
    set_subclass("pyromancer");
    set_spell_chance(25);   
    set_spells(({"inferno", "fireball"}));   
}
