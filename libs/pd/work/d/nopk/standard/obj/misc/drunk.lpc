#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("drunk");
   set_short("");
   set_long("You're faded!");
   set_weight(0);
   set_value(0);
   set_heart_beat(1);
}

int rmv() { remove(); }

void heart_beat() {
   object *exits, ob, dir;
   if (!environment(this_object())->is_living()) this_object()->remove();
   if (random(100) > 30) return;
   message("info", "You stumble out of the room in a drunken haze.",
     ob);
  say(ob->query_cap_name()+" wanders out of "
     "the room in a drunken haze.", ob);
   ob = environment(this_object());
/*   if (!(sizeof(environment(ob)->query_destinations()))) {
     message("info", "You run smack dab right into a wall!", ob);
     say(ob->query_cap_name()+" runs smack dab right into a wall!", ob);
     this_object()->remove();
   }*/
   exits = environment(ob)->query_destinations();
   environment(this_object())->move("/wizards/inferno/workroom");
   rmv();
   return;
}
