//  Fixed by Whit Jan 3, 2002 - 
//  Old file in /wizards/whit/fixed/old/_sharpen.c
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "other"; }
int cmd_sharpen(string str) {
//   int dmg;
   object ob, tp;
   tp = this_player();
   if (!abil()) return 0;
   if (!str) return notify_fail("Sharpen what?\n");
   ob = present(str, tp);
   if (!ob) {
      ob = present(str, environment(tp));
      if (!ob) return notify_fail("You do not see that here.\n");
   }
   if (tp->query_level() < 6) 
      return notify_fail("You are not experienced enough to do this.\n");
   if (!ob->is_weapon())
      return notify_fail("Syntax: <sharpen [weapon]>\n");
   if (tp->query_subclass() == "assassin" && ob->query_type() != "knife")
    return notify_fail("You cannot sharpen that.\n");
  if (tp->query_disable() || tp->query_magic_round() || tp->query_casting())
    return notify_fail("You are too busy.");
   if (ob->query_type() != "axe" && ob->query_type() != "knife" &&
       ob->query_type() != "blade")
      return notify_fail("You can only sharpen bladed weapons.\n");
   if (ob->query_property("sharpened"))
     return notify_fail("It cannot be sharpened any more than it already "
"is.\n");
   ob->set_wc(ob->query_wc() + (1+random(2)));
  ob->set_property("sharpened", 1);
  tp->set_disable();
   write("You sharpen your "+ob->query_short()+".");
   tell_room(environment(tp), tp->query_cap_name()+" sharpens "+
      tp->query_title_gender()+" "+ob->query_short()+".", ({ tp }));
   return 1;
}
void help() {
write("
Syntax: <sharpen [weapon]>
An ability for some who specialize in weapons, sharpening improves the
quality of a bladed weapon.");
}
int abil() {
   object o;
   o = this_player();
   if (o)
     if (o->query_subclass() == "ranger" || o->query_subclass() == "warrior" ||
      o->query_subclass() == "scout" || o->query_subclass() == "assassin")
      if (o->query_level() >= 6)
          return 1;
}
