#include <std.h>
inherit ARMOUR;

void check_me();

void create() {
 ::create();
   set_name("blades");
   set_short("razorblades and nails");
   set_long("Three rows of wicked razor blades jut forth from your "
      "shoulders.");
   set_weight(0);
   set_value(0);
   set_ac(1);
   set_id(({ "blades", "razor", "nails", "razorblades" }));
   set_limbs(({"torso"}));
   set_type("razorblades");
   set_heart_beat(1);
   call_out("heart", 10, 0);
}


int query_auto_load() { return 1; }

int drop() { if (!wizardp(this_player())) return 1; }

void heart() {
   object ob, tp;
   tp = environment(this_object());
   if (tp)
     call_out("heart", 3, 0);
   if (!tp->is_living()) return;
   if (!(ob = tp->query_current_attacker())) return;
   if (random(15) != 2) return;
   if (random(100) <= 30) {
     write("One of the blades cut you!");
     tp->damage(random(20));
     return;
   }
   message("info", "You slam "+ob->query_cap_name()+" with your shoulders, "
     "gouging "+ob->query_objective()+" horribly.", tp);

   message("owch", tp->query_cap_name()+" slams you with "
     +tp->query_title_gender()+" shoulders, gouging you horribly!", ob);

   tell_room(environment(ob), tp->query_cap_name()+" gouges "
     +ob->query_cap_name()+" with the blades and nails along "
     +tp->query_title_gender()+" shoulders!", ({ ob, tp }));
   ob->damage(75+random(this_player()->query_stats("strength")));
   return;
}

string extra_look() {
   if (!this_object()->query_worn()) return 0;
   if (!environment(this_object())->is_living()) return 0;
   return environment(this_object())->query_cap_name()+" has three "
      "rows of blades and nails jutting forth from "+
      environment(this_object())->query_title_gender()+" shoulders.\n";
}

int check_rmv(string str) {
   if (present(str, this_player()) != this_object()) return 0;
   write("You cannot do that.");
   return 1;
}

void init() {
 ::init();
   add_action("check_rmv", "remove");
   set_heart_beat(1);
}
