//  Created by Whit
// 2
#include <std.h>
#include "/wizards/whit/quest/christmas/quest.h"

inherit ROOM;

void create() {
   ::create();
   set_short("Unknown land");
   set_long("A violent snow storm rages on.  There is hardly any "
     "visibility.  You seem to lose all sense of direction.");
   set_exits(([ 
     "north": ROOMS"maze/9",
     "south": ROOMS"maze/8",
     "west": ROOMS"maze/5",
     "east": ROOMS"r1",
       ]));
   set_post_exit_functions( ({"east"}), ({"finish_south"}) );
}

void init() {
   ::init();
   if(this_player())
   message("", "The storm continues to rage on!", this_player());
   if(this_player())
   if(wizardp(this_player()))
   message("", "%^BOLD%^%^RED%^Wiz:%^RESET%^ Go north.", this_player());

}

int finish_south() { 
   write("You barely make it out of the snow storm!");
   return 1;
}


