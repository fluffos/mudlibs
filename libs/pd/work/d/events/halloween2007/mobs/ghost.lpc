
#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_property("no corpse", 1);
  set_undead(1);
  set_die("%^BOLD%^%^WHITE%^The ghost vanishes.%^RESET%^");
  set_name("ghost");
  set_short("a pale ghost");
  set_long("The ghost is translucent, but the body that's visible "
    "looks more like a tattered sheet. It flaps in a breeze you cannot feel.");
  set_gender(({"male","female"})[random(2)]);
  set_race("ghost");
  set_body_type("human");
  set_level(28);
  set_alignment(300);
  set_class("clergy");
  set_subclass("cleric");
  set_spells( ({ "unknit", "pain", "paralyze", "shield me" }) );
  set_spell_chance(40);
  set_skill("healing", 150);
  set_skill("belief", 150);
  set_skill("faith", 150);
  set_skill("attack", 50);
  set_skill("melee", 50);
}

