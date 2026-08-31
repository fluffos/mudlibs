#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("igloo");
   set_short("%^BOLD%^%^CYAN%^an igloo");
   set_long("%^BOLD%^%^CYAN%^The large igloo is starting to melt.. "
      "How it got here, you have NO clue, and even less to why it's "
      "still here in the heat. A small tunnel is being used "
      "as a doorway.");
   set_value(0);
   set_weight(90000);
}

int enter(string str) {
   if (!str || str != "igloo") return 0;
   write("You climb into the igloo.");
   this_player()->move_player("/wizards/inferno/room/iglooroom", "igloo");
   return 1;
}

void init() {
 ::init();
   add_action("enter", "enter");
}

int get() { return 0; }
