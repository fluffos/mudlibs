#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort ("Main Room of the Learners Quarters");
  SetIntLong (
"You are in the main room of the learners quarters. Though it's quite "
"empty, it is nevertheless comfortable. "
"Along the walls are several couches and cushions for relaxed "
"contemplation.\n"
"A doorway leads west into the Administration Tower, other doors "
"lead south into the dormatory, and east into the training workshop.\n"
             );
  AddDetail (({"couch", "couches"}), "They invite for relaxation.\n");
  AddDetail ("cushion", 
"Whoa, so many cushions, you can't decide on which to look at.\n"
            );
  AddDetail ("cushions",
"Small cushions, big cushions, fluffy cushions...\n"
"But all are cosy, cute, from Squornshellous Beta, and dead.\n"
            );
  AddExit ("west",TOWER("first/east_corr"));
  AddExit ("south","./dormatory");
  AddExit ("east","./workshop");
}
