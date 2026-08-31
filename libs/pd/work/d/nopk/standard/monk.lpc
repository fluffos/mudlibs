#include <std.h>
#include <daemons.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "light" : 2, "indoors" : 1 ]));
   set_short("Entrance to the Hall of Monks");
   set_day_long(
     "The inside of this small hut is much more impressive than the outer looks "
     "would make somebody think. A doorway leads north, but is engulfed in a "
     "magnificent %^BOLD%^%^BLUE%^blue%^RESET%^ light. Refreshing daylight "
     "streams in through the two "
     "windows and door all on the south wall. Through the windows, the entire "
     "road to the south can be seen. It is here that Clergy who have reached "
     "level 10 can <become monk>."
   );
   set_night_long(
     "Within what appears to be a small hut from without is much roomier inside "
     "than appears possible from outside. The northern doorway is engulfed in "
     "a magnificent%^BOLD%^%^BLUE%^ blue %^RESET%^light which lights the "
     "room. Outside it is night, "
     "but is bright as day in here due to the blue light. The whole road to the "
     "south can be seen through the two windows on the southern wall. It is here "
     "that Clergy who have reached level 10 can <become monk>."
   );
   set_items(([
     "windows" : "They give a great view outside.",
     "door"    : "The northern door is completely outlined in a bright blue "
                 "light.",
     "light"   : "%^BOLD%^%^BLUE%^Magnificent blue light shine through the "
                 "doorway.",
     "road"    : "All of the road to the south can be seen."
   ]));
   set_exits(([
	"out"   : ROOMS"lorroad3",
        "north" : ROOMS"monk_sub"
   ]));
}

int go_north() {
   if (this_player()->query_subclass() == "monk" || wizardp(this_player())) return 0;
   write("You cannot pass the blue light.");
   say(this_player()->query_cap_name()+" cannot pass the blue light to go north.",
     this_player());
   return 1;
}

int become_m(string str) {
   if (!str || str != "monk") return notify_fail("Become what?\n");
   if (this_player()->query_level() < 10 || this_player()->query_class() !=
     "clergy" || this_player()->query_subclass() != "none")
     return notify_fail("You must be a level 10 Clergy with no subclass.\n");
   write("%^BOLD%^%^WHITE%^You have chosen the path of the monk.");
   CHAT_D->do_raw_chat("clergy", "%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+
      " has become chosen the path of the monk.");
   this_player()->set_subclass("monk");
   return 1;
}

void init() {
 ::init();
   add_action("go_north", "north");
   add_action("become_m", "become");
}
