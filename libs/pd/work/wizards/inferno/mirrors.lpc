#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_property("no teleport", 1);
   set_short("The mystical hall of mirrors");
   set_long("You have wanderered into the fabled hall of mirrors. Many "
     "mirrors line the walls and the ground is made of thick glass. Light "
     "floods the room. In the mirrors, you can see visions of people "
     "from far off lands.");
   set_exits(([
      "down" : "/wizards/inferno/portals"
   ]));
}

int view_me(string str) {
   object ob, loc;
   string tmp;

   if (!str || !(ob = find_player(str)))
     return notify_fail("Could not find that player.\n");
   loc = environment(ob);
   if ((tmp = loc->query_long()))
    write(tmp);
   tmp = "%^GREEN%^"+loc->query_long_exits()+"%^RESET%^";
    write(tmp);
   if ((tmp = loc->describe_living_contents(({this_player()}))) != "")
    write(tmp);
   if ((tmp = loc->describe_item_contents(({}))) != "")
    write(tmp);   
   return 1;
}

int goto_you(string str) {
   string who;
   object ob, env;

   if (!str) return 0;
   if (!(sscanf(str, "%s's mirror", who))) return 0;
   if (!(ob = find_player(who)))
     return notify_fail("You do not see "+who+" in the mirrors.\n");
   env = environment(ob);
   write("You enter "+ob->query_cap_name()+"'s mirror.");
   say(this_player()->query_cap_name()+" enters "+ob->query_cap_name()+
     "'s mirror.", this_player());
   this_player()->move(env);
   this_player()->force_me("look");
   return 1;
}

void init() {
 ::init();
   add_action("view_me", "view");
   add_action("goto_you", "enter");
}
