/*
 * clothing.c
 *
 * This object is used for hats, robes, scarves, necklaces, and the works as
 * items of fashion as opposed to items of protection. Note, also, that
 * armour types slowly decay as they are bashed about, these items are
 * always as good as if they were just coded.
 */

#include "/include/mudlib.h"
inherit BASE;

#define NAME (string)this_player()->query_name()

status worn;

void init() {
  ::init();
  add_action("wear", "wear");
  add_action("remove", "remove");
}

status get() { return 1; }

status drop(status silently) {
  if (worn && !silently) {
    tell_object(environment(), "You drop your worn " + query_name() + ".\n");
  }
  worn = 0;
  return 0;
}

string short(status wiz) {
  if (!::short(wiz)) return 0;
  return ::short(wiz) + ((worn) ? " (worn)" : "");
}

status wear(string str) {
  int i;
  object ob;

  if (!str) {
    notify_fail("Wear what?\n");
    return 0;
  }
  if (!(ob = present(str, this_player()))) {
    notify_fail("You do not have a " + str + ".\n");
    return 0;
  }
  if (ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if (worn) {
    write("You already wear it!\n");
    return 1;
  }
  sscanf(str, "%s %d", str, i);
  for (i=1; (ob = present(str + " " + i, this_player())); i++) {
    if (ob->query_worn()) {
      write("You are already wearing a " + query_name() + ".\n");
      return 1;
    }
  }
  write("You wear " + query_name() + ".\n");
  say(NAME + " wears " + query_name() + ".\n");
  worn = 1;
  return 1;
}

status query_worn() { return worn; }

status remove(string str) {
  int i;
  object ob;

  if (!str) {
    notify_fail("Remove what?\n");
    return 0;
  }
  if (!(ob = present(str, this_player()))) {
    notify_fail("You do not have a " + str + ".\n");
    return 0;
  }
  if (ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if (!worn) {
    write("You are not wearing it.\n");
    return 1;
  }
  write("You remove your " + query_name() + ".\n");
  say(NAME + " removes " + query_name() + ".\n");
  worn = 0;
  return 1;
}

