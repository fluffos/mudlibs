#include <locations.h>
#include <locations.h>
#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_recall()
{
    if(this_player()->query_arena()) {
	write("You may not recall out of the arena.\n");
	return 1;
    }
    if (this_player()->query_ghost()) {
      message("mout", "You feel your spirit pulled back to a place of prayer.", this_player());
      message("mout", this_player()->query_cap_name()+" vanishes.", environment(this_player()), this_player());
      this_player()->move("/d/nopk/tirun/monastery");
      this_player()->describe_current_room(1);
      return 1;
    }

    if (this_player()->query_level() > 5)
    {
	notify_fail("You are too old to recall.\n");
	return 0;
    }
    write("You are magically teleported back to tirun square...");
    this_player()->move_player(SQUARE_LOC, "into nothingness");
    return 1;
}
int help()
{
    write( @EndText
Syntax: recall
Effect: Allows a newbie to be transported to Tirun park square.
        A dead player can also use it to return to the monastery to pray.

EndText
    );
    return 1;
}
