// a dungeonware.net production based on sharpen/enchant
// coded for PD by Stormy
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
string type() { return "faith"; }
int cmd_bless(string str) {
   object ob, tp;
   tp = this_player();
   if(!spell()) return 0;
   if (!str) return notify_fail("Bless what?\n");
   ob = present(str, tp);
   if (!ob) {
      ob = present(str, environment(tp));
      if (!ob) return notify_fail("You do not see that here.\n");
   }
   if (tp->query_ghost()) return notify_fail("You howl at the item.\n");
   if (tp->query_disable())
      return notify_fail("You are busy.\n");  
   if (!ob->is_weapon())
      return notify_fail("Syntax: <bless [weapon]>\n");
   if (tp->query_mp() < 15)
      return notify_fail("You are far too tired to do this.\n");
   if (ob->query_enchanted())
      return notify_fail("It has already been blessed.\n");
   ob->set_wc(ob->query_wc() + (1+random(2)));
   ob->set_enchanted(1);
   tp->set_disable();
   tp->add_mp(-50);
   write("You bless your "+ob->query_short()+".");
   tell_room(environment(tp), tp->query_cap_name()+" blesses "+
      tp->query_title_gender()+" "+ob->query_short()+".", ({ tp }));
   return 1;
}
void help() {
write("
Syntax: <bless [weapon]>
A paladin ability, bless makes a weapon more powerful.");
}
int spell() {
   object o;
   o = this_player();
   if (o)
     if (o->query_subclass() == "paladin")
      if (o->query_level() >= 6)
          return 1;
   return 0;
}
