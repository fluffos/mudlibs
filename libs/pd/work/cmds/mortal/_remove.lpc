#include <std.h>

inherit DAEMON;

int do_remove(object tp, object armour);

void help() {
  message("help",
    "Syntax: <remove [armour]>\n"
    "        <remove all>\n"
    "\n"
    "This command will let you take off a piece of armour "
    "that you are wearing, or all your armour at once.",
    this_player() );
}

int cmd_remove(string str) {
  object tp = this_player();
  object env = environment(tp);
  mixed unwield;

  if (!str)
    return notify_fail("Remove what?");

  if (str == "all") {
    object *armours = filter(all_inventory(tp), (: $1->query_worn() :) );
    if (!sizeof(armours))
      return notify_fail("You are not wearing anything.");
    foreach (object a in armours)
      do_remove(tp, a);
  }
  else {
    object armour = present(str, tp);
    if (!armour)
      return notify_fail("You do not have a \""+str+"\".");
    return do_remove(tp, armour);
  }

  return 1;
}

int do_remove(object tp, object armour) {

  if (!armour->query_worn())
    return notify_fail("You are not wearing that!");

  tp->set_disable(1);

  armour->unequip();

  return 1;
}

