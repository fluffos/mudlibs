#include <std.h>
#include <roston.h>
inherit MONSTER;
  
void create() {
::create();
    set_name("Hunter");
    set_short("Dwarven Hunter");
    set_long("A weathered dwarf skilled in the art of hunting.");
    set_id(({"hunter","dwarven hunter"}));
    set_level(36+random(7));
    add_money("gold", (25+random(25)));
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    set_class("fighter");
    set_subclass("ranger");
    set_spell_chance(35);
    set_spells( ({ "whirl", }) );
    new(ARM"h_shield")->move(this_object());
    force_me("wear shield");
    new(ARM"armour")->move(this_object());
    force_me("wear armour");
    new(WEP"axe")->move(this_object());
    force_me("wield axe");
}
