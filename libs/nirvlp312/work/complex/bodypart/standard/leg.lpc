#include <action.h>
#include <combat.h>
#include <event.h>
#include <message.h>

inherit ACTION "kick";
inherit ACTION "knee";
inherit BODYPART;

status has_position(string pos);

void configure() {
  BODYPART::configure();
  ACTION "kick"::configure();
  ACTION "knee"::configure();

  set_type("leg");
  set_name("leg");
  add_id(({"leg"}));
  add_position("lower");
  add_bodypart_connectors(({BPC_ANKLE,BPC_HIP}));
}

void init_component() {
  ACTION "kick"::init_actions();
  ACTION "knee"::init_actions();
  BODYPART::init_component();
}

object get_other_leg() {
  if (has_position("right"))
    return get_user()->get_bodypart("left leg",1);
  else
    return get_user()->get_bodypart("right leg",1);
}

mapping build_complete_action(mapping action, mapping args) {
  mapping needed;

  action = BODYPART::build_complete_action(action,args);
  action =
    ACTION "kick"::build_complete_action(action,args) ||
    ACTION "knee"::build_complete_action(action,args) ||
    action;
  if (action[E_ACTION] == "kick" || action[E_ACTION] == "knee") {
    needed = action[A_NEEDED_USED] || ([]);
    needed[query_name()] = 1;
    needed[get_other_leg()->query_name()] = 1;
    action[A_NEEDED_USED] = needed;
  }
  return action;
}

mapping build_action_event(mapping action) {
  return
    ACTION "kick"::build_action_event(action) ||
    ACTION "knee"::build_action_event(action) ||
    BODYPART::build_action_event(action);
}

mapping build_damage_event(mapping action) {
  return
    ACTION "kick"::build_damage_event(action) ||
    ACTION "knee"::build_damage_event(action);
}

mixed query_action_impossible(mapping action) {
  return
    ACTION "kick"::query_action_impossible(action) ||
    ACTION "knee"::query_action_impossible(action) ||
    BODYPART::query_action_impossible(action);
}

status query_unreachable(object by) {
  mixed h;

  if (BODYPART::query_unreachable(by))
    return 1;
  if ((h = get_compound_bodypart()) && h->query_unreachable(by))
    return 1;
}
