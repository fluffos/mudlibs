#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

extra_reset() {
  no_castle_flag = 1;
  if(!present("sign",this_object()))
  move_object(clone_object("players/boltar/casino/sign"),this_object());
  if(!present("doorman",this_object()))
  move_object(clone_object("players/boltar/casino/doorman"),this_object());
}
FOUR_EXIT("room/southroad3","east",
       "room/lanceroad2", "west",
       "room/new_alley", "northwest",
       "players/boltar/casino/front_desk", "north",
       "Lance Road, (CASINO)",
"You are walking along the recently paved Lance Road. You notice a huge\n"+
"new building on the north side of the street. It is done in a retro\n"+
"theme but is very modern at the same time. A large sign in bright\n"+
"lights shines down on to the roadway and wide sidewalk. The building\n"+
"its self appears to be still under construction but open for business.\n"+
"There is a revolving door to the north and Lance road continues on to the\n"+
"east and west.\n",1)

look(str) {
  if (!str) return 0;
  if (str == "at door" || str=="at revolving door") {
     write("A large, expensive, and heavily decorated revolving door.\n");
     return 1;
   }
  if (str == "at building") {
     write("This building appears to be a hotel and casino. It's large\n"+
           "size is simply overwhelming. It's glow and decoration over\n"+
           "the top.\n");
     return 1;
  }
  if (str == "at road") {
     write("You notice a hole in the road off to the side where\n"+ 
           "village workers have already cut up the new pavement to\n"+ 
           "get at a pipe or something.\n");
     return 1;
  }
  return 0;
}  
