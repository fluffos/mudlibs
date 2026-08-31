#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("tree");
   set_short("an uprooted tree");
   set_long("The seventeen foot long tree looks much like a battering "
     "ram with leaves and roots still attached. It is extremely heavy "
     "but would deal a devastating blow.");
   set_weight(450);
   set_hands(2);
   set_id(({ "tree" }));
   set_wc(13);
   set_type("blunt");
   set_value(100);
}

int rock_world() {
   object tp, ob, env;
   if (this_player()->is_player()) return 0;
   if (!this_player()->query_current_attacker()) return 0;
   tp = this_player();
   ob = tp->query_current_attacker();
   tell_room(environment(tp), tp->query_cap_name()+" slams an "
     "uprooted tree trunk into "+ob->query_cap_name()+"!", ({ tp, ob }));
   tell_object(ob, tp->query_cap_name()+" slams a huge uprooted tree "
     "trunk into you!");
   ob->damage(250 + random(50));
   env = environment(tp);
   if (env->query_exit("down") == "/d/standard/void") return 1;
   tell_room(env, "%^YELLOW%^The increadible force of the tree sends "
     +ob->query_cap_name()+" through the ground!", ({ ob }));
   tell_object(ob, "%^YELLOW%^The increadible force of the tree sends "
     "you through the ground!");
   env->set_long(env->query_long()+"\n%^YELLOW%^"
     +capitalize(a_or_an(ob->query_race()))+" "+ob->query_race()+
     "-sized hole leads down.%^RESET%^");
   ob->move(env->query_exit("down"));
   ob->force_me("look");
   tp = env->query_exit("down");
   env = tp;
   tell_object(ob, "You hit the ground with a thud!");
   tell_room(env, ob->query_cap_name()+" rips through the ceiling "
     "and hits the ground with a thud!", ({ ob }));
   env->set_long(env->query_long()+"\n%^YELLOW%^"+
     capitalize(a_or_an(ob->query_race()))+" "+ob->query_race()+ 
     "-sized hole is in the ceiling.%^RESET%^");
   return 1;
}

void init() {
 ::init();
   add_action("rock_world", "rock");
}

int query_auto_load() {
   if (this_player()->query_level() >= 15) return 3;
}
