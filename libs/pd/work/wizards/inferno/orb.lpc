#include <std.h>
inherit OBJECT;

create() {
   ::create();
   set_name("orb");
   set_short("Orb of transportation");
   set_long("This is an orb that seems to shift and move around");
   set_id(({ "orb" "orb of transporation", "transportation orb"}));
}
int query_auto_load() { return 1; }

init() {
   ::init();
   add_action("teleport", "teleport");
}

int teleport(string str) {
   object ob, env;
   if(!str)
   return notify_fail("Try someone real!");
   if(!(ob = find_player(str)))
   return notify_fail("Try someone real!\n");
   env = environment(ob);
   this_player()->move(env);
   write("You have been secretly moved.");
   return 1;
}
