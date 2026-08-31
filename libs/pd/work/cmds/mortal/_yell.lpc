
#include <std.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <yell [message]>\n\n"
    "You can yell loudly and people in surrounding rooms will hear you. "
    "The sound dissipates with distance, and it takes a bit of strength.\n"
    "See also: say, whisper, emote, shout\n",
    this_player() );
}

int cmd_yell(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *prim, *sec;

  if (tp->query_ghost()) {
    message("emote", "You howl pitifully.", tp);
    message("emote", "You hear the howling of a ghost.", env, tp);
    return 1;
  }

  if (tp->query_sp() < 5)
    return notify_fail("You are too tired to yell.\n");

  if (!str)
    return notify_fail("Sore throat?\n");

  tp->add_sp(-5);

  if (env->query_property("no shout"))
    return notify_fail("Your voice does not travel far.\n");

  if (!env->is_room())
    return notify_fail("Something is wrong.\n");

  prim = ({});
  sec = ({});

  foreach (string room in env->query_destinations()) {
    object r = load_object(room);

    if (objectp(r) && member_array(r, prim) == -1)
      prim += ({ r });
  }

  foreach (object proom in prim) {
    foreach (string sroom in proom->query_destinations()) {
      object q = load_object(sroom);
      if (objectp(q) && member_array(q, sec) == -1)
        sec += ({ q });
    }
  }

  prim -= ({ env });
  sec -= prim;
  sec -= ({ env });

  message("yell", "You yell: "+str, tp);
  message("yell", tp->query_cap_name()+" yells: "+str, prim + ({ env }), tp);
  message("yell", tp->query_cap_name()+" yells from nearby: "+str, sec, ({ tp, env }) );

  return 1;
}
    
