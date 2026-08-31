#include <std.h>
#include <roston.h>
inherit MONSTER;
  
void create() {
::create();
    set_name("Stoneworker");
    set_short("Dwarven Stoneworker");
    set_long("A burly dwarven stone worker.");
    set_id(({"stoneworker","dwarven stoneworker"}));
    set_level(22+(random(8));
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    set_class("fighter");
    set_subclass("warrior");
    set_spell_chance(30);
    set_spells( ({ "whirl" }) );
    new(ARM"armour")->move(this_object());
    force_me("wear armour");
    new(WEP"swhammer")->move(this_object());
    force_me("wield hammer");
    new(WEP"chisel")->move(this_object());
    force_me("wield chisel");
}