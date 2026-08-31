#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_id(({ "jacks" }));
   set_name("jacks");
   set_short("jacks");
   set_long("About twenty small, silver, pointed jacks. They are "
     "used for playing the game, jacks. These jacks have some sort "
     "of explosive white powder sprinkled on them.");
   set_weight(2);
   set("value", 175);
}

int throw(string str) {
   string who;
   object ob;
   if (!str || !sscanf(str, "jacks at %s", who)) {
      notify_fail("Throw what at who?\n");
      return 0;
   }
   if (!present(who, environment(this_player()))) {
      notify_fail("You do not see "+who+" here.\n");
      return 0;
   }
   ob = present(who, environment(this_player()));
   if (ob == this_player()) {
      notify_fail("Throw them at yourself?\n");
      return 0;
   }
   if (this_player()->query_disable())
      return notify_fail("You are too busy to do that.\n");
   if (this_player()->query_current_attacker())
      return notify_fail("You are too busy to do that.\n");
   if (environment(this_player())->query_property("no attack")) {
      write("Greater powers prevent your malice.");
      return 1;
   }
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " throws small, explosive metal jacks at "
     +ob->query_cap_name()+"!", ({ this_player(), ob }));
   tell_object(ob, this_player()->query_cap_name()+" throws small, "
     "explosive metal jacks at you!");
   write("You the small, explosive jacks at "
     +ob->query_cap_name()+"!");
   this_player()->set_disable(1);
   ob->damage(250 + random(20));
   this_player()->kill_ob(ob);
   this_object()->remove();
   return 1;
}

void init() {
 ::init();
   add_action("throw", "throw");
}
