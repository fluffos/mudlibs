#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("tree");
   set_short("%^BOLD%^%^WHITE%^a co%^RESET%^conu%^BOLD%^t tree%^RESET%^");
   set_long("A coconut tree grows here on the island. There are "
	"probably coconuts just waiting to be picked in this thing! "
	"The lowest branch of the tree is low enough for you to be "
	"able to reach it.");
   set_prevent_get("Try as you might, you cannot uproot this tree.");
   set_id(({ "tree", "coconut tree" }));
}

int coco(string str) {
   object ob, env, igor;
   if (!str || str == "") { write("You fail to find that in the "
	"tree.\n"); return 1; }
   igor = new("/wizards/inferno/igor");
   igor->move("/d/freepk/keys/sorn/up");
   env = environment(igor);
   igor->remove();
   if (!present(str, env)) { write ("You cannot seem to "
	"find a "+str+" in the tree.\n");
	return 1; }
   ob = present(str, env);
   if (ob->is_living()) {
	write("You reach up and pull "+ob->query_cap_name()+
		" from the tree!");
	tell_object(ob, this_player()->query_cap_name()+" pulls "
		"you out of the tree! You fall and hit the ground "
		"with a thud!");
	ob->set_paralyzed(5, "You are stunned from your fall.");
	ob->move(environment(this_object()));
	return 1;
   }
   ob->move(this_player());
   write("You pick "+str+" from the tree.");
   return 1;
}

int nut(string str) {
   if (!str || str != "tree") return notify_fail("Climb what?\n");
   write("You climb, branch by brach, up the coconut tree.");
   this_player()->move_player("/d/freepk/keys/sorn/up", "up");
   return 1;
}

void init() {
 ::init();
   add_action("coco", "pick");
   add_action("nut", "climb");
}
