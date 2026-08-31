
#include <std.h>
#include <ridarin.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("elven sentinel");
  set_id( ({ "elf", "elven sentinel", "sentinel", "elf sentinel" }) );
  set_short("an elven sentinel");
  set_long(
    "A tall elf, and rather sturdy looking. His hair is cropped short, "
    "and he seems to be ready to protect something."
  );
  set_gender("male");
  set_race("elf");
  set_body_type("human");
  set_aggressive(15+random(6));
  set_class("fighter");
  set_subclass("warrior");
  set_level(48+random(2));
  set_spell_chance(40);
  set_spells( ({ "slash", "impale", "warblade", "whirl", "parry" }) );
  set_inventory( ([
    RIDARIN_WEAPONS+"sword" : "wield sword",
    RIDARIN_WEAPONS+"spear" : "wield spear",
    RIDARIN_ARMOURS+"leatherarmour" : "wear armour",
    RIDARIN_ARMOURS+"leggings" : "wear leggings",
  ]) );
}

