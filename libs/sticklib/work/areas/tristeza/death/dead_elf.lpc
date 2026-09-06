#include <areas.h>

#ifndef ROOM_ELF
#define	ROOM_ELF "death/workroom"
#define	ROOM_END "/room/church"
#endif

#include <player_defs.h>

int
dead_elf(object tp, int count)
{
    string str;
    int    wait;

    wait = 4;
    switch (count) {
    case 0: str =
	"Standing in front of you is a tall figure clad in midnight black robes. Its\
 face is hidden by the hood, but two eyes glimmering like stars are visible\
 underneath it. In its right hand it holds a tall staff with a clear crystal\
 embedded into the top.";
	break;

    case 1: str =
	"Death says: Thy mortal life is over, friend. Come with me and I shall show\
 thee thy new life.";
	wait = 3;
	break;

    case 2: str =
	"Death extends one pale hand and leads you forward through a shimmering doorway\
 appearing into air next to it. You enter a large green valley, filled with\
 song of birds and humming of wind in the tops of the tall majestic trees. A\
 deep blue sky arcs over you, and you feel a sense of peace descend over you.";
	wait = 1;
	break;

    case 3: tp->move_player("X",AREA_TRISTEZA+ROOM_ELF);
	break;

    case 4: str =
	"Death says: These are the Gardens of Afterlife, where the Deceased Ones spend\
 their days before their next birth.";
	break;

    case 5: str =
	"Death leads you forward through the beautiful scenery. In distance you see\
 Elves moving along in groups, or sitting under the shades of the trees. Some\
 seem to notice you, but no one tries to come any closer, as if they were\
 avoiding the dark figure walking alongside you.";
	break;

    case 6: str =
	"You arrive before a great building made of white marble, and with tall\
 columns supporting the roof above. You follow Death up the stairs and enter\
 the Great Library of Souls where all the life stories of Elves are recorded.";
	break;

    case 7: str =
	"Death says: I shall write the final entry to the story of thy life, and then\
 enter thy name into the Book of the Dead.";
	wait = 2;
	break;

    case 8: str =
	"Death opens a large tome and a quill appears in its hand. It starts to write,\
 but stops suddenly and looks at you.";
	wait = 2;
	break;

    case 9: str =
	"Death says: There seems to be a mistake. Thou should not yet enter the\
 Gardens of Afterlife. Thy waiting for a new life is not yet to start.";
	break;

    case 10: str =
	"Death rises its staff and the crystal flares brightly for a moment. The\
 walls of the library fade around you, and you spin through the void hearing\
 the voice of Death whispering to you.";
	wait = 1;
	break;

    case 11: str =
	"Death says : I shall wait for thee, Elvenkin. I have time.";
	wait = 2;
	break;

    case 12: str =
	"World again gains shape around you, forming into the familiar graveyard of\
 the village. You stand there, shivering in the slight wind that blows dust\
 and leaves through your ethereal body.";
	wait = 1;
	break;

    case 13: tp->move_player("X",ROOM_END);
	/* no break */

    default:
	tp -> set(LIV_NO_DEATH_MARK);	// Important.
	destruct(this_object());
    }
    if (str)
	tp -> tell_me(str + "\n");
    return wait;
}
