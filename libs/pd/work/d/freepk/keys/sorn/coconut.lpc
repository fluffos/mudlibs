#include <std.h>
inherit FOOD;

void create() {
 ::create();
   set_name("coconut");
   set_short("coconut");
   set_long("It was grown in the wild and looks great for a refreshing "
	"snack!");
   set_strength(5);
   set_id(({"coconut"}));
   set_weight(1);
   set_curr_value("silver", 5);
}

void bomb(object ob) {
   tell_object(ob, "A coconut lands on your head.");
   ob->damage(0);
   this_object()->move(ob);
}

int throw(string str) {
   object ob;
   string who, what;
   if (!str || str == "") return 0;
   if (sscanf(str, "%s at %s", what, who) != 2)
	return notify_fail("Throw what at whom?\n");
   if (what != "coconut") return notify_fail("Throw what at whom?\n");
   if (!(ob = find_player(who))) return notify_fail("Who?\n");
  this_object()->move("/d/nopk/standard/temporary");
   write("You throw the coconut at "+ob->query_cap_name()+".");
   say(this_player()->query_cap_name()+" throws a coconut at "+
	ob->query_cap_name()+".", this_player());
   call_out("bomb", 3, ob);
   return 1;
}

void init() {
 ::init();
   add_action("throw", "throw");
}
