// Written by Chronos..
#include <mudlib.h>

inherit DAEMON;

int cmd_push(string str) {
  object target, item;
  string work1,work2;
  if (!str) {
    write("Usage: push <object> to <person>\n");
    return 1;
  }
  if (sscanf(str, "%s to %s", work1, work2) != 2) {
    write("Usage: push <object> to <person>\n");
    return 1;
  }
  target = find_player(work2);
  if (!target) {
    write("That player is not logged in right now.\n");
    return 1;
  }
  item = present(work1, this_player());
  if (!item) {
    write("You do not have such an item.\n");
    return 1;
  }
  item->move(target);
  if (item->query("short")) {
    work1 = TPN + " places " + item->query("short") +" in your inventory.\n";
    tell_object(target, work1);
    write("You pushed " + item->query("short") + " to " +
      target->query("cap_name") + ".\n");
  }
  else {
    work1 = TPN + " places something in your inventory.\n";
    tell_object(target, work1);
    write("You pushed something to " + target->query("cap_name") + ".\n");
  }
  return 1;
}
