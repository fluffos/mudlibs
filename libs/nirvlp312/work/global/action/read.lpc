/*
 * logic/read.c - give a read skill
 * Mar 1992 by marion@cs.tu-berlin.de
 * Parsing rewritten by Ugh 1996
 * updated and events added, Coogan, 09-Jan-02
 */

#pragma strong_types

#include <skilltree.h>
#include <grammar.h>
#include <describe.h>
#include <server.h>
#include <event.h>

inherit "basic/parser";
inherit "basic/action";

#define DEFAULT_PERCENT	80

private void receive_read_event(mapping e, string type, int prio);


void create() {
  action::create();
  set_skill_path(S_READ);
  set_command("read");
  set_specific(0);
  set_function("command_read");
  add_rule("read "G_WORDS" of "G_OBJECT, "read_part");  // Coogan, 13-Jul-2004
  add_rule("read "G_OBJECT" "G_WORDS,    "read_part");  // Coogan, 13-Jul-2004
  add_rule("read "G_OBJECT, "read");
  add_rule("read "G_ALL,    "read_all");
  add_rule("read "G_TEXT,   "read_typo");
  add_error_message("read", ({ "Read what?\n", -1 }));

  set_global_listening_event("read", 1);
  listen_event("read", EPRIO_HANDLE, #'receive_read_event);
}

private int apply_read_action(mapping e) {
  int sk;
  sk = this_player()->query_modified_skill(query_skill_path());
  return (e[E_TARGET]->apply_action(query_skill(), sk, e));
}

private void receive_read_event(mapping e, string type, int prio) {
  if (type != "read" || prio != EPRIO_HANDLE)
    return;
  e[E_HANDLED] = 1;
  e[E_SUCCESS] = with_player(e[E_AGENT], #'apply_read_action, e);
}

int action_read_map(object ob, string desc) {
  int ret;
  mapping event;

  event = ([ E_AGENT    : this_player(),
             E_TARGET   : ob,
             E_ID       : desc || ob->query_name(),
          ]);
  send_event("read", event, environment(this_player()));
  if (event[E_CANCELLED])
    return 1;
  if (event[E_SUCCESS] > 0) {
    if (event[E_SUCCESS] > 1)
      this_player()->add_skill_points(query_skill_path(), event[E_SUCCESS]);
    else if (random(100) < DEFAULT_PERCENT)
      this_player()->add_skill_points(query_skill_path(),
                                      SE_SKILLS->query_reward(this_player(),
                                                              event[E_SUCCESS],
                                                              50, S_READ));
  } else
    notify_fail("You can't read "+
                describe(event[E_TARGET], ARTICLE_THE) + ".\n"), 0;
  return event[E_SUCCESS];
}

int command_read(string str, int line) {
  string desc;

  if (this_player()->test_darkness(environment(this_player()), 1)) {
    notify_fail("It is too dark to read.\n");
    return 0;
  }
  if (this_player()->test_brightness(environment(this_player()), 1)) {
    notify_fail("It is too bright to read.\n");
    return 0;
  }
  return parse_sentence(str ? "read "+str : "read");
}

int do_action(string action, mapping args) {
  int success, i;
  string error, name;
  object *not_read;
  mixed h;

  switch (action) {
  case "read_typo":
    if (!present(args[G_TEXT], environment(this_player())) &&
        !present(args[G_TEXT], this_player()) &&
        !environment(this_player())->query_fakeitem_id(args[G_TEXT]))
      notify_fail("There is no "+args[G_TEXT]+" here!\n");
    return 0;

  // added this case, Coogan, 13-Jul-2004
  case "read_part":
    if (!action_read_map(args[G_OBJECT], args[G_WORDS]))
      return notify_fail("You can't read "+
                         describe(args[G_WORDS],ARTICLE_THE)+".\n");
    return 1;

  case "read":
    if (!action_read_map(args[G_OBJECT], args[G_OBJECT,1]))
      return notify_fail("You can't read "+
                         describe(args[G_OBJECT,1],ARTICLE_THE)+".\n");
    return 1;

  case "read_all":
    error = "";
    name = args[G_ALL,1][0];
    args[G_ALL] = filter_objects(args[G_ALL], "short");
    args[G_ALL,1][1] = sizeof(args[G_ALL]);
    not_read = ({ });
    for (i=0; i<args[G_ALL,1][1]; i++)
      if (!action_read_map(args[G_ALL][i],
		           /* if name==0 ('all') take the name */
		           name||lower_case(args[G_ALL][i]->query_name()||"") ))
	not_read += ({ name || args[G_ALL][i] });
      else 
	success = 1;
    h = describe_list(not_read, ARTICLE_THE);
    notify_fail("You can't read "+make_list(h,"that")+".\n",
                (action == "read_all"));  // higher prio than 0!
    return success;
  }
  return 0;
}

string query_info(string str) {
  return "Every being is able to read common.\n"
         "But some things are quite difficult to read.\n";
}

