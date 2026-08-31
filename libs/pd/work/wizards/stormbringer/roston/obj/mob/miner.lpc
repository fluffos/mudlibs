#include <std.h>
#include <roston.h>
inherit MONSTER;
  
void create() {
::create();
    set_name("Miner");
    set_short("Dwarven Miner");
    set_long("A short dirty dwarf.");
    set_id(({"miner","dwarven miner"}));
    set_level(25+(random(8));
    add_money("gold", (25+random(25)));
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    set_class("fighter");
    set_subclass("warrior");
    set_spell_chance(30);
    set_spells( ({ "hack" }) );
    new(ARM"armour")->move(this_object());
    force_me("wear armour");
    new(WEP"pickaxe")->move(this_object());
    force_me("wield axe");
}