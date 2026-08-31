
#include <std.h>
#include <rooms.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "scout" &&
      tp->query_skill("perception") >= 15*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <hawkeye [direction]>\n\n"
    "Masters of perception, scouts can use this ability to see "
    "for long distances.",
    this_player() );
}

int can_cast(object tp, string dir) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_blind())
    FAIL("You cannot see.");

  if (!strlen(dir) || environment(tp)->query_exit(dir) == ROOM_VOID)
    FAIL("You cannot see far in that direction.");

  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 10)
    FAIL("You are too tired.");

  return 1;
}

int cmd_hawkeye(string str) {
  object tp = this_player();
  object env = environment(tp);
  object prev;
  object *all = ({});
  string file, out = "";
  int x;
  
  if (!abil()) return 0;

  switch (str) {
    case "n": str = "north"; break;
    case "s": str = "south"; break;
    case "e": str = "east"; break;
    case "w": str = "west"; break;
    case "ne": str = "northeast"; break;
    case "nw": str = "northwest"; break;
    case "se": str = "southeast"; break;
    case "sw": str = "southwest"; break;
    case "u": str = "up"; break;
    case "d": str = "down"; break;
  }

  if (!can_cast(tp, str)) return 0;

  // see another room for every 7 levels of maxed perception
  // (not counting the amount needed to gain this ability)
  // minimum of 3 rooms
  x = tp->query_skill("perception");
  x -= (15*6);
  x /= (7*6);
  x += 3;

  prev = env;
  while ((file = prev->query_exit(str)) != ROOM_VOID && x--) {
    object room = load_object(file);
    string tmp;
    if (room == env || member_array(room, all) != -1)
      break;

    out += MAPPER_D->mapper(room);
    tmp = room->describe_living_contents( ({}) );
    if (strlen(tmp))
      out += replace_string(tmp, "\n", ", ")+RES+"\n";
    if (prev == env) {
      tmp = room->describe_item_contents( ({}) );
      if (strlen(tmp))
        out += replace_string(tmp, "\n", ", ")+RES+"\n";
    }
    out += "------\n\n";

    all += ({ room });
    prev = room;
  }

  if (!sizeof(all) || !strlen(out))
    message("info", "You cannot see far in that direction.", tp);
  else {
    tp->add_sp(-(10+random(3)-random(3)));
    tp->set_disable(1);
    message("info", "You gaze "+str+" for a moment...\n\n"+out, tp);
    message("info", tp->query_cap_name()+" "+COL+"gazes"+RES+
        " "+str+" for a moment.", env, tp);
  }

  return 1;
}

