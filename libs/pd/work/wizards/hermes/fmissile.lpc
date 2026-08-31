inherit OBJECT;
void create() {
 ::create();
   set_name("missile");
   set_short("a small forget missile missle");
   set_long("%^BLUE%^%^BOLD%^A simple throwable dart that has a question mark on it's side..");
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
      " throws a %^BLUE%^%^BOLD%^missle of forgetfullness%^RESET%^ at "+ob->query_cap_name()+"!", ({ this_player() }));
   write("You throw a forgetful missile at "+ob->query_cap_name()+"!");
   this_object()->move("/d/nopk/standard/temporary");
   return 1;
}
void hit(object ob, object tp) {
   tell_object(ob, "A %^BOLD%^missile%^RESET%^ hits you in the head... oww... hey, you forgot where your gates were to!");
ob->force_me("follow endbringer");
   if (wizardp(ob))
   tell_object(ob, "Doh! "+tp->query_cap_name()+" did it! I swear.");
   tell_room(environment(ob), "A missle flys in and hits
"+ob->query_cap_name()+
      " making them blink once and look confused.", ({ ob }));
   this_object()->remove();
}
void init() {
 ::init();
   add_action("throw", "throw");
}
