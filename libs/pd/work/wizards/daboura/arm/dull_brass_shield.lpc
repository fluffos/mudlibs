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
  set_type("shield");
  set_limbs( ({ "right arm", "left arm", "torso", "head" }) );
  set_weight(1);
  set_curr_value("gold", 14);
  set_post_wear_func( (: check_on :) );
  set_post_remove_func( (: check_off :) );
}

string query_state() { return state; }

void toggle_brass(object tp) {
  if (state == "brass") return;

  set_name("brass shield");
  set_id(({ "shield", "brass shield", "dull brass shield", DULL_BRASS_ID }));
  set_short("dull brass shield");
  set_long("A magic shield made of brass, it is very dull and old. "
           "It floats in front of its bearer.");
  set_ac(1);
  
  if (state == "crystal") {
    message("info", COL+"Your crystal shield transforms into brass!"+RES, tp);
    message("info", COL+tp->query_cap_name()+"'s crystal shield transforms "
      "into brass!"+RES, environment(tp), tp);
  }

  state = "brass";
}

void toggle_crystal(object tp) {
  if (state == "crystal") return;

  set_name("crystal shield");
  set_short(COL+"crystal shield"+RES);
  set_long("A magic shield made of solid crystal, it reflects any light that shines on it. "
           "It floats in front of its bearer.");
  set_id(({ "shield", "crystal shield", CRYSTAL_ID }));
  set_ac(6);

  if (state == "brass") {
    message("info", COL+"Your brass shield transforms into crystal!"+RES, tp);
    message("info", COL+tp->query_cap_name()+"'s brass shield transforms "
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

