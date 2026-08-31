#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
::create();
    set_name("Bear");
    set_short("White Bear");
    set_long("A huge white bear standing six feet tall.");
    new(WEP "claw")->move(this_object());
    force_me("wield claw");
    new(WEP "claw")->move(this_object());
    force_me("wield claw 2");
    set_id(({"bear","white bear"}));
    set_level(35+random(5));
    set_race("bear");
    set_body_type("canine");
    set_swarm("Bear");
    set_gender("male");
    set_class("fighter");
    set_subclass("warrior");
    set_spell_chance(35);
    set_spells( ({ "slash", }) );
}

