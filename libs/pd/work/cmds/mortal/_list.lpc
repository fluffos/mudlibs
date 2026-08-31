
#include <std.h>
#include <daemons.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <list [channel]>\n\n"
    "Lists all the players who are listening to a particular channel.",
    this_player() );
}

int cmd_list(string str) {
  object tp=this_player();
  object *ppl;
  string msg;

  return CHAT_D->list_channel(str);;

  if (!str)
    return notify_fail("Syntax: <list [channel]>\n");

  if (!CHAT_D->query_is_channel(str) ||
      !CHAT_D->query_listening(tp, str))
        return notify_fail("Invalid line.\n");

  ppl = CHAT_D->query_listeners(str);

  msg = "Online:";

  foreach (object person in ppl) {
    if (!person) continue;
    if (hiddenp(person)) continue;
    if (person->query_invis()) continue;
    if (person->query_blocked(str)) continue;
    msg += " "+person->query_cap_name();
  }

  message("info", msg, tp);

  return 1;
}
