#include <std.h>
inherit OBJECT;
void create() {
 ::create();
   set_name("grenade");
   set_short("a small grenade");
   set_long("It has been magically created for the purposes of ... fun! "
      "Can you imagine that?");
   set_weight(1);
   set_value(0);
}
int throw(string str) {
   string you;
   object ob;
   if (!str) return notify_fail("Syntax: <throw grenade at [person]>\n");
   if (!sscanf(str, "grenade at %s", you))
      return notify_fail("Syntax: <throw grenade at [person]>\n");
   ob = find_player(you);
   if (!ob) return notify_fail("Throw grenade at whom?\n");
   if (ob->query_invis()) return notify_fail("Throw grenage at whom?\n");
   ob->damage(500);
   call_out("hit", 4, ob, this_player());
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      " throws a grenade at "+ob->query_cap_name()+"!", ({ this_player() }));
   write("You throw a grenade at "+ob->query_cap_name()+"!");
   this_object()->move("/d/standard/temporary");
   return 1;
}
void hit(object ob, object tp) {
   tell_object(ob, "A grenade hits you and explodes!");
   if (wizardp(ob))
   tell_object(ob, "Doh! "+tp->query_cap_name()+" did it! I swear.");
   tell_room(environment(ob), "A grenade flys in and hits "+ob->query_cap_name()+
      " engulfing them in an explosion!", ({ ob }));
   this_object()->remove();
}
void init() {
 ::init();
   add_action("throw", "throw");
}
