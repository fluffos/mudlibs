#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;
FOUR_EXIT("room/lanceroad3","south",
       "room/path2", "north",
       "players/mokri/stuff/paintball/shack", "east",
       "room/housing/nowheres", "west",
         "Narrow path",
"This is a narrow foot path leading uphill towards the village church.\n"+
"It has long been used as a short cut for villagers living on the east end\n\
of Lance Road.  The path continues to the north with Lance Road to the south.\n\
A path to the west looks quite new.\n", 1)

string *testers;
int   loaded;
void init() { ::init();
  if(!loaded) { testers = ({ "vertebraker","verte","guineapig" }); loaded = 1; }

  add_action("cmd_west", "west");
}

int cmd_west()
{
  if(!this_player()) return 0;
/*
  if(member_array((string)this_player()->query_real_name(), testers) == -1)
  write("You try to go west, but realize it's SO friggin' new\n\
that it doesn't even *exist* yet.\n");
  else
*/
  this_player()->move_player("west#/players/earwax/housing/realty");
  return 1;
}
