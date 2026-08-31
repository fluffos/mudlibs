
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <buck [living]>\n\n"
    "This makes you buck off someone who's riding you.",
    this_player() );
}

int cmd_buck(string str) {
  object tp = this_player();
  object env = environment(tp);
  object who;
  object *tmp;

  if (str)
    who = present(str, env);

  if (!who && sizeof(tmp = tp->query_riders()) == 1)
    who = tmp[0];

  if (!objectp(who))
    FAIL("Buck who?");

  if (who->query_riding() != tp)
    FAIL(who->query_cap_name()+" is not riding you.");

  message("info", "You buck "+who->query_cap_name()+" off.", tp);
  message("info", tp->query_cap_name()+" bucks you off.", who);
  message("info", tp->query_cap_name()+" bucks "+
    who->query_cap_name()+" off.", env, ({ tp, who }) );

  tp->remove_rider(who);
  who->remove_riding();

  return 1;
}

