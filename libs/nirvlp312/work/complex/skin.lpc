/*
 * This file provides a generic skin/fur.
 * Coogan, 27-Nov-2002.
 *
 */

#pragma strong_types

#include <prop/item.h>
#include <libs.h>
#include <message.h>
#include <persistence.h>
#include <size.h>

inherit "basic/decay";
inherit "basic/math";
inherit "complex/item";

private string race, *ids, size_desc;

string query_race() {
  return race;
}

void set_race(string r) {
  if (LIB_RACE->query_is_known_race(r))
    race = r;
}

void rot_away() {
  object t;
  if (item::short()) {
    if (t = find_living_environment())
      send_message(({ M_TARGETS, t, M_ME_THE, M_ME_VERB, "rot", " away." }));
    else
      send_message(({ M_ROOM, (: get_room(this_object()) :),
                      M_ME_THE, M_ME_VERB, "rot", " away." }));
  }
  call_out(#'destruct, 0, this_object());
}

private void compute_size_desc() {
  size_desc = LIB_DESCRIBE->size_description(
                (100*query_property(P_AREA_SIZE)) /
                LIB_RACE->compute_area_size(race, SIZE_MEDIUM));
}

void set_size_desc(string desc) {  // should be called by LIB_PERSISTENCE only
  size_desc = desc;
}

string query_size_desc() {
  if (!size_desc)
    compute_size_desc();
  return size_desc;
}

private void compute_ids() {
  if (query_property(P_FUR))
    ids = ({ "fur" });
  else
    ids = ({ "skin" });
  if (race)
    ids += ({ race + " " + ids[0] });
  if (query_property(P_TANNED)) {
    ids += ({ "tanned " + ids[0] });
    if (race)
      ids += ({ "tanned " + ids[1] });
  }
  if (!query_property(P_FUR) && query_property(P_TANNED))
    ids += ({ "leather" });
}

int id(string str) {
  return item::id(str) || member(ids, str) > -1;
}

string* query_id() {
  return ids + (item::query_id() || ({ }));
}

string query_short() {
  if (query_property(P_TANNED)) {
    if (query_property(P_FUR))
      return "a tanned " + (race ? race + " " : "") + "fur";
    return "a piece of " + (race ? race  + " " : "") + "leather";
  }
  if (query_property(P_FUR))
    return describe((race ? race + " " : "") + "fur", ARTICLE_A);
  return describe((race ? race + " " : "") + "skin", ARTICLE_A);
}

string short() {
  if (query_decaying() && !query_property(P_STATE_DESCRIPTION) && !random(10))
    log_file("state_description", load_name(this_object())+"\n");
  if (query_decayed())
    if (find_call_out("rot_away") == -1) {
      call_out("rot_away", to_int(60 * gauss_random()));
      set_persistence(PER_NO_PERSISTENCE);
    }
  return query_short();
}

varargs string query_long(string str) {
  string res;
  res = capitalize(describe(this_object())) + ".";
  if (!query_race())
    return res + ".\n";
  return res + " It is of " + (query_size_desc() == SIZE_DESC_MEDIUM
                ? "medium" : query_size_desc()) + " size.\n";
}

void remove_property(string prop) {
  item::remove_property(prop);
  (prop == P_FUR || prop == P_TANNED) && compute_ids();
}

varargs void set_property(string prop, mixed value) {
  item::set_property(prop, value);
  (prop == P_FUR || prop == P_TANNED) && compute_ids();
  if (prop == P_TANNED) {
    set_decay_rate(0);
    remove_property(P_STATE_DESCRIPTION);
  }
}

// this function is for easier configuring
varargs void configure_skin(string race, mixed area_size) {
  string key;
  race && set_race(race);
  if (!query_race())
    return raise_error("Unknown race given to configure_skin()!\n");
  if (!area_size)
    area_size = SIZE_MEDIUM;
  if (intp(area_size)) {  // an absolute value
    set_property(P_AREA_SIZE, area_size);
    compute_size_desc();
  }
  else if (stringp(area_size)) {  // macros of <size.h>
    set_property(P_AREA_SIZE, LIB_RACE->compute_area_size(race, area_size));
    size_desc = LIB_DESCRIBE->size_description(area_size);
  }
  else if (pointerp(area_size)) {  // ({ length, width })
    set_property(P_AREA_SIZE, area_size[0] * area_size[1]);
    compute_size_desc();
  }
  else
    return raise_error("Invalid argument 2 for configure_skin()!\n");
  LIB_RACE->configure_object(this_object());
  compute_ids();
}

void configure() {
  item::configure();
  set_persistence(__FILE__, PER_KEEP_VARS,
                  ({ ({ "short", "set_short", "query_real_short" }),
                     ({ "long",  "set_long",  "query_real_long"  }),
                     ({ "id",    "set_id",    "query_real_id"    }),
                     "race", "size", "size_desc" }) +
                  decay::query_persistent_variables());
  // no set_name()
  set_property(P_SKIN);
  set_short("a skin");
  set_id(0);              // will be overwritten by LIB_RACE resp. persistence
  set_encumbrance(2000);  // will be overwritten by LIB_RACE resp. persistence
  set_decay_stages(5);
  set_decay_descriptions(({ "rotten", "old", "usable", "usable", "fresh" }));
  set_decay_rate(14000 + to_int(1000.0 * gauss_random()));  // around 4 hours
  // set default values, Coogan, 12-Aug-2003
  set_race("animal");
  set_property(P_AREA_SIZE, 1000);
  size_desc = "normal";
  compute_ids();
}

void notify_move(object from, mixed to) {
  if (!query_property(P_TANNED))
    if (decay::start_decaying(from, to)) {
      add_to_property(P_STATE_DESCRIPTION,
                      ({ 0, "query_decay_state_description" }));
    }
}

