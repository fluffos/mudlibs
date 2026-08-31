#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"
#define DULL_BRASS_ID "dull_brass_armour_piece"
#define CRYSTAL_ID "crystal_armour_piece"
#define DULL_BRASS_NUM 8

inherit ARMOUR;

string state = "";

void toggle_brass(object);
void toggle_crystal(object);
void check_on(object);
void check_off(object);

void create() {
  ::create();
  toggle_brass(0);
  set_type("bracers");
  set_limbs( ({ "right arm", "left arm" }) );
  set_weight(20);
  set_curr_value("gold", 7);
  set_post_wear_func( (: check_on :) );
  set_post_remove_func( (: check_off :) );
}

string query_state() { return state; }

void toggle_brass(object tp) {
  if (state == "brass") return;

  set_name("brass bracers");
  set_id(({ "bracers", "brass bracers", "dull brass bracers", DULL_BRASS_ID }));
  set_short("dull brass bracers");
  set_long("Bracers made of brass, they are very dull and old.");
  set_ac(1);
  
  if (state == "crystal") {
    message("info", COL+"Your crystal bracers transform into brass!"+RES, tp);
    message("info", COL+tp->query_cap_name()+"'s crystal bracers transform "
      "into brass!"+RES, environment(tp), tp);
  }

  state = "brass";
}

void toggle_crystal(object tp) {
  if (state == "crystal") return;

  set_name("crystal bracers");
  set_short(COL+"crystal bracers"+RES);
  set_long("Bracers made of solid crystal, they reflect any light that shines on them.");
  set_id(({ "bracers", "crystal bracers", CRYSTAL_ID }));
  set_ac(4);

  if (state == "brass") {
    message("info", COL+"Your brass bracers transform into crystal!"+RES, tp);
    message("info", COL+tp->query_cap_name()+"'s brass bracers transform "
      "into crystal!"+RES, environment(tp), tp);
  }

  state = "crystal";
}

void check_on(object tp) {
  object *search = filter(all_inventory(tp), (:
    $1->id(DULL_BRASS_ID) && $1->query_worn()
  :) );
  if (sizeof(search) == DULL_BRASS_NUM)
    search->toggle_crystal(tp);
}

void check_off(object tp) {
  object *search = filter(all_inventory(tp), (:
    $1->id(CRYSTAL_ID)
  :) );
  if (sizeof(search))
    search->toggle_brass(tp);
}

int query_auto_load() {
  return (this_player() && this_player()->query_level() >= 20);
}

