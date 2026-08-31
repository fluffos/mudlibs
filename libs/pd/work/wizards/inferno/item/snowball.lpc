#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("snowball");
   set_short("a small snowball");
   set_long("It has been magically created for the purposes of ... fun! "
      "Can you imagine that?");
   set_weight(1);
   set_value(0);
}

int throw(string str) {
   string you;
   object ob;
   if (!str) return notify_fail("Syntax: <throw snowball at [person]>\n");
   if (!sscanf(str, "snowball at %s", you))
      return notify_fail("Syntax: <throw snowball at [person]>\n");
   ob = find_living(you);
   if (!ob) return notify_fail(you+" is not logged on.\n");
   if (ob->query_invis()) return notify_fail(you+" is not logged on.\n");
   call_out("hit", 3, ob, this_player());
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      " throws a snowball at "+ob->query_cap_name()+"!", ({ this_player() }));
   write("You throw a snowball at "+ob->query_cap_name()+"!");
   this_object()->move("/d/standard/temporary");
   return 1;
}

void hit(object ob, object tp) {
   tell_object(ob, "A snowball hits you in the head!");
   tell_room(environment(ob), "A snowball flys in and hits "+ob->query_cap_name()+
      " in the head.", ({ ob }));
   this_object()->move(ob);
}

void init() {
 ::init();
   add_action("throw", "throw");
}
