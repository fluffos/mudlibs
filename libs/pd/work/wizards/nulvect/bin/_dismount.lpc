
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <dismount>\n\n"
    "This lets you dismount from whatever you're riding.",
    this_player() );
}

int cmd_dismount(string str) {
  object tp = this_player();
  object who;
  string msg;
  mixed tmp;

  if (!objectp(who = tp->query_riding()))
    FAIL("You are not riding anything.");

  if (tmp = who->query_unmount_message())
    msg = tmp;
  else
    msg = "You dismount from "+who->query_cap_name()+".";

  message("info", msg, tp);
  message("info", tp->query_cap_name()+" dismounts from "+
    who->query_cap_name()+".", environment(tp), ({ tp, who }) );
  message("info", tp->query_cap_name()+" dismounts.", who);
  
  tp->remove_riding();
  who->remove_rider(tp);
  
  return 1;
}

