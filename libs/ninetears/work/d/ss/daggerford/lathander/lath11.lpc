#include "path.h"
inherit "std/room";

setup()
{
set_light(100);
set_short("By the pulpit");
set_long("You stand by a beutiful ornate pulpit, seemingly made entirely from "+
        "brightly polished silver.  This looks like a very holy place indeed. "+
        " To the north, through a door,  is the guild of Lathander clerics, "+
        "and to the west "+
        "the temple stretches as far as your eyes can see.\n");

add_exit("north", ROOM+"lathander", "door");
add_exit("west", ROOM+"lath9", "corridor");
modify_exit("north", ({"function","go_north"}));

add_item("pulpit", "It's seemingly made from pure silver to honor Lathander "+
   "the morning God.  The silver is as bright as the brightest morning.\n");
add_item("temple", "It's full of benches.  A large window catches your eye.\n");
add_alias("pew", "pews", "bench", "benches");
add_item("benches", "These are simple wooden benches.  They aren't "+
        "exceptionally comfortable, but the do provide a place to sit "+
        "during a service.\n");
add_item("window", "The glass seems to be of exceptional quality, "+
        "especially considering its size.  You wonder how they made such "+
        "a large piece of glass, as it seems to be one solid sheet, rather "+
        "than a number of separate panes.\n");
add_item("archway", "The large archway is a heavy stone structure.\n");
add_item("foyer", "It's too dark in there to see clearly from this distance. "+
  "if you move west you'll see it better.\n");

set_zone("lathander");
}
int go_north()
{
   if((string)this_player()->query_guild_name()=="lathander")
      return 1;
   if((string)this_player()->query_level()<1)
      return 1;
   tell_room(environment(this_player()),
      this_player()->query_cap_name()+" tried to go north, but was "+
      "stopped by an unseen force from Lathander.\n",
      this_player());
   notify_fail("The voice of Lathander fills "+
      "your head: \"You can not enter this room.\", and you are "+
      "forced away.\n");
      return 0;
}
