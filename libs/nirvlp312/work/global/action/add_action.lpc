/*
 * global/action/add_action.c - add an action to actions (grin)
 * Oct 1991 by marion@cs.tu-berlin.de
 * changed Feb 1992 by marion@cs.tu-berlin.de
 * Updated by Coogan, 08-Jan-02
 */

#pragma strong_types

#include <wizlevels.h>
#include <skilltree.h>
#include <global_actions.h>

inherit "basic/action";

string query_info(string str) {
  return "Use 'action {add|remove} <object>' to add or remove actions object.\n"
         "Use 'action list [path]' to list already used action verbs.\n";
}

string *query_actions() {
  return ({ "action", 0, "command_action" });
}

string *init_living(object ob) {
  if (!ob || ob->query_level() < WL_APPRENTICE)
    return 0; /* disallow */
  return allocate(0); /* no extra commands */
}

private string query_path(string str, int skill_path) {
  if (skill_path)
    return call_other(str, "query_skill_path") || "";
  else
    return str;
}

int command_action(string str) {
  string *argv;
  string ret;
  mixed *a1, *a2;
  string action;
  int i, j;
  int how;      // == 1 means, show the skillpath

  if (!this_player() || this_player()->query_level() < WL_APPRENTICE)
    return 0;
  if (!str || sizeof((argv = explode(str, " "))) < 1)
    return notify_fail(query_info("")), 0;

  switch (argv[0]) {
  case "add":
    if (sizeof(argv) < 2) {
      notify_fail(argv[0] + " what?\n");
    } else {
      ret = ACTION->new_action(argv[1]);
      write(ret + ".\n");
    }
    return 1;

  case "remove":
    if (sizeof(argv) < 2) {
      notify_fail(argv[0] + " what?\n");
    } else {
      ret = ACTION->remove_action(argv[1]);
      write(ret + ".\n");
    }
    return 1;

  case "list":
    if (sizeof(argv) > 1 && argv[1]=="path")
      how = 1;
    a1 = ACTION->query_action();
    a2 = ACTION->query_method();
    if (how)
      write("PRIMARY   SECONDARY           SKILLPATH\n");
    else
      write("PRIMARY   SECONDARY           OBJECT\n");
    for (i = 0; i < sizeof(a1); i++) {
      action = a1[i];
      if (!a2[i][0])    // only one action
        printf("%-30s%s\n", action, query_path(a2[i][1][0][1], how));
      else
        for (j = 0; j < sizeof(a2[i][0]); j++)
          printf("%-10s%-20s%s\n", (j ? "" : action), a2[i][0][j],
                                   query_path(a2[i][1][j][1], how));
    }
    return 1;
  }
  return 0;
}

void create() {
  action::create();
  set_skill_path(S_LORE);
  set_command("action");
  set_specific(0);
  set_reward(0);
}

