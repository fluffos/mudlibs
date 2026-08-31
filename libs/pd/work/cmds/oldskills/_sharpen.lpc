//  Fixed by Whit Jan 3, 2002 - 
//  Old file in /wizards/whit/fixed/old/_sharpen.c
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_sharpen(string str) {
//   int dmg;
   object ob, tp;
   tp = this_player();
   if (!str) return notify_fail("Sharpen what?\n");
   ob = present(str, tp);
   if (!ob) {
      ob = present(str, environment(tp));
      if (!ob) return notify_fail("You do not see that here.\n");
   }
   if (tp->query_subclass() != "ranger" 
       && tp->query_subclass() != "warrior" && tp->query_subclass() != "scout"
)
      return notify_fail("What?\n");
   if (tp->query_level() < 6) 
      return notify_fail("You are not experienced enough to do this.\n");
   if (!ob->is_weapon())
      return notify_fail("Syntax: <sharpen [weapon]>\n");
   if (tp->query_mp() < 15)
      return notify_fail("You are far too tired to do this.\n");
   if (ob->query_type() != "axe" && ob->query_type() != "knife" &&
       ob->query_type() != "blade")
      return notify_fail("You can only sharpen bladed weapons.\n");
   if (!ob->sharpen(random(4)))
     return notify_fail("It cannot be sharpened any more than it already "
"is.\n");
   ob->set_wc(ob->query_wc() + random(3));
   write("You sharpen your "+ob->query_short()+".");
   tell_room(environment(tp), tp->query_cap_name()+" sharpens "+
      tp->query_title_gender()+" "+ob->query_short()+".", ({ tp }));
   return 1;
}
void help() {
write("
Syntax: <sharpen [weapon]>
A ranger, scout, and warrior ability, sharpen improves the quality "
"of a bladed weapon.");
}
int abil() {
   object o;
   o = this_player();
   if (o)
     if (o->query_subclass() == "ranger" || o->query_subclass() == "warrior" ||
o->query_subclass() == "scout")
      if (o->query_level() >= 6)
          return 1;
}
