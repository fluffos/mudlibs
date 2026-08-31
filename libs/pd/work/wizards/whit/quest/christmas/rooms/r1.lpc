//  Created by Whit

#include <std.h>
#include "/wizards/whit/quest/christmas/quest.h"

inherit ROOM;

void create() {
   ::create();
   set_short("Unknown land");
   set_long("As far as the eye can see is snow.  A "
     "path can barely be seen beneath the freshly fallen "
     "snow.  The path leads further into the snow barren land.");
   set_exits(([ "north": ROOMS"maze/1", "south": ROOMS"dock" ]));
   set_post_exit_functions( ({"north"}), ({"finish_north"}) );
}

int finish_north() {
   write("You have seemed to have stumbled into a violent snow storm!");
   return 1;
}

