
#include <std.h>
#include <move.h>

#define TOO_DARK -6

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <put item in container>\n\n"
    "Puts an item into a container like a bag or treasure chest.",
    this_player() );
}

int cmd_put(string str) {
  object tp=this_player();
  object env=environment(tp);
  object what, bag;
  string whatstr, bagstr;
  string whatshort, bagshort;
  int ret;

  if (!(str && sscanf(str, "%s in %s", whatstr, bagstr) == 2))
    FAIL("Put what where?");

  if (total_light(tp) + tp->query_sight_bonus() < TOO_DARK)
    FAIL("It is too dark.");

  what = present(whatstr, tp);
  bag = present(bagstr, tp);
  if (!bag)
    bag = present(bagstr, env);

  if (!what)
    FAIL("You are not carrying "+whatstr+".");

  if (!bag)
    FAIL("You do not see "+bagstr+" here.");

  if (what == bag)
    FAIL("You can't do that.");

  if (what->drop())
    FAIL("You cannot let go of it!");

  whatshort = what->query_short();
  bagshort = bag->query_short();

  ret = what->move(bag);

  switch (ret) {
    case MOVE_NO_ROOM:
      FAIL(capitalize(strip_color(whatshort))+" doesn't fit in "+strip_color(bagshort)+".");
    break;

    case MOVE_NOT_ALLOWED:
      FAIL("You cannot put that in there.");
    break;

    case MOVE_OK:
      message("cmd_put", "You put "+whatshort+" in "+bagshort+".", tp);
      message("cmd_put", tp->query_cap_name()+" puts "+whatshort+
                         " in "+bagshort+".", env, tp);
    break;
    
    default:
      FAIL("Space and time suddenly bend and keep that from happening.");
  }

  return 1;

}


