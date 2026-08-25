/* ehcoto.c
 * Externalized by Baldrick jun '97
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
//inherit "/global/creator/wiz_cmd_base";


void setup(){

position = 1;
}
 
protected int cmd(string str, object me) 
  {
  string who, what;
  object ob;

  if(!str || str == "") {
    notify_fail("Syntax : echoto <player> <text>\n");
    return 0;
  }
  if(sscanf(str, "%s %s", who, what) != 2) {
    notify_fail("Syntax : echoto <player> <text>\n");
    return 0;
  }
  who = lower_case(who);
  who = (string)me->expand_nickname(who);
  ob = find_player(who);
  log_file("ECHOS", ctime(time())+" "+ me->query_cap_name()+
                    " Echoto's "+who+": " +what+"\n");
  what += "%^RESET%^";
  me->my_mess("You echo to " + who + ": ", what);
  event(ob, "player_echo_to", what + "\n");
  me->set_trivial_action();
  return 1;
} /* do_echo_to() */
