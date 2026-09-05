#include <combat.h>
#include <action.h>
#include <event.h>
#include <message.h>

inherit ACTION"parry";
inherit ACTION"arm_action";
inherit BASIC_DEFENSE;
inherit BODYPART;

void
configure()
{
  ACTION"parry"::configure();
  ACTION"arm_action"::configure();
  BODYPART::configure();

  set_type("arm");
  set_name("arm");
  add_id(({"arm"}));
  add_position("upper");
  add_position("middle");
  add_bodypart_connectors(({BPC_SHOULDER,BPC_WRIST}));
}

object get_hand() {
  return get_compound_bodypart()->get_component("hand");
}

mapping build_action(string action, mapping args) {
  object hand;

  if (is_arm_action(action) ||         // action of the arm 
      action == "parry") {             // parry
    if (args &&
        args[A_G_WEAPON] && 
        args[A_G_WEAPON] != this_object() &&
        (!(hand = get_hand()) || 
         (hand != args[A_G_WEAPON] &&
          !hand->query_wielding(args[A_G_WEAPON]))))
      return
        notify_fail(message2string(({"Maybe you should wield ",
                                     M_THE,M_OBJECT,args[A_G_WEAPON],
                                     " first.\n"}))), 0;
    if (action != "parry" &&
        !(args && args[A_G_TARGET]) && 
        !get_user()->get_opponent())
      return 
        (action == "parry" ? 
         notify_fail("Parry what with what?\n") :
         notify_fail(capitalize(action+" at whom or what?\n"))), 0;
  }
  return BODYPART::build_action(action,args);
}

mapping build_complete_action(mapping action, mapping args) {
  mapping needed;
  object hand;

  action = BODYPART::build_complete_action(action,args);
  action = (ACTION"parry"::build_complete_action(action,args) ||
            ACTION"arm_action"::build_complete_action(action,args) ||
            action);
  if (is_arm_action(action[E_ACTION]) || action[E_ACTION] == "parry") {
    // limitation: we just handle one-handed arms ;-)
    hand = get_hand();
    // swing/thrust/... only standing on two legs
    needed = action[A_NEEDED_SHARED] || ([]);
    if (needed["leg"] < 2)
      needed["leg"] = 2;
    action[A_NEEDED_SHARED] = needed;
    needed = action[A_NEEDED_USED] || ([]);
    needed[query_name()] = 1;
    action[A_NEEDED_USED] = needed;
    if (!needed[hand->query_name()])  // hand not yet in list?
      action = hand->build_complete_action(action,args);
  }
  return action;
}

mapping build_action_event(mapping action) {
  return
    ACTION"parry"::build_action_event(action) ||
    ACTION"arm_action"::build_action_event(action) ||
    BODYPART::build_action_event(action);
}

mapping build_damage_event(mapping action) {
  return
    ACTION"parry"::build_damage_event(action) ||
    ACTION"arm_action"::build_damage_event(action);
}

mixed query_action_impossible(mapping action) {
  return
    ACTION"parry"::query_action_impossible(action) ||
    ACTION"arm_action"::query_action_impossible(action) ||
    BODYPART::query_action_impossible(action);
}

void init_component() {
  ACTION"parry"::init_actions();
  ACTION"arm_action"::init_actions();
  BODYPART::init_component();
}

void set_user(object u) {
  BASIC_DEFENSE::set_user(u);
  BODYPART::set_user(u);
}

status query_unreachable(object by) {
  mixed h;

  if (BODYPART::query_unreachable(by))
    return 1;
  if ((h = get_compound_bodypart()) && h->query_unreachable(by))
    return 1;
}

status prevent_event(mapping e, string t, int p) {
  mixed h;

  if (BODYPART::prevent_event(e,t,p))
    return 1;
  if (e[E_TOOL] == this_object() &&
      (h = get_hand()) &&
      h->prevent_event(e,t,p))
    return 1;
}
