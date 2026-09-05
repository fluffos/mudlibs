/* 
 * basic skill of searching
 * sas@cs.tu-berlin.de (Ardanna)
 * Modified Aug28 93 muxestba.
 * Updated and event added, Coogan, 09-Jan-02
 */

#pragma strong_types

#include <skilltree.h>
#include <grammar.h>
#include <event.h>
#include <server.h>
#include <message.h>
#include <time_units.h>

inherit "basic/parser";
inherit "basic/action";
inherit "basic/orientation";  // Alfe 2002-Mar-25

private void receive_search_event(mapping e, string t, int p);

void create() {
  action::create();
  set_skill_path(S_SEARCH);
  set_command("search");
  set_specific(0);
  set_function("parse_action");

#if 1  // Alfe 2002-Mar-25
  add_rule("search for traces",            "search_for_traces");
  add_rule("search here for traces",       "search_for_traces");
  add_rule("search "G_OBJECT" for traces", "search_for_traces");
#endif
  add_rule("search "G_INDIRECT, "search_indirect");
  add_rule("search "G_TEXT,     "search_env");
  add_rule("search",            "search_error");

  set_global_listening_event("search", 1);
  listen_event("search", EPRIO_HANDLE, #'receive_search_event);
}

string query_info(string str) {
  return
   "You can search any object, and sometimes you might find something.\n"
   "Depending on your skill, there may be times when you will not find all\n"
   "there is to find. Just try again when your skill is higher.\n"
   "Searching increases by practise.\n";
}

int do_action(string action, mapping args) {
  mapping event;

  if (this_player()->test_darkness(environment(this_player()), 1)) {
    notify_fail("It is too dark to search.\n");
    return 0;
  }
  if (this_player()->test_brightness(environment(this_player()), 1)) {
    notify_fail("It is too bright to search.\n");
    return 0;
  }
  switch (action) {
  case "search_error":
    notify_fail("You search around aimlessly but don't find anything "
                "of interest.\n");
    return 0;

  case "search_indirect":
    event = ([ E_AGENT  : this_player(),   
               E_TARGET : args[G_INDIRECT, 0]
            ]);
    // improved the next part, Coogan 23-Apr-02
    if (lower_case(describe(args[G_INDIRECT, 0])||"") ==
        lower_case(args[G_INDIRECT, 1]))
      event[E_ID] = describe(args[G_INDIRECT, 0]);
    else
      event[E_ID] = args[G_INDIRECT, 1];
    break;

  case "search_env":
    event = ([ E_AGENT  : this_player(),
               E_TARGET : environment(this_player()),
               E_ID     : args[G_TEXT],
            ]);
    break;

  case "search_for_traces":
    event = ([ E_AGENT  : this_player(),
               E_TYPE   : "traces",
               E_TARGET : args[G_OBJECT, 0] || environment(this_player()),
               E_ID     : args[G_OBJECT, 1] || "here",
            ]);
    break;

  default:
    return 0;
  }
  send_event("search", event, environment(this_player()));
  if (event[E_CANCELLED])
    return 1;
  if (event[E_SUCCESS] > 0) {
    if (event[E_SUCCESS] > 1)
      this_player()->add_skill_points(query_skill_path(), event[E_SUCCESS]);
    else if (!random(3))
      this_player()->add_skill_points(query_skill_path(),
                                      SE_SKILLS->query_reward(this_player(),
                                                              event[E_SUCCESS],
                                                              50, S_SEARCH));
  } else if (event[E_SUCCESS] == 0) {
    // improved the next part, Coogan 23-Apr-02
    notify_fail("There is nothing to be found by searching " +
                describe(args[G_INDIRECT] &&
                           event[E_ID] ||
                         args[G_TEXT] == "here" &&
                           environment(this_player()) ||
                         args[G_TEXT], ARTICLE_THE) +
                ".\n", (action == "search_indirect"));
  }

  return !!event[E_SUCCESS];
}

private mixed describe_trace(mixed trace) {
  mixed age;
  string *ages;
  mixed direction;
  mixed boots;
  ages = ({ " brand new", " fresh", "", " slightly blurred",
            " old", " very old", " ancient" });
  age = time() - trace[<1];
  switch (age) {
  case               0 ..  3*ONE_MINUTE: age = 0; break;
  case  3*ONE_MINUTE+1 .. 15*ONE_MINUTE: age = 1; break;
  case 15*ONE_MINUTE+1 ..    ONE_HOUR:   age = 2; break;
  case    ONE_HOUR  +1 ..  3*ONE_HOUR:   age = 3; break;
  case  3*ONE_HOUR  +1 .. 12*ONE_HOUR:   age = 4; break;
  case 12*ONE_HOUR  +1 ..  3*ONE_DAY:    age = 5; break;
  default:                               age = 6; break;
  }
  if (pointerp(trace[0]) && sizeof(trace) == 2)
    trace = trace[0];
  else
    trace = trace[0..<2];  // cut off time
  if (sizeof(trace) > 3 && trace[3])
    boots = ({ " tracks of " + trace[3] });
  else
    boots = ({ " traces" });
  switch (trace[0]) {
  case "enter":
    direction = orientation_reverse(trace[2], 0);
    if (direction == "up")
      direction = ({ " leading here from above" });
    else if (direction == "down")
      direction = ({ " leading here from below" });
    else if (direction)
      direction = ({ " leading here from the " + direction });
    else
      direction = ({ ", but ", M_PL_VERB, "cannot",
                     " tell where they came from" });
    return ({ ages[age] }) + boots + direction;
  case "leave":
    direction = orientation_reverse(trace[2], 0);
    direction = orientation_reverse(direction, 0);
    if (direction)
      direction = ({ " leaving " + direction });
    else
      direction = ({ ", but ", M_PL_VERB, "cannot",
                     " tell where they are leading to" });
    return ({ ages[age] }) + boots + direction;
    break;
  default:
    return ({ ages[age] + " traces of something, but ", M_PL_VERB, "cannot",
              " tell of what" });
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

private status finds_trace(mixed trace) {
  // this function determines whether this_player() finds the trace.
  return time() - trace[<1] /* age */ < ONE_MINUTE || !random(5);
}

private int apply_search_action(mapping e) {
  int sk;
  sk = this_player()->query_modified_skill(query_skill_path());
  if (e[E_TYPE] == "traces") {
    mixed *traces;
    if (e[E_TARGET] != environment(this_player()))
      send_message(({ M_PL_THE, M_PL_VERB, "have", " a close look on ",
                      M_THE, M_OBJECT, e[E_TARGET], "." }));
    else
      send_message(({ M_PL_THE, M_PL_VERB, "look",
                      " around very carefully, especially on the ground." }));
    traces = e[E_TARGET]->query_traces();
    if (!traces) {
      send_message(({ M_WRITE,
                      M_PL_THE, M_PL_VERB, "don't", " see any traces on ",
                      M_THE, M_OBJECT, e[E_TARGET], "." }));
      return -1;  // intermediate solution for 'responsible but not successful'
    }
    else {
      mixed *found;
      found = filter(m_indices(mkmapping(traces - ({ 0 }))),
                     (: this_player()->get_cache($1, finds_trace($1)) :));
      found = map(found, #'describe_trace);
      while (sizeof(found) > 1)
        if (sizeof(found) > 2)
          found = ({ found[0] + ({ "," }) + found[1] }) + found[2..];
        else
          found = ({ found[0] + ({ " and" }) + found[1] });
      if (sizeof(found) == 0)
        send_message(({ M_WRITE,
                        M_PL_THE, M_PL_VERB, "don't", " find any traces." }));
      else
        send_message(({ M_WRITE,
                        M_PL_THE, M_PL_VERB, "find" }) + found[0] + ({ "." }));
    }
    return 1;
  }
  return (e[E_TARGET]->apply_action(query_skill(), sk, e));
}

private void receive_search_event(mapping e, string type, int prio) {
  if (type != "search" || prio != EPRIO_HANDLE)
    return;
  e[E_HANDLED] = 1;
  e[E_SUCCESS] = with_player(e[E_AGENT], #'apply_search_action, e);
  if (e[E_SUCCESS] > 0)
    e[E_AGENT]->decrease_saturation();  // Coogan, 01-Apr-2003
}

void notify_destruct() {
  set_global_listening_event("search", 0);
  unlisten_event("search", EPRIO_HANDLE, #'receive_search_event);
}

