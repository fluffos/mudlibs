
#include <std.h>

#define FAIL(s) return notify_fail(strip_color(s)+"\n")
#define CAP(s) capitalize(strip_color(s))

inherit DAEMON;

int close_container(object tp, object env, object bag);

void help() {
  message("help",
    "Syntax: <close container>\n"
    "        <close door>\n\n"
    "Closes containers like bags or packs, or doors.",
    this_player() );
}

int cmd_close(string str) {
  object tp=this_player();
  object env=environment(tp);
  object bag;
  int flag;

  if (!str || str == "")
    FAIL("Close what?");

  bag = present(str, tp);
  if (!bag)
    bag = present(str, env);
  if (!bag)
    if (!(flag = env->is_door(str)))
      FAIL("Close what?");

  if (flag) {
    env->event_close(tp, str);
    return 1;
  }
  else
    return close_container(tp, env, bag);

  return 1;
}

int close_container(object tp, object env, object bag) {
  string bagshort;

  bagshort = bag->query_short();
  
  if (bag->query_locked())
    FAIL("The lock is stuck and in the way of closing it.");

  if (!bag->query_can_close())
    FAIL(CAP(bagshort)+" cannot be closed.");
  
  if (bag->query_closed())
    FAIL(CAP(bagshort)+" is already closed.");

  bag->set_closed(1);

  message("cmd_close", "You close "+bagshort+".", tp);
  message("cmd_close", tp->query_cap_name()+" closes "+bagshort+".", env, tp);

  return 1;
}

