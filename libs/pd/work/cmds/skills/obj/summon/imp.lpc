// imp for the summon spell
// a dungeonware.net collaboration with
// -(Inferno)-
#include <std.h>
#include <dirs.h>
inherit DIR_CLASS_CMDS+"/obj/summon/kataan_demon";
void create() {
  ::create();
  set_name("imp");
  set_id( query_id() + ({ "imp" }) );
  set_gender("female");
  set_short("a small, black imp");
  set_level(9);
  set_long("The imp's leathery black wings are pressed up against "
    "its back. She has burning red eyes and long, sharp "
    "claws. Her skin is as black as oil, her gaze piercing.");
  set_body_type("imp");
  set_alignment(-700);
  set_subclass("wizard");
  set_class("mage");
  set_spell_chance(90);
  set_spells( ({ "magicmissile", "shockwave",  "tremble" }) );
}
