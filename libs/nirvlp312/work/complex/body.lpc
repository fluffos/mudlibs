/****************************************************************************
            body.c -- a body object comprising bodyparts
                    written by Ugh for Tubmud
****************************************************************************/
#pragma strong_types

#include <persistence.h>
#include <combat.h>
#include <event.h>
#include <inventory.h>

inherit "basic/race";
inherit BASIC_BODYPART_COMPOUND;
inherit BASIC_DEFENSE;
inherit BASIC_TOOL;
inherit "complex/item";

inherit ACTION "hit";   // unspecified general purpose attack
inherit ACTION "dodge";

public object get_environment() {
  object u;
  return get_user() || environment();
}

void create() {
  if (!clonep())
    return;
  else
    item::create();
}

private string body_long() {
  return capitalize(describe("a "+query_race()+" body"))+".\n";
}

void configure() {
  item::configure();
  ACTION"hit"::configure();
  set_persistence(PER_NO_PERSISTENCE);
  set_id(({ "body" }));
  set_short(0);
  set_long(#'body_long);
  set_name("body");
  set_property(P_BODY);
}

status id(string str) {
  return
    item::id(str) ||
    BASIC_BODYPART_COMPOUND::id(str);
}

status hide_inventory(string str) {
  if (str && get_component(&str))
    return BASIC_BODYPART_COMPOUND::hide_inventory(str);
  return 1;
}

varargs string query_name(string str) {
  if (str && get_component(&str))
    return BASIC_BODYPART_COMPOUND::query_name(str);
  return item::query_name();
}

varargs mixed query_property(string prop,string id) {
  if (id && get_component(&id))
    return BASIC_BODYPART_COMPOUND::query_property(prop,id);
  else
    return item::query_property(prop,id);
}

string long(string id) {
  return BASIC_BODYPART_COMPOUND::long(id) || item::long(id);
}

void set_user(object u) {
  BASIC_BODYPART_COMPOUND::set_user(u);
  BASIC_DEFENSE::set_user(u);
}

void
notify_move(object from, object to)
{
  set_user(to);
}

void add_tool_action_rule(varargs mixed vargs) {
  return apply(#'add_action_rule,vargs);
}

void init() {
  if (this_player() == environment()) {
    BASIC_BODYPART_COMPOUND::init();
  }
}

void init_actions() {
  "*"::init_actions();
}

status handle_event(mapping e, string t, int p) {
  return
    BASIC_TOOL::handle_event(e,t,p) ||
    item::handle_event(e,t,p);
}

status prevent_event(mapping e, string t, int p) {
  if (e[E_TOOL] == this_object())
    return
      item::prevent_event(e,t,p);
}

status can_perceive(mapping e,string t) {
  return 0;
}

string describe_event(mapping e,string t) {
  if (can_perceive(e,t))
    return sprintf("Event of type %O received:\n"
                   "%O\n",t,e);
  return 0;
}

object get_user() {
  return environment();
}

object *get_inventory(string which, string preposition) {
  object *result;

  result = ({});
  result += item::get_inventory(which,preposition) || ({});
  result +=
    (BASIC_BODYPART_COMPOUND::get_inventory(which,preposition) || ({})) -
    result;
  return result;
}

status drop(status silently) {
  return 1;
}

mapping build_complete_action(mapping action, mapping args) {
  return (ACTION"hit"::build_complete_action(action,args) ||
          ACTION"dodge"::build_complete_action(action, args) ||
          BASIC_TOOL::build_complete_action(action,args));
}

mapping build_action_event(mapping action) {
  return (ACTION"hit"::build_action_event(action) ||
          ACTION"dodge"::build_action_event(action) ||
          BASIC_TOOL::build_action_event(action));
}

mixed query_action_impossible(mapping e) {
  return (ACTION"hit"::query_action_impossible(e) ||
          ACTION"dodge"::query_action_impossible(e) ||
          BASIC_TOOL::query_action_impossible(e));
}

mixed query_running_action_impossible(mapping e) {
  return (ACTION"hit"::query_running_action_impossible(e) ||
          ACTION"dodge"::query_running_action_impossible(e) ||
          BASIC_TOOL::query_running_action_impossible(e));
}
