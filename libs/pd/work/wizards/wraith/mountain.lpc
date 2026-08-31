#include <std.h>
inherit OBJECT;
void create() {
 ::create();
   set_name("snowball");
   set_short("a large snowball");
   set_long("Thats not a snowball thats a MOUNTAIN!");
   set_weight(1);
   set_value(0);
}
int throw(string str) {
   string you;
   object ob;
   if (!str) return notify_fail("Syntax: <throw snowball at [person]>\n");
   if (!sscanf(str, "snowball at %s", you))
      return notify_fail("Syntax: <throw snowball at [person]>\n");
   ob = find_player(you);
   if (!ob) return notify_fail("Throw snowball at whom?\n");
   if (ob->query_invis()) return notify_fail("Throw snowball at whom?\n");
   call_out("hit", 4, ob, this_player());
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      " throws a friggin HUMOUNGOUS snowball at "+ob->query_cap_name()+"!", ({ this_player() }));
   write("You just threw a mountain at "+ob->query_cap_name()+"!");
   this_object()->move("/d/standard/temporary");
   return 1;
}
void hit(object ob, object tp) {
   tell_object(ob, "Holy crud! A mountain of snow just fell on your head!");
   ob->damage(0);
   if (wizardp(ob))
   tell_object(ob, "%^BOLD%^%^YELLOW%^Doh! "+tp->query_cap_name()+" did it! I swear.%^RESET%^");
   tell_room(environment(ob), "A mountain of snow just flew in and landed on "+ob->query_cap_name()+
      " removing them from sight!", ({ ob }));
   this_object()->remove();
}
void init() {
 ::init();
   add_action("throw", "throw");
}
