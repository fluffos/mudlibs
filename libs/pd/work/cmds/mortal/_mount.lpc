
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <mount [living]>\n\n"
    "Lets you try to ride a living thing. Only some races can "
    "carry others on their backs. To ride a player, that player "
    "must use <allow> to give you permission first.",
    this_player() );
}

int cmd_mount(string str) {
  object tp = this_player();
  object env = environment(tp);
  object who;
  mixed tmp;
  string msg;
  int mob;

  if (str && sscanf(str, "%s %s", tmp, msg) == 2 && tmp == "allow")
    return load_object("/cmds/mortal/_allow")->cmd_allow(msg+" to mount");

  if (tp->query_rideable())
    FAIL("Your body is not suited to riding on others.");

  if (objectp(tmp = tp->query_riding()))
    FAIL("You are already mounted on "+tmp->query_cap_name()+"!");
  
  if (str)
    who = present(str, env);

  if (!who)
    FAIL("Mount what?");

  mob = !userp(who);
  
  if (!who->query_rideable())
    FAIL("You cannot ride "+(mob?"that":who->query_objective())+".");

  if (sizeof(who->query_riders()) >= who->query_max_riders())
    FAIL(who->query_cap_name()+" cannot carry anyone else.");

  if (!who->query_rideallow(tp)) {
    if (mob)
      return 0; // func passed in set_rideallow should send msgs
    else
      FAIL("You should get permission first.");
  }
  
  if (tmp = who->query_mount_message())
    msg = tmp;
  else
    msg = "You mount "+who->query_cap_name()+".";

  message("info", msg, tp);
  message("info", tp->query_cap_name()+" mounts "+who->query_cap_name()+".",
    env, ({ tp, who }) );
  message("info", tp->query_cap_name()+" mounts you.", who);
  
  tp->set_riding(who);
  who->add_rider(tp);
  
  return 1;
}
