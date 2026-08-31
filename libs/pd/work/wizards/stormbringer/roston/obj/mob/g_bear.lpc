#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("Bear");
    set_short("A Giant Bear");
    set_long("This giant bear stands ten feet tall and has a dark brown coat of fur.");
    set_id(({"bear","giant bear"}));
    set_level(40+random(5));
    set_race("bear");
    set_body_type("canine");
    set_gender("male");
    set_class("fighter");
    set_subclass("warrior");
    set_spell_chance(35);
    set_spells( ({ "slash", }) );
    new(WEP"g_claw")->move(this_object()); 
    force_me("wield claw");
}