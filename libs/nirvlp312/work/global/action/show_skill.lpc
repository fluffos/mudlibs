/*
 * the action handler for the 'show skill' action.
 *
 * Updated by Coogan, 04-Jan-02
 *
 */

#pragma strong_types

#include <skills.h>
#include <skilltree.h>
#include <grammar.h>
#include <libs.h>

inherit "basic/parser";
inherit "basic/action";

private int step;

void create() {
  action::create();
  set_skill_path(S_LORE);
  set_reward(0);
  set_command("show");
  set_specific("skill");
  set_function("parse_action");
#if 0
  step = sizeof(SKILL_RATING) - 1;
#endif
  add_rule("show skill levels",       "show_skill_levels");
  add_rule("show skill tree percent real", "show_skill_tree_percent_real");
  add_rule("show skill tree percent", "show_skill_tree_percent");
  add_rule("show skill tree",         "show_skill_tree");
  add_rule("show skill G_WORD",       "show_skill_error");
  add_rule("show skill",              "show_skills");
  add_error_message("show",
                    ({ "You can only display 'skill', 'skill tree' or "
                       "'skill levels'.\n", -1 }));
}

varargs string get_total(string *path, status in_percent, status real) {
  if (in_percent) {
    if (real)
      return sprintf("%4d %%", this_player()->query_modified_skill(path));
    else
      return sprintf("%4d %%", this_player()->query_skill(path));
  }
  else
    return LIB_SKILLS->query_level_description(
                                        this_player()->query_skill(path));
}

private void write_skill(mixed *node, string tab, int depth, string *path) {
  int i, last;

  if (1 || depth) { /* muxestba */
    last = sizeof(path);
    path += ({ "" });

    for (i=0; i<sizeof(node); i++) {
      path[last] = node[i][0];
      if (sizeof(node[i][2]) == 0) { /*write only leaves...*/
        write(tab + node[i][0] + ":\t");
        write(get_total(path)+"\n");
      }
      write_skill(node[i][2], tab, depth-1, path);
    }
  }
}

private void show_skill(mixed* elem, int depth, string *path) {
  write("Your overall mastery of these proficiencies is ");
  write(get_total(path)+".\n");
  write_skill(elem[2], "    ", depth, path);
}

// rewritten and improved, Coogan, 30-Dec-01
private string* get_skill_tree(mixed *node, string tab, int depth,
                               string *path, status in_percent,
                               status real)  {
  int i, last;

  if (depth) {
    string *res;
    last = sizeof(path);
    path += ({""});
    res = ({ });
    for (i=0; i<sizeof(node); i++) {
      path[last] = node[i][0];
      res += ({ tab + node[i][0], get_total(path, in_percent) }) +
             get_skill_tree(node[i][2], tab + "  ", depth-1, path, in_percent,
                            real);
    }
    return res;
  }
}

private varargs void write_skill_tree(mixed *node, string tab, int depth,
                                      string *path, status in_percent,
                                      status real) {
  string result, *res;
  mixed *results;
  int i, j, k, s;

  res = get_skill_tree(node, tab, depth, path, in_percent, real);
  if (!sizeof(res)) {
    show_skill((this_player()->query_skill_tree())[0], 3, ({ }));
    return;
  }
  results = ({ });
  result = "";
  s = sizeof(res);
  j = k = 0;
  for (i = 0; i<s; i+=2) {
    if (res[i][0] != ' ' && j > 0) {
      results += ({ res[k..k+j-1] });
      j = 0;
      k = i;
    }
    j+=2;
  }
  results += ({ res[k..k+j-1] });
  if (sizeof(results) % 2)
    results += ({ ({ "" }) });
  for (i=0; i < sizeof(results); i+=2) {
    j = sizeof(results[i]) - sizeof(results[i+1]);
    res = ({ });
    for (k = 0; k < abs(j); k++)
      res += ({ "" });
    if (j < 0) {
      results[i] += res;
      j = sizeof(results[i+1]);
    } else if (j > 0) {
      results[i+1] += res;
      j = sizeof(results[i]);
    } else {
      j = sizeof(results[i]);  // forgot this case, Coogan, 12-Jan-02
    }
    for (k = 0; k < j; k+=2) {
      result += sprintf("%-21s %-17s|%-21s %-17s\n",
                        results[i][k],
                        results[i][k+1],
                        results[i+1][k],
                        results[i+1][k+1]);
    }
  }
  write(result);
}

private mixed* find_skill(mixed *node, string *path) { 
  int i;
  string rest;

  for (i=0; i<sizeof(node); i++) {
    if (path[0] == node[i][0]) {
      if (sizeof(path) == 1)
        return node[i];
      else
        return find_skill(node[i][2], path[1..sizeof (path)-1]);
    }
  }
  return 0;
}

int do_action(string verb, mapping args) {
  switch (verb) {
  case "show_skill_levels":
    message(break_string("Skill levels are " +
#if 0
                         implode(SKILL_RATING,", ")
#else
                         implode(LIB_SKILLS->query_level_descriptions(), ", ")
#endif
                         + ".", 72) + "\n");
    return 1;

  case "show_skill_tree":
    write_skill_tree((this_player()->query_skill_tree())[0][2], "", -1,
                     ({ "skill" }));
    return 1;

  case "show_skill_tree_percent":
    write_skill_tree((this_player()->query_skill_tree())[0][2], "", -1,
                     ({ "skill" }), 1);
    return 1;

  case "show_skill_tree_percent_real":
    write_skill_tree((this_player()->query_skill_tree())[0][2], "", -1,
                     ({ "skill" }), 1, 1);
    return 1;

  case "show_skills":
    show_skill((this_player()->query_skill_tree())[0], 3, ({ }));
    return 1;

  case "show_skill_error":
    notify_fail("You can only display 'skill', 'skill tree' or "
                "'skill levels'.\n");  // fall through
  default:
    return 0;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

string query_info(string str) {
  return "This will show your current prowess in certain skills to you.\n"
         "You can display 'skill', 'skill tree' or 'skill levels'.\n";
}

string *init_living(object ob) {
  return ({({ "show", 0, "parse_action" })});
}

