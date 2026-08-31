// nightmare for the summon spell
// a dungeonware.net collaboration with
// -(Inferno)-
#include <std.h>
#include <dirs.h>
inherit DIR_CLASS_CMDS+"/obj/summon/kataan_demon";

int check_ride(object);

void create() {
  ::create();
  set_name("nightmare");
  set_id( query_id() + ({ "nightmare" }) );
  set_gender("female");
  set_short("a nightmare");
  set_level(9);
    set_long("The nightmare is a huge jet black mount. She seems "
      "to absorb all the light around her. Evil eminates "
      "from her powerful form.");
  set_body_type("horse");
  set_alignment(-700);
  set_class("fighter");
  set_subclass("antipaladin");
  set_spell_chance(10);
  set_spells( ({ "rush" }) );
  set_skill("attack", 12*6);
  set_rideable(1);
  set_rideallow( (: check_ride :) );
}

int check_ride(object ob) {
  if (!query_owner() || ob != query_owner()) {
    message("emote", query_cap_name()+" snorts and kicks at you.", ob);
    return 0;
  }
  return 1;
}
