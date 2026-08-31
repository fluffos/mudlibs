
#include <std.h>
#include <ridarin.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("elven hunter");
  set_id( ({ "elf", "elven hunter", "hunter", "elf hunter" }) );
  set_short("an elven hunter");
  set_long("This elf is of medium height with bright eyes and dark hair. "
           "His skin is rather tanned for an elf. He appears to be hunting "
	   "small game.");
  set_gender("male");
  set_race("elf");
  set_body_type("human");
  set_aggressive(10+random(6));
  set_class("fighter");
  set_subclass("ranger");
  set_level(37+random(2));
  set_spell_chance(40);
  set_spells( ({ "spear", "impale" }) );
  set_inventory( ([
    RIDARIN_WEAPONS+"spear" : "wield spear",
    RIDARIN_ARMOURS+"jerkin" : "wear jerkin",
    RIDARIN_ARMOURS+"leggings" : "wear leggings",
  ]) );
}

