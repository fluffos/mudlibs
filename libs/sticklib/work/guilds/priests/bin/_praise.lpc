#include "../priest.h"

status
praise_cmd(object who, object sym, string str)
{
    string funny;

    funny=({
      /* And which one of these is not like the others? */
      "and Saint Kelgath the Damned",
      "and Doomdark the WindRider",
      "and Kelgath the Misunderstood",
      "and Saint Kelgath the Unfortunate",
      /* I think.....THIS ONE- Starks
	    "and Avatar Baccata the Grim Reaper"
      */
    })[random(4)];

    environment(who)->tell_here(":%<me.capname>% kneels down, raising \
%<me.possessive>% hands and eyes towards the heavens, chanting loudly \
praises to " GOD_NAME " %<1>%.",0,({0,funny}),who,who,0,0);

    who->tell_me("You kneel down, raising your hands and \
gaze towards the heavens, praising " GOD_NAME ", your God.");
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}

