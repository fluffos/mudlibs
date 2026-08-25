/* pwd.c
 * Externalized by Baldrick dec '97
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}

protected int cmd(string str, object me) 
  {
  write(me->query_path()+"\n");
  this_object()->set_trivial_action();
  return 1;
}

