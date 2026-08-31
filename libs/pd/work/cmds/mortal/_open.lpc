
#include <std.h>

#define FAIL(s) return notify_fail(strip_color(s)+"\n")
#define CAP(s) capitalize(strip_color(s))

inherit DAEMON;

int open_door(string);
int open_bag(string);

void help() {
  message("help",
    "Syntax: <open container>\n"
    "        <open door>\n\n"
    "Lets you open a closed container, providing it "
    "isn't locked. You can also open doors by name or direction.",
    this_player() );
}

int cmd_open(string str) {
  object tp = this_player();
  object env = environment(tp);
  int ret;

  if (str && sizeof(env->query_doors())) ret = open_door(str);
  if (!ret) return open_bag(str);
  return ret;
}

int open_door(string str) {
  object tp = this_player();
  object env = environment(tp);
  string *doors;

  if (!str) FAIL("Open what?");
  str = remove_article(str);

  doors = env->query_doors_blocking_exit(str);
  if (!sizeof(doors)) doors = ({ env->query_door_id(str) });

  doors = filter(doors, (: ($1 != 0) :) );

  if (!sizeof(doors)) FAIL("There is no "+str+" here.");

  foreach (string id in doors)
    env->event_open(tp, id);

  return 1;
}

int open_bag(string str) {
  object tp=this_player();
  object env=environment(tp);
  object bag;
  string bagshort;

  if (!str || str == "")
    FAIL("Open what?");

  bag = present(str, tp);
  if (!bag)
    bag = present(str, env);
  if (!bag)
    FAIL("You do not have "+str+".");

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

