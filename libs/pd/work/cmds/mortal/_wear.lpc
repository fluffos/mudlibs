#include <std.h>

#define FEWER_FINGERS_PENALTY 1

inherit DAEMON;

varargs int do_equip(object tp, object armour, int flag, string where);

void help() {
  message("help",
    "Syntax: <wear [armour] (on [limb1, limb2, ...])>\n"
    "        <wear all>\n"
    "\n"
    "This command allows you to wear armour to protect you.\n"
    "Note that not all races can wear all kinds of armour, "
    "hooved races for example cannot wear boots. Wearing gloves "
    "with more fingers than you will incur a small penalty to "
    "their effectiveness, and it's not possible to wear gloves "
    "with less fingers.\n"
    "\n"
    "Examples: <wear boots> will automatically pick where to wear them\n"
    "          <wear boots on left foot> to specify limbs to use\n",
    this_player() );
}

int cmd_wear(string str) {
  object tp = this_player();
  object env = environment(tp);

  if (!str)
    return notify_fail("Wear what?");

  if (tp->query("bear") || tp->query("lion") || tp->query("wolf"))
    return notify_fail("Your armour will not fit in this form.");

  if (str == "all") {
    object *armours = filter(all_inventory(tp), (: $1->is_armour() :) );
    if (!sizeof(armours))
      return notify_fail("You have nothing to wear.");
    foreach (object a in armours)
      do_equip(tp, a, 1);
  }

  else {
    object armour;
    string what, where;
    if (sscanf(str, "%s on %s", what, where) != 2)
      what = str;
    armour = present(what, tp);
    if (!armour)
      return notify_fail("You don't have a \""+what+"\" to wear.");
    return do_equip(tp, armour, 0, where);
  }

  return 1;
}

varargs int do_equip(object tp, object armour, int flag, string where) {
  int fingers;
  int penalty;
  string *limbs;
  string errorcheck;

  if (!tp || !armour) return 0;

  if (armour->query_worn())
    return notify_fail("You are already wearing that!");

  if (tp->query_race() == "dragon" &&
      !(armour->query_type() == "ring" || armour->query_property("dragon wear")))
        return notify_fail("Your scales are armour enough!");

  if ((fingers = armour->query_fingers())) {
    fingers = tp->query_fingers() - fingers;
    if (fingers > 0)
      return notify_fail("You have too many fingers to wear that.");
    if (fingers < 0)
      penalty = FEWER_FINGERS_PENALTY;
  }

  if (where) {
    string *trylimbs;
    string tmp = where;
    tmp = replace_string(tmp, " and ", ",");
    tmp = replace_string(tmp, " ,", ",");
    tmp = replace_string(tmp, ", ", ",");
    trylimbs = explode(tmp, ",");
    
    if (!armour->query_can_equip(trylimbs))
      return notify_fail("You cannot wear that on your "+where+".");

    limbs = trylimbs;
  }
  else {
    if (armour->query_type() == "ring")
      limbs = ({});
    else
      limbs = armour->query_limbs();
  }

  errorcheck = armour->equip(tp, limbs, 0, penalty);

  if (errorcheck)
    return notify_fail(errorcheck);

  tp->set_disable(1);

  return 1;
}

