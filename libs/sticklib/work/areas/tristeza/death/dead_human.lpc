#include <areas.h>

#ifndef ROOM_HUMAN
#define ROOM_HUMAN "death/workroom"
#define	ROOM_END "/room/church"
#endif

#include <player_defs.h>

int
dead_human(object tp, int count)
{
    string str;
    int    wait;

    wait = 5;
    switch (count) {
    case 0: str =
	"You can see a hooded skeletal figure standing beside your corpse. He is\
 wiping the bloody blade of a wicked looking scythe with slow measured\
 motions. Suddenly he stops and seems to look straight at you with his\
 empty...no, not empty but.... orbs....";
	wait = 3;
	break;

    case 1: str =
	"Death says: COME WITH ME, MORTAL ONE!";
	wait = 1;
	break;

    case 2: str =
	"He reaches for you and suddenly you find yourself in another place.";
	wait = 1;

    case 3: tp->move_player("X",AREA_TRISTEZA+ROOM_HUMAN);

	wait = 2;
	break;

    case 4: str =
	"Death says: IT IS TIME";
	wait = 1;
	break;

    case 5: str =
	"Death lifts his right arm and makes beckoning motion. You feel quite certain\
 that if you had been alive you would have died from fear on the spot.\
 Strangely enough you don't feel anything like that at all. Just a mild\
 curiosity.";
	wait = 3;
	break;

    case 6: str =
	"Death says: COME HERE, I MUST READ YOUR SOUL.";
	wait = 1;
	break;

    case 7: str =
	"Death steps closer, reaches out a bony hand straight into your chest,\
 grabbing something that is within! You feel a strange internal yank as\
 your very soul is removed for examination...Suddenly Death collects your\
 bodyless essence with great sweeping motions of his skeletal hands and\
 puts you in a small glass orb that he inserts into his right eye socket!\
 You feel a strange blue light from within his eyeless orb penetrate you\
 as he leans over the chart.";
	wait = 6;
	break;

    case 8: str =
	"Death says: NOT MUCH OF A LIFE I CAN SAY. YOU MISERABLE MORON.";
	wait = 1;
	break;

    case 9: str =
	"Death removes the orb from his eye and stands up. Suddenly he turns and\
 walks out of the room through the nearest wall, still holding you in\
 his skeletal hand! He walks rapidly through a dark winding corridor,\
 down a staircase to the innermost room in the bottom of the cellar.";
	break;

    case 10: str =
	"Finally he stops in front of a door bearing the words 'ETERNITY' in\
 black letters. On the door you can see a small hatch which Death opens\
 with a flick of his hand. From the open hatch you can hear the moaning\
 murmurs of a million souls. Slowly he lifts you to the gaping maw\
 of the hatch.";
	break;

    case 11: str =
	"A small daemon arrives from one of the walls to Death and whispers something to\
 it's ear.";
	wait = 1;
	break;

    case 12: str =
	"Death says: WHAT DO YOU MEAN? AN ERROR! THIS SOUL IS MINE!";
	wait = 2;
	break;

    case 13: str =
	"The daemon whispers something more to the Death.";
	wait = 1;
	break;

    case 14: str =
	"Death walks in front of you holding his scythe on the shoulder.";
	break;

    case 15: str =
	"Death says: OH ALL RIGHT THEN! I CAN WAIT. ONE DAY YOU WILL BE MINE ANYWAY!";
	wait = 2;
	break;

    case 16: str =
	"The Grim Reaper hurls you up in the air, you feel a strange sensation\
 as you pass through the very walls of the building, out in the open air,\
 through some other walls and fairly surprised horses before you finally\
 stop on a vaguely familiar place...";
	wait = 1;
	break;

    case 17: tp->move_player("X",ROOM_END);
	/* no break */

    default:
	tp->set(LIV_NO_DEATH_MARK);	// Important!
	destruct(this_object());
    }
    if (str)
	tp -> tell_me(str + "\n");
    return wait;
}
