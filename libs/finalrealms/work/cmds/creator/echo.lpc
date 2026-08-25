/* echo.c
 * Externalized by Baldrick jun '97
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;


void setup(){

position = 1;
}

protected int cmd(string str, object me) 
  {
  if (!str || str == "") {
    notify_fail("Syntax : echo <text>\n");
    return 0;
  }
  log_file("ECHOS", ctime(time())+" "+ me->query_name()+" echo's: "+
                    str+"\n");
  str += "%^RESET%^";
  me->my_mess("You echo: ", str);
  event(environment(me), "player_echo", str + "\n");
  me->set_trivial_action();
  return 1;
} /* do_echo() */
 
