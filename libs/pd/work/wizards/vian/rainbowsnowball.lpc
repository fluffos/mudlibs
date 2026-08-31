#include <std.h>
inherit OBJECT;
void create() {
 ::create();
   set_name("rainbow snowball");
   set_short("%^BOLD%^a %^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^BLUE%^n%^GREEN%^b%^MAGENTA%^o%^CYAN%^w %^WHITE%^snowball");
   set_long("%^BOLD%^This small snowball is magically infused with the colors of the %^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^BLUE%^n%^GREEN%^b%^MAGENTA%^o%^CYAN%^w%^RESET%^%^BOLD%^!%^RESET%^");
   set_weight(1);
   set_id( ({ "snowball", "rainbow snowball" }) );
   set_value(0);
  set_property("no auction", 1);
  set_property("juggle", 1);
}
void init() {
  ::init();
  add_action("throw", "throw");
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
      " throws a %^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^BLUE%^n%^GREEN%^b%^MAGENTA%^o%^CYAN%^w %^RESET%^ snowball at "+ob->query_cap_name()+"!", ({ this_player() }));
   write("You throw a %^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^BLUE%^n%^GREEN%^b%^MAGENTA%^o%^CYAN%^w %^RESET%^snowball at "+ob->query_cap_name()+"!");
   this_object()->move("/d/nopk/standard/temporary");
   return 1;
}
void hit(object ob, object tp) {
   if(!ob && tp) {
      message("info", "They left before the %^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^BLUE%^n%^GREEN%^b%^MAGENTA%^o%^CYAN%^w %^RESET%^snowball could hit them!", tp);
      return;
   }
   tell_object(ob, "A %^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^BLUE%^n%^GREEN%^b%^MAGENTA%^o%^CYAN%^w%^RESET%^ snowball hits you in the head!");
   if (tp) tell_object(ob, "Doh! "+tp->query_cap_name()+" did it! I swear.");
   tell_room(environment(ob), "A %^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^BLUE%^n%^GREEN%^b%^MAGENTA%^o%^CYAN%^w %^RESET%^snowball flys in and hits "+ob->query_cap_name()+" in the head.", ({ ob }));
   this_object()->move(ob);
}

