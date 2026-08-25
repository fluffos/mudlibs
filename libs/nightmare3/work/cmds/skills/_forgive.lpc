//  _forgive.c
//  A command to change a players outlaw status
//  For the Nightmare Mudlib
//  Written 941001 by manny@Nightmare

#include <std.h>
#include <council.h>

inherit DAEMON;

object who, tp;

cmd_forgive(string str) {
  tp=this_player();
  if(!justicep(tp)) return 0;
  if(!str)
    return notify_fail("Syntax: forgive <who>\n");
  if(!who=present(str, environment(tp))) {
    message("my_action", "You don't see "+capitalize(str)+
      " here.", tp);
    return 1;
  }
  if(!who->query_outlaw()) {
    message("my_action", who->query_cap_name()+" is not an outlaw.",
      tp);
    return 1;
  }
  who->set_outaw(0);
  message("my_action", "You impart mercy upon "+who->query_cap_name()+".",
    tp);
  message("my_action", "You have been forgiven of your transgressions!", 
    who);
  return 1;
}

