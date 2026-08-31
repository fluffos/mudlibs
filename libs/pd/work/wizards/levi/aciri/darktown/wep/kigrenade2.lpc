#include <std.h>
inherit WEAPON;

void create() {
 ::create();
   set_id(({ "grenade", "ki grenade", "ki" }));
   set_name("grenade");
   set_short("%^BOLD%^%^CYAN%^a ki grenade%^RESET%^");
   set_long("This blazing ki grenade is ready to be thrown.");
   set_weight(1);
   set("value", 1000000);
   set_wc(1);
   set_ac(2);
   set_type("blunt");
}

int throw(string str) {
   string who;
   object ob;
   if (!str || !sscanf(str, "ki grenade at %s", who)) {
      notify_fail("Throw what at who?\n");
      return 0;
   }
   if (!present(who, environment(this_player()))) {
      notify_fail("You do not see "+who+" here.\n");
      return 0;
   }
   ob = present(who, environment(this_player()));
   if (ob == this_player()) {
      notify_fail("Throw the ki grenade at yourself?\n");
      return 0;
   }
   if (environment(this_player())->query_property("no attack")) {
      write("Greater powers prevent your malice.");
      return 1;
   }
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " throws a blazing ki grenade at "+ob->query_cap_name()+"!", ({ this_player(), ob }));
   tell_object(ob, this_player()->query_cap_name()+" throws a ki grenade "
     "at you!");
   write("%^BLUE%^%^BOLD%^You throw a %^CYAN%^blazing ki grenade%^BLUE%^ at "+ob->query_cap_name()+"!");
   ob->damage(500);
   if (this_object()->query_wielded()) this_player()->force_me("unwield
boulder");
   this_object()->remove();
   return 1;
}

void init() {
 ::init();
   add_action("at", "grenade");
}


int query_auto_load() { if (this_player()->query_level() >=50) return 1; }


