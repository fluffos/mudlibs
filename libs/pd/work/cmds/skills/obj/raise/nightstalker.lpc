// nightstalker for the raise spell
// a dungeonware.net production
#include <std.h>
#include <dirs.h>
inherit DIR_CLASS_CMDS+"/obj/raise/necro_undead";
void create() {
  ::create();
  set_name("nightstalker");
  set_id( ({ "nightstalker undead", "nightstalker", "undead" }) );
  set_gender("male");
  set_short("a nightstalker");
  set_level(35);
  set_long("The nightstalker is a large black form of evil and vileness. Once in life this form might have been a giant of some kind but now it serves evil and stalks the living.");
  set_body_type("demon");
  set_alignment(-700);
  set_race("undead");
  set_class("clergy");
  set_subclass("kataan");
  set_skill("magic attack", 50);
  set_skill("faith", 50);
  set_skill("summoning", 50);
  set_spell_chance(25);
  set_spells( ({ "darkmist", "shadowburst", "fear" }) );
  set_property("no_corpse", 1);
  set_die( "The nightstalker %^RED%^dissipates%^RESET%^ before you." );
  set_return("dissipates.");
  set_raise_msg("fades out of the shadows before you!");
}
