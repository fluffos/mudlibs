/* Cadra@Nightfall 22-12-1993
With MANY MANY thanks to Shandril@TappMud (Timelord@Nightfall) who created this kiss for 
the lost world of TappMud
*/
inherit "/std/thing";

#include <properties.h>
#include <secure/wizlevels.h>
#include "path.h"

create() {
        ::create();
	SetIds(({"kiss"}));
	SetAds(({"magic","magical","a"}));
        SetValue(100);
        SetShort("a magical kiss");
        SetLong(
"This appears to be a small sphere made of just a swirling mist. There's a "
"softness and warmth about the mist and yet more that is beyond descript, for "
"how does one describe a kiss in the wind?\n"
"To send this kiss to your beloved, simply 'blow <beloved>'.\n");
}

init() {
        ::init();
        add_action("blow","blow");
}

blow(string str) {
        object pl;
        if (environment(this_object()) != this_player()) return 0;
        if (!str) {
                write("Whom do you want to blow this beautiful kiss to?\n");
                return 1;
        }
      
        pl = find_player(str);

/* TO BE READDED IF WE HAVE IGNORE AND/OR DISTURBANCES OFF
                if (pl && pl->is_ignoring_you(this_player())) {
                write("It seems that "+CAP(str)+" is ignoring you so it will"+
                        "take much more that this kiss to reach
"+pl->POSS+" heart.\n");
                return 1;
        }
        if (pl && !pl->can_be_disturbed()) {
                write(CAP(str)+" is very busy right now and such a
beautiful\n"+
                        "and loving kiss would surely disrupt 
"+pl->QueryPossessive()+"
concentration.\n");
                return 1;
        }
*/
        if (pl) {
if (!interactive(pl)) {return (int) notify_fail(capitalize(str)+" is not reachable.\n"); }
if (!IS_WIZARD(this_player()) && (pl->QueryInvis())) {return (int) notify_fail(capitalize(str)+" is not reachable.\n"); }
                write("You blow a magical kiss to "+capitalize(str)+".\n");
                say(this_player()->QueryName()+" blows a magical kiss towards the heavens.\n");
                move_object(this_object(), pl);
                tell_room(environment(pl),"You hear a soft ringing coming from heaven.\n",({pl}));
                tell_object(pl, capitalize(this_player()->QueryName())+" blows a magical kiss to you filled with "+this_player()->QueryPossessive()+" pure love.\n");
                  return 1;
        } else {
                write(capitalize(str)+" is not playing now.\n");
                return 1;
        }
}
