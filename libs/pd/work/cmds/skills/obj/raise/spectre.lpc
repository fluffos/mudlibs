// spectre for the raise spell
// a dungeonware.net production
#include <std.h>
#include <dirs.h>
inherit DIR_CLASS_CMDS+"/obj/raise/necro_undead";
void create() {
  ::create();
  set_name("spectre");
  set_id( ({ "spectre undead", "spectre", "undead" }) );
  set_gender("male");
  set_short("a spectre");
  set_level(25);
  set_long("The spectre is the incorporeal form of life after death.  It "
    "is transparent, and ghastly in appearance.");
  set_body_type("human");
  set_alignment(-700);
  set_race("undead");
  set_class("clergy");
  set_subclass("cleric");
  set_skill("belief",25*4);
  set_skill("healing",25*4);
  set_spell_chance(25);
  set_spells( ({ "pain", "shield" }) );
  set_property("no_corpse", 1);
  set_die( "The spectre %^RED%^dissipates%^RESET%^ before you." );
  set_return("dissipates.");
  set_raise_msg("fades out of the shadows before you!");
}
