#include <std.h>
#include <damage_types.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("ice golem");
    set_short("an ice golem");
    set_long("This huge golem is made entirely of gleaming white ice. Its massive limbs stand "
      "like huge white treetrunks. Reflecting light dances upon its body as it moves. "); 
    set_id(({"ice", "golem", "ice golem"}));
    set_level(50);
    set_race("golem");
    set_body_type("human");
    set_gender("neuter");
    set_class("clergy");
    set_subclass("druid");
    set_spell_chance(45);
    set_spells( ({"freeze"}) );
    set_property("no_corpse", 1);
    set_resistance(DAMAGE_ICE, 100);
    set_die( "The golem %^BOLD%^%^BLUE%^shatters%^RESET%^ before you." );
    new("/d/helgrath/items/g_tooth")->move(this_object());
}
