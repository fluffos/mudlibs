
#include <std.h>

#define FAIL(s) return notify_fail(strip_color(s)+"\n")
#define CAP(s) capitalize(strip_color(s))

inherit DAEMON;

int open_container(object tp, object env, object bag);

void help() {
  message("help",
    "Syntax: <open container>\n"
    "        <open door>\n\n",
    "Lets you open a closed container or door, providing it isn't locked.",
    this_player() );
}

int cmd_open(string str) {
  object tp=this_player();
  object env=environment(tp);
  object bag;
  int flag;

  if (!str || str == "")
    FAIL("Open what?");

  bag = present(str, tp);
  if (!bag)
    bag = present(str, env);
  if (!bag)
    if (!(flag = env->is_door(str)))
      FAIL("Open what?");

  if (flag) {
    env->event_open(tp, str);
    return 1;
  }

  else
    return open_container(tp, env, bag);
  
  return 1;
}

int open_container(object tp, object env, object bag) {
  
  string bagshort;
  
  bagshort = bag->query_short();

  if (bag->query_locked())
    FAIL(CAP(bagshort)+" is locked.");

  if (!bag->query_can_close())
    FAIL(CAP(bagshort)+" cannot be closed.");
  
  if (!bag->query_closed())
    FAIL(CAP(bagshort)+" is already opened.");

  bag->set_closed(0);

  message("cmd_open", "You open "+bagshort+".", tp);
  message("cmd_open", tp->query_cap_name()+" opens "+bagshort+".", env, tp);

  return 1;
}
