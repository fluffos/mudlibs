#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("clasp");
   set_short("a silver cape clasp");
   set_id(({ "clasp", "cape clasp" }));
   set_long("It connects the two top ends of a cape.");
   set_weight(1);
    set_curr_value("gold", 15);
   set_type("clasp");
   set_limbs(({ "torso" }));
   set_ac(1);
}

int check_wear(string str) {
   object *ob=({ });
   int i, t;
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_object()->query_worn()) return 0;
   ob = all_inventory(this_player());
   i = sizeof(ob);
   t = 0;
   while (i--) {
     if (ob[i]->query_type() == "cape" && ob[i]->query_worn()) t = 1;
   }
   if (!t) {
     write("You must be wearing a cape to wear that.");
     return 1;
   }
   return 0;
}

int check_rmv(string str) {
   object ob, *all=({ });
   int i, j;
   if (!str || str == "all") return 0;
   ob = present(str, this_player());
   if (!ob || ob == this_object()) return 0;
   if (!ob->is_armour()) return 0;
   if (ob->query_type() == "cape")
      this_player()->force_me("remove clasp");
   return 0;
}

void init() {
 ::init();
   add_action("check_wear", "wear");
   add_action("check_rmv", "remove");
}
