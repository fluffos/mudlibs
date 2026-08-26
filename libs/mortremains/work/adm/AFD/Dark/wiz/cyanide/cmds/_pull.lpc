// Written by Chronos..
#include <mudlib.h>

inherit DAEMON;

int cmd_pull(string str) {
  object target, item;
  string work1,work2;
  if (!str) {
    write("Usage: pull <item> from <person>\n");
    return 1;
  }
  if (sscanf(str, "%s from %s", work1, work2) != 2) {
    write("Usage: pull <object> from <person>\n");
    return 1;
  }
  target = find_player(work2);
  if (!target) {
    write("That player is not logged in right now.\n");
    return 1;
  }
  item = present(work1, target);
  if (!item) {
    write(target->query("cap_name") + " does not have such an item.\n");
    return 1;
  }
  item->move(TP);
  if (item->query("short")) {
    work1 = TPN + " removes " + item->query("short") +" from your inventory.\n";
    tell_object(target, work1);
  work1 = "You pulled " + item->query("short") + " from " +
        target->query("cap_name") + "'s inventory.\n";
    write(work1);
  }
  else {
    work1 =TPN+" removes something from your inventory.\n";
    tell_object(target,work1);
    write("You pulled something from "+target->query("cap_name")+".\n");
  }
  return 1;
}
