/***************************************************************************
          bodypart/.../humanoid/hand -- written by Ugh 98 for Tubmud
***************************************************************************/
#include <combat.h>
#include <event.h>
#include <message.h>
#include <grammar.h>
#include <action.h>
#include <global_commands.h>  // added global_, Coogan, 02-May-01

inherit ACTION "hold";   // holding/transferring of objects
inherit ACTION "punch";   // attack 'punch'
inherit BODYPART;         // for bodypart-data/handling, damage,defense

#ifndef A_M_USER
#define A_M_USER (get_user())
#endif

void configure() {
  BODYPART::configure();
  ACTION "hold"::configure();
  ACTION "punch"::configure();

  set_type("hand");
  set_name("hand");
  add_id(({"hand","fist","extremity"}));
  add_position("upper");
  add_position("middle");
  add_bodypart_connectors(({BPC_WRIST}));
}

void create() {
  BODYPART     ::create();
  ACTION"hold"::create();
}

void notify_destruct() {
  BODYPART::notify_destruct();
  map(get_held(),#'let_go);
}

void set_clenched(status c) {
  if (c && !sizeof(get_held()))
    set_name("fist");
  else
    set_name("hand");
  ACTION"hold"::set_clenched(c);
}

string long(string str) {
  string result, verb;
  mixed h;

  result = BODYPART::long(str);
  if (cut_off_position(str) == "fist" && !query_clenched())
    result +=
      capitalize(message2string(({"For it to become a fist, ", A_M_USER,
                                  " would have to clench it first.\n"})));
  if (sizeof(h = get_held())) {
    if (query_wielding(h[0]))
      verb = "wield";
    else if (query_clenched())
      verb = "clench";
    else
      verb = "hold";
    result +=
      capitalize(message2string(({M_PRONOUN,A_M_USER,M_VERB,"are",A_M_USER,
                                  " "+verb+"ing ",
                                  M_THE,M_OBJECT,h," in ",
                                  M_ME_PRONOUN,".\n"})));
  }
  return result;
}

object get_arm() {
  return get_compound_bodypart()->get_component("arm");
}

mapping build_complete_action(mapping action,mapping args) {
  int i;
  object *held, arm;
  mapping needed;
  action = BODYPART::build_complete_action(action,args);
  action = (ACTION "hold"::build_complete_action(action,args) ||
            ACTION "punch"::build_complete_action(action,args) || action);
  if (LIB_ACTIONS->is_arm_action(action[E_ACTION]) || 
      action[E_ACTION] == "parry") {  // arm action?
    needed = action[A_NEEDED_USED] || ([]);
    if (!needed[query_name()]) {  // are we not yet in the mapping?
      needed[query_name()] = 1;
      action[A_NEEDED_USED] = needed;
      // make sure that the arm is involved:
      arm = get_arm();
      if (!needed[arm->query_name()])  // is the arm not yet in?
        action = arm->build_complete_action(action,args);
      // complete the action mapping by all held weapons:
      if (sizeof(held=get_held()))
        for (i=sizeof(held); i-->0; )
          action = held[i]->build_complete_action(action,args) || action;
    }
  } else if (action[E_TOOL] == this_object()) {
    needed = action[A_NEEDED_USED] || ([]);
    needed[query_name()] = 1;
    action[A_NEEDED_USED] = needed;
  }
  return action;
}

mapping build_action_event(mapping action) {
  return
    (ACTION "hold"::build_action_event(action) ||
     ACTION "punch"::build_action_event(action) ||
     BODYPART::build_action_event(action));
}

mapping build_damage_event(mapping attack) {
  return
    (ACTION "hold"::build_damage_event(attack) ||
     ACTION "punch"::build_damage_event(attack));
}

void init_component() {
  ACTION "hold"::init_actions();
  ACTION "punch"::init_actions();
  BODYPART::init_component();
}

mixed query_action_impossible(mapping action) {
  mixed h;
  switch (action[E_ACTION]) {
    case "let_go":
      if (action[E_TARGET]) {
        h = action[E_TARGET];
      } else {
        h = get_held();
      }
      h = filter(h, "query_wielding", action[E_AGENT]);
      h -= filter_objects(h, "query_wieldable_not_held", action[E_AGENT]);
      if (sizeof(h))
        return message2string(({"You have to unwield ",M_THE, h, " first.\n"}));
      break;
    case "unclench":
      h = get_held();
      h = filter(h, "query_wielding", action[E_AGENT]);
      h -= filter_objects(h, "query_wieldable_not_clenched", action[E_AGENT]);
      if (sizeof(h))
        return message2string(({"You have to unwield ",M_THE, h, " first.\n"}));
      break;
  }
  return
    (ACTION "hold"::query_action_impossible(action) ||
     ACTION "punch"::query_action_impossible(action) ||
     BODYPART::query_action_impossible(action));
}

mixed query_running_action_impossible(mapping action) {
  return
    (ACTION "hold"::query_running_action_impossible(action) ||
     ACTION "punch"::query_running_action_impossible(action) ||
     BODYPART::query_running_action_impossible(action));
}

status prevent_prepare_action_event(mapping e) {
  mixed h;

  if (e[E_TOOL] == this_object()) {
    switch (e[E_ACTION]) {
      case "punch":
        if (sizeof(h = get_held()))
          return precede_action(build_action("let_go"));
        if (!query_clenched())
          return precede_action(build_action("clench"));
        break;
    }
  }
  return
    ACTION "hold"::prevent_prepare_action_event(e) ||
    BODYPART::prevent_prepare_action_event(e);
}

status query_unreachable(object by) {
  mixed h;

  if (BODYPART::query_unreachable(by))
    return 1;
  if ((h = get_compound_bodypart()) && h->query_unreachable(by))
    return 1;
}

status prevent_event(mapping e, string t, int p) {
  int i;
  mixed h;
  string name;

  name = object_name()+"##"+__FILE__+"##"+p;
  if (member(e[E_PREVENTERS],name))
    return e[E_PREVENTERS][name];
  e[E_PREVENTERS][name] = 0;
  if (e[E_TYPE] == "action") {
    for (i = sizeof(h = get_held()); i-->0; )
      if (h[i]->prevent_event(e,t,p))
        return e[E_PREVENTERS][name] = 1;
    if (LIB_ACTIONS->is_arm_action(e[E_ACTION])) {
      h -= filter_objects(h,"query_wielded_by",get_user());
      if (sizeof(h))
        return e[E_PREVENTERS][name] = 
          e[E_TOOL]->fail_action(message2string(({"You should let go of ",
                                                  M_THE,M_OBJECT,h,
                                                  " first.\n"})),1), 1;
    }
    if ((h = get_arm()) && h != e[E_TOOL])
      if (h->prevent_event(e,t,p))
        return e[E_PREVENTERS][name] = 1;
    if (e[E_TARGET]) {
      if (objectp(e[E_TARGET])) {
        if (e[E_TARGET]->prevent_event(e,t,p))
          return e[E_PREVENTERS][name] = 1;
      } else {
        for (i = sizeof(h = e[E_TARGET]); i-->0; )
          if (h[i]->prevent_event(e,t,p))
            return e[E_PREVENTERS][name] = 1;
      }
    }
  }
  if (BODYPART::prevent_event(e,t,p))
    return e[E_PREVENTERS][name] = 1;
}
