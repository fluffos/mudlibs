inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     As you continue down the passage way, you see that "
       "nothing much has changed.  The stream still bubbles merrily "
       "along and the stalagtites and stalagmites are still there.  "
     "You could go northeast, which is the direction you came from,"
   " but curiosity drives you to continue on westward.  You wonder "
    "where this stream leads to.\n\n");
add_item(({"stalagtites","stalagmites","stalagtite","stalagmite"}),"You "
   "look around and notice that there are fewer stalagtites and "
   "stalagmites, but the ones that are present are much longer than "
   "the ones before and have been worn smooth.\n\n");
add_item(({"stream","brooke","river"}),"You look at the stream that "
   "you seem to be following.  It is still quite clear, but with the "
   "lack of good light it takes on the look of a black mirror.\n\n");
add_smell("air","The air smells a bit fresher now, due mainly in part "
   "to the fact that the running water seems to be creating a slight "
   "breeze.\n\n");
add_exit("west",UNDER +"under07","path");
add_exit("northeast",UNDER +"under03","path");
}
