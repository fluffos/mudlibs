
#include <std.h>
#include <h2k7.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("scarecrow");
  set_short("a ragged scarecrow");
  set_long("This scarecrow has straw sticking out of his sleeves "
    "and around his neck. His eyes are made of large buttons, but "
    "he holds a pitchfork and is somehow moving.");
  set_race("scarecrow");
  set_body_type("human");
  set_gender("male");
  set_level(24);
  set_class("clergy");
  set_subclass("kataan");
  set_spells( ({ "impale", "fear" }) );
  set_spell_chance(30);
  set_alignment(-400);
  new(H2K7ITEMS"pitchfork")->move(this_object());
  command("wield pitchfork");
}
