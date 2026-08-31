#include <std.h>
inherit WEAPON;

void create() {
 ::create();
   set_id(({ "grenade", "ki", "ki grenade" }));
   set_name("grenade");
   set_short("%^BLUE%^a %^GREEN%^k%^BOLD%^i %^BLUE%^g%^CYAN%^re%^RESET%^%^GREEN%^n%^BOLD%^%^BLUE%^a%^CYAN%^d%^RESET%^%^BLUE%^e%^RESET%^");
   set_long("The Ki grenade blazes brilliantly.");
   set_weight(1);
   set("value", 1000000);
   set_wc(4);
   set_ac(2);
   set_type("blunt");
}

int throw(string str) {
   string who;
   object ob;
   if (!str || !sscanf(str, "grenade at %s", who)) {
      notify_fail("Throw what at who?\n");
      return 0;
   }
   if (!present(who, environment(this_player()))) {
      notify_fail("You do not see "+who+" here.\n");
      return 0;
   }
   ob = present(who, environment(this_player()));
   if (ob == this_player()) {
      notify_fail("Throw the grenade at yourself?\n");
      return 0;
   }
   if (environment(this_player())->query_property("no attack")) {
      write("%^CYAN%^The grenade flares in your hand but ceases to function in this place of peace.");
      return 1;
   }
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " throws a KI grenade at "+ob->query_cap_name()+"!", ({ this_player(),
ob }));
   tell_object(ob, this_player()->query_cap_name()+" throws a %^BLUE%^%^BOLD%^ki grenade%^RESET%^ "
     "at you!");
   write("%^BLUE%^You throw your %^BOLD%^KI grenade %^RESET%^%^BLUE%^at "+ob->query_cap_name()+"!");
   ob->damage(500);
   if (this_object()->query_wielded()) this_player()->force_me("unwield
grenade");
   this_object()->remove();
   return 1;
}

void init() {
 ::init();
   add_action("throw", "throw");
}
