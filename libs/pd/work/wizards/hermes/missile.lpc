#include <std.h>
inherit OBJECT;
void create() {
 ::create();
   set_name("missile");
   set_short("a small healing missle");
   set_long("%^BLUE%^%^BOLD%^A simple throwable dart that has a beautiful, brilliant light contained within.");
   set_weight(1);
   set_value(0);
}
int throw(string str) {
   string you;
   object ob;
   if (!str) return notify_fail("Syntax: <throw missile at [person]>\n");
   if (!sscanf(str, "missile at %s", you))
      return notify_fail("Syntax: <throw missile at [person]>\n");
   ob = find_player(you);
   if (!ob) return notify_fail("Throw missile at whom?\n");
   if (ob->query_invis()) return notify_fail("Throw missile at whom?\n");
   call_out("hit", 4, ob, this_player());
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      " throws a %^BLUE%^%^BOLD%^healing%^RESET%^ missile at "+ob->query_cap_name()+"!", ({ this_player() }));
   write("You throw a healing missile at "+ob->query_cap_name()+"!");
this_object()->move("/d/nopk/standard/temporary");
   return 1;
}
void hit(object ob, object tp) {
   tell_object(ob, "A %^BOLD%^missile%^RESET%^ hits you in the head. Bathing you with a %^BLUE%^%^BOLD%^blue%^RESET%^ light.");
   ob->add_hp(1000);
   ob->add_sp(1000);
   ob->add_mp(5000);
   if (wizardp(ob))
   tell_object(ob, "Doh! "+tp->query_cap_name()+" did it! I swear.");
   tell_room(environment(ob), "A healing missle flys in and hits
"+ob->query_cap_name()+
      " engulfing them in brilliant light!", ({ ob }));
   this_object()->remove();
}
void init() {
 ::init();
   add_action("throw", "throw");
}
