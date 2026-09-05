/*
 * pick the pockets of a living.....
 * sas@cs.tu-berlin.de (Ardanna)
 * Modified Aug28 93 muxestba
 * Updated and event added, Coogan, 10-Jan-02
 */

#pragma strong_types

#include <skilltree.h>
#include <server.h>
#include <grammar.h>
#include <event.h>
#include <prop/item.h>
#include <describe.h>

inherit "basic/parser";
inherit "basic/action";

private void receive_picklock_event(mapping e, string type, int prio);

void create() {
  action::create();
  set_skill_path(S_P_PICK_LOCK);
  set_command("pick");
  set_specific("lock");
  set_function("parse_action");

  add_rule("pick lock of "G_INDIRECT" with "G_OBJECT, "pick_lock_indirect");
  add_rule("pick lock of "G_INDIRECT" with "G_TEXT,   "pick_lock_indirect");
  add_rule("pick lock of "G_INDIRECT,                 "pick_lock_indirect");
  add_rule("pick lock of "G_TEXT,                     "pick_lock_error");
  add_rule("pick lock",                               "pick_lock_error");
  add_error_message("pick", ({ "Pick what?\n", -1 }));

  set_global_listening_event("pick_lock", 1);
  listen_event("pick_lock", EPRIO_HANDLE, #'receive_picklock_event);
}

string *init_living(object ob) {
#if 0  // not yet, Coogan.
  if (!ob || ob->query_skill(query_skill_path()) < 1)
    return 0;  // one must know it to be able to do it
#endif
  return ({({ "pick", 0, "parse_action" })});
}

string query_info(string str) {
  return
    "This skill helps you to pick locks, the higher your skill the more\n"
    "difficult locks you can pick. It helps a lot if you are wielding\n"
    "a lockpick when using this skill. You might want to pick the lock \n"
    "of something (ie 'pick lock of chest').\n";
}

private int apply_picklock_action(mapping e) {
  mixed sk;
  sk = this_player()->query_modified_skills(([ S_M_PICK_LOCK : 50,
                                               S_P_PICK_LOCK : 50 ]));
  sk = (sk[S_M_PICK_LOCK] + sk[S_P_PICK_LOCK])/2;
  return (e[E_TARGET]->apply_action(query_skill(), sk, e));
}

private void receive_picklock_event(mapping e, string type, int prio) {
  if (type != "pick_lock" || prio != EPRIO_HANDLE)
    return;
  e[E_HANDLED] = 1;
  e[E_SUCCESS] = with_player(e[E_AGENT], #'apply_picklock_action, e);
}

int do_action(string action, mapping args) {
  mapping event;
  object lp, to_pick;

  switch (action) {
  case "pick_lock_error":
    if (args[G_TEXT] && !environment(this_player())->id(args[G_TEXT]))
      notify_fail("No " + args[G_TEXT] +
                  " with a lock you could pick is around here.\n");
    else
      notify_fail("What lock do you want to pick?\n");
    return 0;

  case "pick_lock_env":
    event = ([ E_AGENT  : this_player(),   
               E_TARGET : environment(this_player()),
               E_ID     : args[G_TEXT],
            ]);
    break;
               
  case "pick_lock_indirect":
    event = ([ E_AGENT  : this_player(),
               E_TARGET : args[G_INDIRECT,0],
               E_ID     : args[G_INDIRECT,1] || to_pick->query_name(), 
            ]);
    if (args[G_TEXT]) {
      object kr;
      if ((kr = present("keyring", this_player())) &&
          (lp = present(args[G_TEXT], kr)))
        ;
      else {
        notify_fail("What do you want to use to pick?\n", 1);
        return 0;
      }
    }
    break;

  default:
    return 0;
  }
  if (!lp) {
    if (!args[G_OBJECT])
      lp = present("lockpicks", this_player()) || this_player()->query_wield();
    else
      lp = args[G_OBJECT];
  }
  event[E_KEY]  = lp;
  event[E_TOOL] = lp;
  send_event("pick_lock", event, environment(this_player()));
  if (event[E_CANCELLED])
    return 1;
  if (event[E_SUCCESS] > 0) {
    if (event[E_SUCCESS] > 1)
      this_player()->add_skill_points(query_skill_path(), event[E_SUCCESS]);
    else {
      this_player()->add_skill_points(query_skill_path(),
                                      SE_SKILLS->query_reward(this_player(),
                                                            event[E_SUCCESS],
                                                            50, S_P_PICK_LOCK));
      this_player()->improve_skill(S_M_PICK_LOCK, event[E_SUCCESS], 50);
    }
  } else
    notify_fail("Alas, it is impossible to pick the lock of " +
                describe(args[G_TEXT] || (args[G_INDIRECT]&&args[G_INDIRECT,1]),
                         ARTICLE_THE) + ".\n");
  return event[E_SUCCESS];
}

