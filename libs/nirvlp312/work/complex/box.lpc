/*
 * a generic configurable box
 *
 */

#pragma strong_types

#include <describe.h>
#include <prop/item.h>
#include <persistence.h>

inherit "basic/handle";
inherit "complex/container";

string short()  // Coogan, 22-Mar-98
{
  if (!query_property(P_STATE_DESCRIPTION)) {
    // could be spam a bit, but we want all not properly initialized boxes
    log_file("state_description", load_name()+"\n");
    // changed load_name() to load_name(), Coogan, 12-Sep-00
  }
  return container::short();
}

private string box_short() {
  return describe(this_object(), ARTICLE_A);
}

private string box_long() {
  // added funcall(), Coogan, 09-Jun-2004
  return ((funcall(query_container_long()) ||
           "This is " + describe(this_object(), ARTICLE_A) + ".\n") +
          "It is " + query_open_state_description() + ".\n");
}

void create() {
  handle::create();
  container::create();
}

void refresh() {  // Coogan, 22-Mar-98
  handle::refresh();
  container::refresh();
}

void configure() {
  container::configure();
  set_persistence(__FILE__, PER_KEEP_VARS, ({
    PER_PERM_VAR+"open_state",   // PER_PERM_VAR added, Coogan, 22-Mar-98
    }));

  set_short(#'box_short);
  set_long(#'box_long);
  add_to_property(P_STATE_DESCRIPTION,({ 0, "query_open_state_description" }));
  set_id(({ "non-descript box" }));
  set_name("box");
}

status insert_objects() {
  return query_open();
}

int apply_action(string action, int level, mixed args) {
  return
    handle::apply_action(action,level,args) ||
    container::apply_action(action,level,args);
}
