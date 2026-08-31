#include <std.h>
inherit OBJECT;
void create() {
 ::create();
   set_name("firework");
   set_short("a small firework");
   set_long("YAY!  A %^BOLD%^%^RED%^f%^BOLD%^%^BLACK%^i%^RED%^r%^BLACK%^e%^RED%^w%^BLACK%^o%^RED%^r%^BLACK%^k%^RESET%^ to play with!");
   set_weight(1);
   set_value(0);
}
int throw(string str) {
   string you;
   object ob;
   if (!str) return notify_fail("Syntax: <throw firework at [person]>\n");
   if (!sscanf(str, "firework at %s", you))
      return notify_fail("Syntax: <throw firework at [person]>\n");
   ob = find_player(you);
   if (!ob) return notify_fail("Throw firework at whom?\n");
   if (ob->query_invis()) return notify_fail("Throw firework at whom?\n");
   call_out("hit", 4, ob, this_player());
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      " throws a %^BOLD%^%^RED%^f%^BOLD%^%^BLACK%^i%^RED%^r%^BLACK%^e%^RED%^w%^BLACK%^o%^RED%^r%^BLACK%^k%^RESET%^ at "+ob->query_cap_name()+"!", ({ this_player() }));
   write("%^BOLD%^%^GREEN%^You %^BOLD%^%^YELLOW%^throw %^BOLD%^%^BLACK%^a %^BOLD%^%^RED%^f%^BOLD%^%^BLACK%^i%^RED%^r%^BLACK%^e%^RED%^w%^BLACK%^o%^RED%^r%^BLACK%^k%^RESET%^ %^BOLD%^%^MAGENTA%^at %^BOLD%^%^WHITE%^"+ob->query_cap_name()+"!");
   this_object()->move("/d/standard/temporary");
   return 1;
}
void hit(object ob, object tp) {
   tell_object(ob, "%^BOLD%^%^YELLOW%^A %^BOLD%^%^RED%^f%^BOLD%^%^BLACK%^i%^RED%^r%^BLACK%^e%^RED%^w%^BLACK%^o%^RED%^r%^BLACK%^k%^RESET%^ %^BOLD%^%^MAGENTA%^h%^BOLD%^%^BLUE%^i%^BOLD%^%^BLACK%^t%^BOLD%^%^RED%^s %^BOLD%^%^GREEN%^you %^BOLD%^%^CYAN%^in %^BOLD%^%^RED%^the %^BOLD%^YELLOW%^h%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^a%^BOLD%^%^MAGENTA%^d%^BOLD%^%^BLUE%^ and %^BOLD%^%^YELLOW%^ex%^WHITE%^plo%^YELLOW%^des%^RESET%^!");
   ob->damage(5109);
   tell_room(environment(ob), "%^BOLD%^%^CYAN%^A %^BOLD%^%^RED%^f%^BOLD%^%^BLACK%^i%^RED%^r%^BLACK%^e%^RED%^w%^BLACK%^o%^RED%^r%^BLACK%^k%^RESET%^%^BOLD%^%^CYAN%^ flys in and hits
"+ob->query_cap_name()+
      " %^BOLD%^%^CYAN%^engulfing them in an %^BOLD%^%^YELLOW%^exp%^WHITE%^lo%^YELLOW%^s%^RED%^ion%^RESET%^%^BOLD%^%^GREEN%^!", ({ ob }));
   this_object()->remove();
}
void init() {
 ::init();
   add_action("throw", "throw");
}
