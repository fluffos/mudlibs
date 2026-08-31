#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("rock");
   set_short("a hard rock");
   set_long("A small, round rock. If you're feeling cruel you could throw it "
     "at someone..");
   set_weight(1);
   set_value(0);
}

int throw(string str) {
   string you;
   object ob;
   if (!str) return notify_fail("Syntax: <throw rock at [person]>\n");
   if (!sscanf(str, "rock at %s", you))
      return notify_fail("Syntax: <throw rock at [person]>\n");
   ob = find_player(you);
   if (!ob) return notify_fail("Throw it at whom?\n");
   if (ob->query_invis()) return notify_fail("Throw it at whom?\n");
   call_out("hit", 4, ob, this_player());
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      " throws a rock at "+ob->query_cap_name()+"!", ({ this_player() }));
   write("You throw a rock at "+ob->query_cap_name()+"!");
   this_object()->move("/d/standard/temporary");
   return 1;
}

void hit(object ob, object tp) {
   tell_object(ob, "A rock flys into the room and hits you in the head!");
   if (wizardp(ob))
   tell_object(ob, "Doh! "+tp->query_cap_name()+" did it! I swear.");
   tell_room(environment(ob), "A rock flys in the room and hits "
     +ob->query_cap_name()+" in the head.", ({ ob }));
   this_object()->move(ob);
}

void init() {
 ::init();
   add_action("throw", "throw");
}
