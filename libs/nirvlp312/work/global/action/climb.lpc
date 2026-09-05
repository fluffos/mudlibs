/* 
 * basic skill of climbing
 * sas@cs.tu-berlin.de (Ardanna)
 * Modified Aug28 93 muxestba
 * Updated and event added, Coogan, 16-Jan-02
 */

#pragma strong_types

#include <skilltree.h>
#include <server.h>
#include <grammar.h>
#include <server.h>
#include <event.h>
#include <describe.h>
#include <prop/room.h>

inherit "basic/parser";
inherit "basic/action";

private void receive_climb_event(mapping e, string type, int prio);

void create() {
  action::create();
  set_skill_path(S_CLIMB);
  set_command("climb");
  set_specific(0);
  set_function("parse_action");

  add_rule("climb over "G_INDIRECT,    "climb_over_env");
  add_rule("climb through "G_INDIRECT, "climb_through_env");
  add_rule("climb "G_INDIRECT,         "climb_env");
  add_rule("climb "G_TEXT,             "climb_env_error");
  add_rule("climb",                    "climb_error");

  set_global_listening_event("climb", 1);
  listen_event("climb", EPRIO_HANDLE, #'receive_climb_event);
}

string query_info(string str) {
  return
    "You can climb up or down, or you could try to climb an object.\n"
    "The higher your climbing skill, the higher is your chance of succeeding\n"
    "with difficult climbs, but beware: a slip can cause serious damage in\n"
    "some locations.\n"
    "Carrying too much while attempting to climb may result in a drastically\n"
    "lowered effective skill value. The maximum amount you can carry and \n"
    "still climb unencumbered is computed by taking into account your \n"
    "strength, your dexterity and the level of your climb skill.\n";
}

void print_load_message() {
  int l;
  l = (100 * this_player()->query_carry()) /
                (this_player()->query_max_carry());  // 0..200 (percent)
  switch (l) {
  case   0.. 30:
    return;
  case  31.. 60:
    message("The stuff you are carrying hindered you some in climbing.\n");
    return;
  case  61.. 80:
    message("You are quite encumbered for climbing.\n");
    return;
  default:
    message("You had great difficulties in climbing with all the stuff "
            "you are carrying.\n");
    return;
  }
}

int do_action(string action, mapping args) {
  mapping event;

// DEBUG_POINT_TP("coogan", ({ action, args }));
  if (args[G_INDIRECT]) {
    if (present(args[G_INDIRECT], this_player()))
      return 0;
  }
  switch (action) {
  case "climb_error":
    notify_fail("Yes, yes, climbing is healthy, but climb what?\n");
    return 0;

  case "climb_over_env":
    event = ([ E_PREPOSITION : "over" ]);
    // fall through
  case "climb_through_env":
    if (!event)
      event = ([ E_PREPOSITION : "through" ]);
    // fall through
  case "climb_env":
    if (!event)
      event = ([ ]);
    event += ([ E_AGENT  : this_player(),
                E_TARGET : args[G_INDIRECT, 0],
                E_ID     : args[G_INDIRECT, 1],
             ]);
    break;

  case "climb_env_error":
    if      (strlen(args[G_TEXT]) > 5 && args[G_TEXT][0..4] == "over ")
      args[G_TEXT] = args[G_TEXT][5..];
    else if (strlen(args[G_TEXT]) > 8 && args[G_TEXT][0..7] == "through ")
      args[G_TEXT] = args[G_TEXT][8..];

    // first parsing matched an object in the room, but the room has a fakeitem
    // of the same id. try that, too.
    if ((present(args[G_TEXT], environment(this_player())) /* ||
         present(args[G_TEXT], this_player()) */ ) &&
        environment(this_player())->query_fakeitem_id(args[G_TEXT]) ||
        environment(this_player())->query_exit(args[G_TEXT]) ||
        args[G_TEXT] == "up" || args[G_TEXT] == "down"       ||
        environment(this_player())->query_property(P_FOREST) &&
          (args[G_TEXT] == "tree" || args[G_TEXT] == "trees")) {
      event = ([ E_AGENT  : this_player(),
                 E_TARGET : environment(this_player()),
                 E_ID     : args[G_TEXT],
              ]);
      break;
    }
    notify_fail("There is no climbable "+args[G_TEXT]+" around here.\n");
    return 0;
  }
  send_event("climb", event, environment(this_player()));
  if (event[E_CANCELLED])
    return 1;

  if (event[E_SUCCESS] == -1)
    return 1;

  if (event[E_SUCCESS] > 0) {
    print_load_message();
    if (event[E_SUCCESS] > 1)
      this_player()->add_skill_points(query_skill_path(), event[E_SUCCESS]);
    else if (!random(3))
      this_player()->add_skill_points(query_skill_path(),
                                      SE_SKILLS->query_reward(this_player(),
                                                              event[E_SUCCESS],
                                                              50, S_CLIMB));
  } else {
#if 1
    notify_fail("Alas, it is impossible to climb " +
                describe(event[E_ID], ARTICLE_THE) + ".\n");
#else
    switch (action) {
    case "climb_env":
      notify_fail("Alas, it is impossible to climb " +
                  describe(event[E_ID], ARTICLE_THE) + ".\n");
      break;
    case "climb_env_error":
      notify_fail("You look carefully but do not see a climbable " +
                  event[E_ID] + ".\n");
      break;
    }
#endif
  }
  return event[E_SUCCESS];
}

private int apply_climb_action(mapping e) {
  int sk;
  sk = this_player()->query_modified_skill(query_skill_path());
  return (e[E_TARGET]->apply_action(query_skill(), sk, e));
}

private void receive_climb_event(mapping e, string type, int prio) {
  if (type != "climb" || prio != EPRIO_HANDLE || e[E_CANCELLED])
    return;
  e[E_HANDLED] = 1;
  e[E_SUCCESS] = with_player(e[E_AGENT], #'apply_climb_action, e);
}

