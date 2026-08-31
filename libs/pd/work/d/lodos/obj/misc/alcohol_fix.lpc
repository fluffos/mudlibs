#include <std.h>
#include <lodos.h>
inherit OBJECT;

int drink(string str);

void create() {
 ::create();
   set_name("elixer");
   set_short("elixer of alcanst");
   set_long("The thick, dark green liquid bubbles in the bottle.");
   set_weight(5);
   set_value(0);
   set_id(({ "potion", "elixer", "alcanst", "elixer of alcanst" }));
}

int drink(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());
   if (ob != this_object()) return 0;
   if (this_player()->query_intox() >= 65)
      this_player()->add_intox(-(5 + random(15)));
   write("You quaff the thick, bubbling green liquid and wince.");
   this_player()->add_hp(-random(15));
   say(this_player()->query_cap_name()+" drinks a thick, bubbling green liquid.", this_player());
   ob = new(OBJECT);
   ob->set_name("bottle");
   ob->set_short("an empty bottle");
   ob->set_id(({ "bottle" }));
   ob->set_long("This empty bottle used to hold something..");
   ob->set_weight(1);
   ob->value(0);
   ob->move(this_player());
   this_object()->remove();
   return 1;
}

void init() {
 ::init();
   add_action("drink", "drink");
}
