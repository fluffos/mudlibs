
#include <std.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <survey>\n\n"
    "This allows you to do a quick check for living things "
    "and objects in adjacent rooms.\n\n"
    "See also: peer",
    this_player() );
}

int cmd_survey(string str) {
  object tp = this_player();
  object env = environment(tp);
  string *exits;
  string msgout = "";

  if (effective_light(tp) < -6)
    return notify_fail("It is too dark.\n");

  if (!env)
    return notify_fail("You are nowhere.\n");

  exits = env->query_exits();

  if (!sizeof(exits))
    return notify_fail("There are no exits!\n");

  foreach (string exit in exits) {
    object dest;
    object *ai, *livs, *items;
    string file;
    string *doors, *races;
    int si, sl;

    if (env->invis_exit(exit)) continue;

    doors = env->query_doors_blocking_exit(exit);
    if (sizeof(doors))
      doors = filter(doors, (: $2->query_closed($1) :), env);
    if (sizeof(doors)) {
      doors = map(doors, (: indefinite_article($2->query_door_name($1)) :), env);
      msgout +=
        capitalize(list(doors, 1))+" "+(sizeof(doors) == 1 ? "is" : "are")+
        " blocking the view "+exit+".\n";
      continue;
    }

    file = env->query_exit(exit);
    dest = find_object(file) || load_object(file);
    if (!dest) continue;

    ai = all_inventory(dest);
    // disregard anything invisible

    ai = filter(ai, (: (!$1->query_invis($(tp)) && $1->query_short()) :) );
    livs = filter(ai, (: $1->is_living() :) );
    items = ai - livs;

    sl = sizeof(livs);
    si = sizeof(items);

    if (!sl && !si) {
      msgout += "You see nothing "+exit+".\n";
      continue;
    }

    if (si == 1)
      msgout += "You see an object "+exit+".\n";
    else if (si > 1)
      msgout += "You see "+cardinal(si)+" objects "+exit+".\n";

    if (sl) {
      races = livs->query_race();
      races = consolidate_string(races);
      foreach (string r in races)
        msgout += "You see "+r+" "+exit+".\n";
    }

  } // end foreach

  message("info", msgout, tp);

  return 1;
}


    
