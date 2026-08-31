#include <std.h>
inherit WEAPON;

void create() {
 ::create();
   set_id(({ "boulder", "rock", "huge boulder" }));
   set_name("boulder");
   set_short("a huge boulder");
   set_long("This boulder has been ripped out of a mountain "
       "by some monsterous force.");
   set_weight(100);
   set("value", 10);
   set_wc(4);
   set_ac(2);
   set_type("blunt");
}

int throw(string str) {
   string who;
   object ob;
   if (!str || !sscanf(str, "boulder at %s", who)) {
      notify_fail("Throw what at who?\n");
      return 0;
   }
   if (!present(who, environment(this_player()))) {
      notify_fail("You do not see "+who+" here.\n");
      return 0;
   }
   ob = present(who, environment(this_player()));
   if (ob == this_player()) {
      notify_fail("Throw the boulder at yourself?\n");
      return 0;
   }
   if (environment(this_player())->query_property("no attack")) {
      write("Greater powers prevent your malice.");
      return 1;
   }
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " throws a huge boulder at "+ob->query_cap_name()+"!", ({ this_player(),
ob }));
   tell_object(ob, this_player()->query_cap_name()+" throws a huge boulder "
     "at you!");
   write("You throw a huge boulder at "+ob->query_cap_name()+"!");
   ob->damage(70);
   if (this_object()->query_wielded()) this_player()->force_me("unwield
boulder");
   this_object()->remove();
   return 1;
}

void init() {
 ::init();
   add_action("throw", "throw");
}

