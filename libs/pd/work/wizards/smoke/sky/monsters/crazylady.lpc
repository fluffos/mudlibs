#include <std.h>
#include <cp.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("crazy dwarven lady");
  set_id(({ "dwarf", "lady", "crazy lady", "crazy dwarven lady" }));
  set_short("a crazy dwarven lady rambling to anyone who listens");
  set_long("This dwarf goes on and on and on about "
   "nothing worth listening to. She looks dirty "
   "and grimy, as if she's been living under "
   "a bridge for a while.");
  set_race("dwarf");
  set_class("mage");
  set_subclass("sorceror");
  set_body_type("dwarf");
  set("aggressive", 75);
  set_spell_chance(80);
  set_spells( ({ "mindlance", "amnesia", "suppress", "fracture", }) );
  set_gender("female");
  set_level(78);
  set_emotes(10, ({"%^CYAN%^The crazy lady exclaims:%^RESET%^ The "
    "end is near! Sell everything you have and move "
    "to Merkkirri! The Gnolls can save us!",
    "%^CYAN%^The crazy lady says:%^RESET%^ I hope I fed my "
    "cats before I left the house....",
    "The crazy lady glares at you wide-eyed. \n"
    "%^CYAN%^The crazy lady exclaims:%^RESET%^ Nulvect "
    "and I are going to get married.",
    "The crazy lady hacks up a lung."}), 0);
}
