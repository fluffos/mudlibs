
#include <std.h>

#define FAIL(s) return notify_fail(strip_color(s)+"\n")
#define CAP(s) capitalize(strip_color(s))

inherit DAEMON;

int close_door(string);
int close_bag(string);


void help() {
  message("help",
    "Syntax: <close container>\n"
    "        <close door>\n\n"
    "Closes a container (such as bags and packs) or closes a door. "
    "You can also <close south> to close the door to the south, "
    "or <close big oak door> to close the door by that name.",
    this_player() );
}

int cmd_close(string str) {
  object tp = this_player();
  object env = environment(tp);
  int ret;

  if (str && sizeof(env->query_doors())) ret = close_door(str);
  if (!ret) return close_bag(str);
  return ret;
}

int close_door(string str) {
  object tp = this_player();
  object env = environment(tp);
  string *doors;

  if (!str) FAIL("Close what?");
  str = remove_article(str);

  doors = env->query_doors_blocking_exit(str);
  if (!sizeof(doors)) doors = ({ env->query_door_id(str) });

  doors = filter(doors, (: ($1 != 0) :) );

  if (!sizeof(doors)) FAIL("There is no "+str+" here.");

  foreach (string id in doors)
    env->event_close(tp, id);

  return 1;
}

int close_bag(string str) {
  object tp=this_player();
  object env=environment(tp);
  object bag;
  string bagshort;

  if (!str || str == "")
    FAIL("Close what?");

  bag = present(str, tp);
  if (!bag)
    bag = present(str, env);
  if (!bag)
    FAIL("You do not have "+str+".");

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

