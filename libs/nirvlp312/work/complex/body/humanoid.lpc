#include <combat.h>
#include <event.h>
#include <action.h>
#include <message.h>

inherit "basic/body/humanoid/dressable"; // something that can be dressed
inherit "basic/body/humanoid/wielder";   // someone who can wield
inherit "basic/action/move";             // movements of items and self
inherit "basic/action/dress";            // wear,remove,dress,undress
inherit "basic/action/wield";            // wield,unwield
inherit BODY;

status
query_humanoid_race(string r)
{
  switch (r)
  {
  case "human":
  case "dwarf":
  case "elf":
  case "hobbit":
  case "orc":
  case "troll":
  case "gnome":
  case "goblin":
    return 1;
  }
}

void
set_race(string r)
{
  object torso, head, limb;

  if (query_race() || !query_humanoid_race(r))
    return;

  BODY::set_race(r);

  set_name(r+" body");
  add_id(({ r+" body" }));

  add_bodypart(head = clone_object(BP_HEAD(""+r+"")));

  add_bodypart(torso = clone_object(BP_TORSO(""+r+"")));
  connect_bodyparts(torso,head,BPC_NECK);

  // left parts first, so their actions come last
  add_bodypart(limb = clone_object(BP_UPPER_LIMB(""+r+"")));
  limb->add_position("left",1);
  connect_bodyparts(limb,torso,BPC_SHOULDER,BPC_LEFT_SHOULDER);

  add_bodypart(limb = clone_object(BP_LOWER_LIMB(""+r+"")));
  limb->add_position("left",1);
  connect_bodyparts(limb,torso,BPC_HIP);

  add_bodypart(limb = clone_object(BP_UPPER_LIMB(""+r+"")));
  limb->add_position("right",1);
  connect_bodyparts(limb,torso,BPC_SHOULDER,BPC_RIGHT_SHOULDER);

  add_bodypart(limb = clone_object(BP_LOWER_LIMB(""+r+"")));
  limb->add_position("right",1);
  connect_bodyparts(limb,torso,BPC_HIP);

  map(get_bodyparts("hand",1),#'add_hand);
}

void
configure()
{
  BODY::configure();
  ACTION "move"::configure();
  ACTION "dress"::configure();
  ACTION "wield"::configure();

  set_name("humanoid body");
  set_id(({"body","humanoid body"}));
}

void init_actions() {
  BODY::init_actions();
  ACTION "move"::init_actions();
  ACTION "dress"::init_actions();
  ACTION "wield"::init_actions();
}

void init() {
  BODY::init();
  if (this_player() == environment())
    init_actions();
}

mapping build_complete_action(mapping action, mapping args) {
  return
    ACTION "move"::build_complete_action(action,args) ||
    ACTION "wield"::build_complete_action(action,args) ||
    ACTION "dress"::build_complete_action(action,args) ||
    BODY::build_complete_action(action,args);
}

mapping build_action_event(mapping e) {
  return 
    ACTION "move"::build_action_event(e) ||
    ACTION "wield"::build_action_event(e) ||
    ACTION "dress"::build_action_event(e) ||
    BODY::build_action_event(e);
}

mixed query_action_impossible(mapping e) {
  switch (e[E_ACTION]) {
    case "drop":
    case "offer":
    case "give":
    case "transfer":
    case "put_on":
    case "insert":
      if (e[E_TARGET] && e[E_AGENT]->query_wielding(e[E_TARGET]) &&
          !e[E_TARGET]->query_wieldable_not_present(e[E_AGENT]))
        return "You should unwield it first.\n";
      break;
  }
  return
    ACTION "move"::query_action_impossible(e) ||
    ACTION "wield"::query_action_impossible(e) ||
    ACTION "dress"::query_action_impossible(e) ||
    BODY::query_action_impossible(e);
}

mixed query_running_action_impossible(mapping e) {
  return
    ACTION "move"::query_running_action_impossible(e) ||
    ACTION "wield"::query_running_action_impossible(e) ||
    ACTION "dress"::query_running_action_impossible(e) ||
    BODY::query_running_action_impossible(e);
}

status prevent_prepare_action_event(mapping e) {
  int i;
  mixed h;
  mapping action;

  switch (e[E_ACTION]) {
  case "wield":
    if (e[E_WHERE] || e[E_WITH]) {
      if ((h = get_wield_bodypart(e)) && 
          !e[E_TARGET]->query_held_by(e[E_AGENT], 0, h))
        if (e[E_TARGET]->query_wielded_by(e[E_AGENT]))
          return 
            precede_action(build_action("unwield",([A_G_TARGET:
                                                     e[E_TARGET];
                                                     e[E_TARGET,1]])));
        else
          return
            h->precede_action(h->build_action("grab",([A_G_TARGET:
                                                         e[E_TARGET];
                                                         e[E_TARGET,1],
                                                       A_G_POSITION:
                                                         e[E_WHERE];
                                                         e[E_WHERE,1],
                                                       A_G_BODYPART:
                                                         e[E_WITH];
                                                         e[E_WITH,1]])), e);
    }
    if (!can_wield(e[E_TARGET])) {
      if (!e[E_TARGET]->query_wieldable_not_present(e[E_AGENT]) &&
          !present(e[E_TARGET],e[E_AGENT]))
        return
          precede_action(build_action("take",([A_G_TARGET:
                                                 e[E_TARGET];
                                                 e[E_TARGET,1],
                                               A_G_POSITION:
                                                 e[E_WHERE];
                                                 e[E_WHERE,1],
                                               A_G_BODYPART:
                                                 e[E_WITH];
                                                 e[E_WITH,1]])));
      if (!e[E_TARGET]->query_wieldable_not_held(e[E_AGENT]) &&
          !e[E_TARGET]->query_held_by(e[E_AGENT]) &&
          h = get_wield_bodypart(e)) 
        return
          h->precede_action(h->build_action("grab",([A_G_TARGET:
                                                      e[E_TARGET];
                                                      e[E_TARGET,1]])), e);
      if (!e[E_TARGET]->query_wieldable_not_clenched(e[E_AGENT]) &&
          sizeof(h = e[E_TARGET]->get_holding_parts(get_user())) &&
          sizeof(h -= filter_objects(h,"query_clenched"))) {
        action = h[0]->build_action("clench");
        return
          h[0]->precede_action(action,e);
      } 
      return 
        BODY::prevent_prepare_action_event(e) ||
        (fail_action(message2string(({"You can't wield ",
                                      M_OBJECT,M_THE,e[E_TARGET],
                                      " properly.\n"}))), 1);
    } 
    break;
  case "dress":
    h = filter_objects(get_hands(),"query_holding",e[E_TARGET]);
    if (!sizeof(h))
      for (i = sizeof(h = get_hands()); i-->0; )
        if (!sizeof(h[i]->get_held()) && h[i]->can_hold(e[E_TARGET])) {
          action = h[i]->build_action("grab",([A_G_TARGET: e[E_TARGET];
                                                           e[E_TARGET,1]]));
          return 
            h[i]->precede_action(action,e);
        }
    if (present(e[E_TARGET],e[E_AGENT]) && 
        e[E_AGENT] != e[E_RECIPIENT])
      return
        precede_action(build_action("transfer",
                                    ([A_G_TARGET:
                                        e[E_TARGET];
                                        e[E_TARGET,1],
                                      A_G_LIVING:
                                        e[E_RECIPIENT];
                                        e[E_RECIPIENT,1]])));
    else if (!present(e[E_TARGET],e[E_RECIPIENT]))
      return
        precede_action(build_action("take",
                                    ([A_G_TARGET: e[E_TARGET];
                                                  e[E_TARGET,1]])));
    break;
  case "undress":
    if (!e[E_TARGET]->query_worn())
      return BODY::prevent_prepare_action_event(e);
    h = filter_objects(get_hands(),"query_holding",e[E_TARGET]);
    if (!sizeof(h))
      for (i = sizeof(h = get_hands()); i-->0; )
        if (!sizeof(h[i]->get_held()) && h[i]->can_hold(e[E_TARGET])) {
          action = h[i]->build_action("grab",([A_G_TARGET: e[E_TARGET];
                                                           e[E_TARGET,1]]));
          return 
            h[i]->precede_action(action,e);
        }
    break;
  }
  return
    BODY::prevent_prepare_action_event(e) ||
    ACTION "move"::prevent_prepare_action_event(e);
}

status do_preparations(mapping e) {
  switch (e[E_ACTION]) {
    case "dress":
    case "undress":
      return
        BODY::do_preparations(e) +
        ACTION "dress"::do_preparations(e) == 2;
    default:
      return
        BODY::do_preparations(e);
  }
}

void undo_preparations(mapping e) {
  BODY::undo_preparations(e);
  ACTION "dress"::undo_preparations(e);
}

status handle_finish_action_dress(mapping e) {
  mixed result;

  result = ACTION "dress"::handle_finish_action_dress(e);
  if (e[E_SUCCESS])
    schedule_action(build_action("let_go",
                                 ([A_G_TARGET:
                                     e[E_TARGET];
                                     e[E_TARGET,1]]),
                                 A_MODE_FAST));
  return result;
}

status handle_finish_action_undress(mapping e) {
  mixed result;

  result = ACTION "dress"::handle_finish_action_undress(e);
  if (e[E_SUCCESS] && e[E_AGENT] != e[E_RECIPIENT])
    schedule_action(build_action("let_go",
                                 ([A_G_TARGET:
                                     e[E_TARGET];
                                     e[E_TARGET,1]]),
                                 A_MODE_FAST));
  return result;
}
