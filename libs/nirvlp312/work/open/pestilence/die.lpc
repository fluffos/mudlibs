inherit "/players/vertebraker/closed/shardak/std/emote";
#include "/players/pestilence/ansi.h"


void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You cause #T# to have a fake death.\n",
  "#N# tried to make #T# die.\n",
      ""+HIK+"#N#"+NORM+" causes you to die.\n"+
"You feel very weak as your badly damaged body falls to the ground to die.\n"+
"Your intelligence is now 1.\n\n\n"+
"                                   You die.\n"+
"                          You have a strange feeling.\n"+
"                  You can see your own dead body from above.\n"+
"                      setting hit points to 1/3 max....\n\n\n"+
"A white dot appears and expands into a bright white tunnel.\n"+
"The tunnel shimmers slightly as it grows in strength.\n"+
"You feel a desire to enter the tunnel.\n"+
"#N# was just kidding.\n" }));
    load_untargeted_msgs(({
      "You try to make someone die, and failing.\n",
      ""+HIK+"#N# tries to make someone die, failing miserably.\n", }));
}
