#include <areas.h>

#ifndef ROOM_DARKELF
#define	ROOM_DARKELF "death/workroom"
#define	ROOM_END "/room/church"
#endif

#include <player_defs.h>

int
dead_dark_elf(object tp, int count)
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
	"Death says: So you are dead. Your immortal spirit will come with me \
and stay in eternity until the end of the world!";
	wait = 3;
	break;

    case 2: str =
	"Death extends one pale hand and leads you forward through a shimmering doorway\
 appearing into air next to it. Terrible cold squeezes your soul as \
you enter a dark emptiness.";
	wait = 1;
	break;

    case 3: tp->move_player("X",AREA_TRISTEZA+ROOM_DARKELF);
	break;

    case 4: str =
	"Death says: This will be your place for a billion years, evil thing.";
	break;

    case 5: str =
	"Death leads you forward through the void. You hear screams of other \
anguished souls, tortured here for every second of their unlife!";
	break;

    case 6: str =
	"You arrive before a great building made of obsidian-like black stone, \
and with tall columns supporting the roof above. You follow Death up \
the stairs and enter the Great Library of Souls where all the life \
stories of Dark Elves are recorded.";
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
	"Death says: There seems to be a mistake. Thou shalt not yet enter the\
 Void. Thy endless waiting for is not yet to start.";
	break;

    case 10: str =
	"Death rises its staff and the crystal flares brightly for a moment. The\
 walls of the library fade around you, and you spin through the void hearing\
 the voice of Death whispering to you.";
	wait = 1;
	break;

    case 11: str =
	"Death says : I shall wait for thee, Dark Elf. I have time.";
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
