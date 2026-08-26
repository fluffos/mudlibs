#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("displacer beast");
  set_id(({"Displacer beast","beast","displacer beast"}));
  set_race("quadruped");
  set_gender("male");
  set("short","Displacer beast");
  set("long","This vaguely puma-like creature is bluish black, its tentacles\n"+
             "are dead black, the horney edges of the tentacles are brownish\n"+
             "yellow, and its eyes glow a hellish green.");
  set_body_type("quadruped");
  set_level(6);
  set_class("fighter");
  set("aggressive", 18);
  set_size(3);
  set_alignment(5);
  set_hd(6,1);
  set_max_hp(52);
  set_hp(query_max_hp());
  set_new_exp(6, "low");
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 25; }
string query_DC_type(){ return "survival"; }

