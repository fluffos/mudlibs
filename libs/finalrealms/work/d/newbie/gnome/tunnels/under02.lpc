inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the gnome:  Hermit's Hovel");
set_zone("TUNNEL");
set_light(40);
set_long("\nRealm of the Gnome:  Hermit's Hovel\n\n"
	 "     You have found one of the few truly dry spots in the Macedonian "
     "Tunnels.  It appears to be a rather well kept area, free of all debris "
     "that stray animals leave behind.  It almost appears as if someone lives "
     "here.  To the west you can see the main passage of the Macedonian "
     "Tunnels.\n\n");
add_feel("air","The air feels nice and warm.  It is supprisingly free of the"
     " excess moisture found in most underground passageways.\n\n");
add_item(({"wall","walls","ceiling","floor"}),"As you look at "
    "the surrounding walls you notice that they are surprisingly smooth and "
    "dry.\n\n");
add_item(({"tunnel","tunnels"}),"As you look back to the main tunnel, "
    "you see nothing but the slight sparkle of the stream that runs "
    "throughout the main passageway.\n\n");
add_exit("west",UNDER +"under01","path");
}
