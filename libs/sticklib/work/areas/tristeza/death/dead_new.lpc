#ifndef ROOM_DONATOR

#include <player_defs.h>

#define ROOM_DONATOR "death/workroom"
#define	ROOM_END "/room/church"

#endif

// Ok, something nice for donators. -+ Doomdark 22-nov-95 +-

int
dead_donator(object tp, int count)
{
    string str;
    int wait;

    wait = 5;
    switch (count) {
    case 0: str =
	"Inky blackness engulfs your vision. Colours become shades of grey. \
Distinct forms become nothing more than shadows.";
	wait = 3;
	break;

    case 1: //str =
	wait = 1;
	break;

    case 2: //str =
	wait = 2;

    case 3:
	//str =
	wait = 2;
	break;

    case 4:
	//str =
	wait = 1;
	break;

    case 5:
	//str =
	wait = 1;
	break;

    case 6:
	tp->move_player("X",ROOM_END);
	/* no break */

    default:
	tp->set(LIV_NO_DEATH_MARK);	// Important!
	destruct(this_object());
    }
    if (str)
	tp -> tell_me(str);
    return wait;
}
