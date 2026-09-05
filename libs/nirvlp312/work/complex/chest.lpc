/*
 * configurable clonable chest object
 *
 * Chameloid, 9-Sep-96: converted to use of configure() instead of create()
 * Coogan, 05-Sep-97: improved state descriptions and persistence handling
 *
 */

#pragma strong_types

#include <describe.h>
#include <prop/item.h>
#include <persistence.h>

inherit "basic/lockable";
inherit "complex/container";

string short() {
  if (!query_property(P_STATE_DESCRIPTION)) {
    // could be spam a bit, but we want all not properly initialized chests
    log_file("state_description", load_name()+"\n");
  }
  return container::short();
}

private string chest_short() {
  return describe(this_object(), ARTICLE_A);
}

private string chest_long() {
  return ((query_container_long() ||
           "This is " + describe(this_object(),ARTICLE_A) + ".\n") +
          "It is "+ query_open_state_description() + " and " +
          query_lock_state_description() + ".\n");
}

string query_open_description(status in_output) {
  if (in_output) {
    if (query_open())
      return "open";
    else 
      if (!query_lock())
        return "closed"; 
    }
  else  // the state descriptions also cover the states of lock_description
    if (query_lock())
      return "not open\\>|\\<closed\\>|\\<locked";
    else
      if (query_open())
        return "open\\>|\\<not closed\\>|\\<unlocked\\>|\\<not locked";
      else
        return "not open\\>|\\<closed\\>|\\<unlocked\\>|\\<not locked";
}

string query_lock_description(status in_output) {
  if (in_output)
    if (query_lock())
      return "locked";
    else
      if (!query_open())
        return "unlocked";
}

void create() {
  lockable::create();
  container::create();
#if 1  // Coogan, 01-Dec-01. Or better in populate()?
  if (query_default_open())
    open();
  else
    close();
  if (query_default_locked())
    lock();
  else
    unlock();
#endif
}

// added following function which has no real effect right now but which
// is more proper than without.  Alfe 97-Jun-20
void refresh() {
  lockable::refresh();
  container::refresh();
}

void
configure()
{
  container::configure();
  set_persistence("complex/chest", PER_KEEP_VARS, ({
    PER_PERM_VAR + "open_state",  // PER_PERM_VARs added, Coogan, 22-Mar-98
    PER_PERM_VAR + "lock_state",
    }));
  set_short(#'chest_short);
  set_long(#'chest_long);
  remove_persistence(({ "set_short", "set_long" }));
  add_to_property(P_STATE_DESCRIPTION, ({ 0, "query_open_description" }));
  add_to_property(P_STATE_DESCRIPTION, ({ 0, "query_lock_description" }));
  set_id(({ "chest" }));
  set_name("chest");
  set_value(200);
  set_encumbrance(5000);
  set_max_encumbrance(20000);
}

status
insert_objects()
{
  return query_open();
}

int apply_action(string action, int level, mixed args) {
  return
    lockable::apply_action(action, level, args) ||
    container::apply_action(action, level, args);
}
