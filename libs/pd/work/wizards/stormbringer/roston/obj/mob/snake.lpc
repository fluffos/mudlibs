#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
::create();
    set_name("Snake");
    set_short("Snow Snake");
    set_long("A seven foot long, white snake.");
    new(WEP"fangs")->move(this_object());
    force_me("wield fangs");
    set_id(({"snake","snow snake"}));
    set_level(35+random(5));
    set_race("snake");
    set_body_type("snake");
    set_gender("male");
    set_swarm("Snake");
    set_class("wanderer");
    set_subclass("swashbuckler");
    set_spell_chance(35);
    set_spells( ({ "lunge", }) );             
}                                 
