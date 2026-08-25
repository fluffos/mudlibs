/* gauge.c
 * Externalized by Baldrick jun '97
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}


protected int cmd(string str, object me) {
  int eval_cost;

  if ( me->query_current_action_forced() )
    return 0;
  if(!str) {
    notify_fail("Usage : gauge command.\n");
    return 0;
  }
  eval_cost = command(str);
  write("\nThe command '" + str + "' took: " + eval_cost + " CPU cycles.\n");
  me->set_trivial_action();
  return 1;
} /* do_gauge() */

