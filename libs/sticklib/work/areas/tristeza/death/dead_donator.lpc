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
	"You can see a hooded skeletal figure standing beside your corpse. He is\
 wiping the bloody blade of a wicked looking scythe with slow measured\
 motions. Suddenly he stops and seems to look straight at you with his\
 empty... no, not empty but.... orbs....";
	wait = 3;
	break;

    case 1: str =
	"Death says: COME WITH ME, MORTAL ONE!";
	wait = 1;
	break;

    case 2: str =
	"Death suddenly glances at some odd list he seems to be having and scratches\
 its head.";
	wait = 2;

    case 3:
	str =
	"Death says: Ack! Your name seems to be on this stupid donator list that\
 disgusting soft-hearted immortal, Doomdark, gave me.";
	wait = 2;
	break;

    case 4:
	str =
	"Death says: I know I shouldn't have promised to let all of you fancy\
 little donators get away this easily from death sequence... But you know,\
 I was so hammered after whisky Doomdark offered me...";
	wait = 1;
	break;

    case 5:
	str =
	"Death exclaims: SO BE ON YOUR WAY, FANCYPANTS!";
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
