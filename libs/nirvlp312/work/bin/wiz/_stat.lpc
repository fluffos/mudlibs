/*
// /bin/_stat.c
//
// Daemonized by Shadowhawk.
*/

#include <security.h>

#pragma strict_types
#pragma save_types

int
cmd_stat(string name) {
  object ob;
  
  if (!name || (int)this_player()->query_level() < CREATE)
    return 0;
  name = lower_case(name);
  if(!(ob=present(name, environment(this_player()))) || !living(ob))  /* by verte */
  ob = find_living(name);
  if (!ob) {
    write("No such person is playing now.\n");
    return 1;
  }
  if (name != (string)this_player()->query_real_name() &&
      (int)ob->query_invis() > 99 &&
      (int)this_player()->query_level() < (int)ob->query_level()) {
    write("No such person is playing now.\n");
    return 1;
  }
  ob->show_stats();
  return 1;
}
