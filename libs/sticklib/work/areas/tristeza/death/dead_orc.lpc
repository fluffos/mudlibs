#include <areas.h>

#ifndef ROOM_ORC
#define ROOM_ORC "death/workroom"
#define ROOM_END "/room/church"
#endif

#include <player_defs.h>

int
dead_orc(object tp, int count)
{
    string str;
    int    wait;

    wait = 5;
    switch (count) {
    case 0: str =
	"You see a huge dark shape standing next to your bloody corpse. It is clad\
 in a dark suit of armour and wields a long wicked blade that seems to glow\
 with a faint aura of darkness. Red burning eyes glare at you from the depths\
 of the demonic helmet. A fiery Orcish rune of Death and Destruction glows in\
 the apparition's breast as it steps over your corpse towards you.";
	break;

    case 1: str =
	"The Death steps forward and swings its frightful blade, severing your soul's\
 last connection with your dead body. It laughs coarsely as it grabs you up\
 with its ice-cold hand and starts to sink into the ground.";
	wait = 1;
	break;

    case 2: tp->move_player("X",AREA_TRISTEZA+ROOM_ORC);
	break;

    case 3: str =
	"You have a sickening feeling as you fall down through the ground in the grasp\
 of Death. Just as you are sure that you are going to fall straight to the\
 center of the earth, you enter a large underground cavern illuminated by\
 flaming pits of molten rock.";
	break;

    case 4: str =
	"Death says : ALL YOUR LIVES YOU BELIEVED THAT YOU WOULD LIVE IN A PARADISE\
 WHERE YOU COULD FIGHT AND KILL ETERNALLY. HA HA HA";
	wait = 2;
	break;

    case 5: str =
	"Death says : BUT YOU COULD NOT HAVE BEEN MORE WRONG. HA HA HA!";
	wait = 3;
	break;

    case 6: str =
	"Pale shapes of tormented souls hang in chains from the walls and over the\
 fiery pits. Their wailing and howling fills the cavern with a terrible\
 cacophony of death and agony. Death strides towards one exceptionally large\
 and hot pit, and you see a dark spiked chain hanging vacant over it.";
	break;

    case 7: str =
	"Death says : YOU WILL HANG HERE IN ETERNAL TORMENT, AND I WILL WATCH YOU\
 SUFFER! HA HA HA.";
	break;

    case 8: str =
	"Death laughs cruelly as he starts to lock the chains around your ethereal\
 wrists. As your writhe in the agony of the spikes impaling your ghostly flesh\
 and the burning heat, you see that the chains have your name written in them.";
	break;

    case 9: str =
	"Death says : GO ON, TRY TO ESCAPE. IT WILL AMUSE ME. HA HA HA...";
	wait = 3;
	break;

    case 10: str =
	"Suddenly you notice that in its glee Death has forgotten to lock your right\
 hand properly. Before it can notice, you break the chain holding your left\
 hand and land heavily on the rim of the pool of lava. As you sprint across\
 the floor of the cavern, jumping over the chained souls lying everywhere, you\
 hear the Death scream in rage behind you.";
	break;

    case 11: str =
	"Death screams : YOU CAN'T ESCAPE ME, YOU INSOLENT LITTLE SOUL!";
	break;

    case 12: str =
	"You dodge a swing of a dark sword wielded by a skeletal warrior appearing\
 out of thin air beside you, and run forward. Snarling you grab hold of a\
 large chunk of stone and hurl it towards a hellish hound that bounces at you\
 from behind a heap of wailing souls. As your pursuers hesitate in confusion,\
 you slip into a narrow crack in the stone.";
	break;

    case 13: str =
	"Death screams : BRING THAT SOUL BACK, MY SERVANTS. IT BELONGS TO ME!";
	wait = 3;
	break;

    case 14: str =
	"Panting you scramble up the narrow passage, leaving your daemonic pursuers\
 far behind. Finally you reach the top of the tunnel and frantically claw your\
 way through the earth and stone blocking your way to surface.";
	wait = 3;
	break;

    case 15: str =
	"Just as you emerge from the ground in the center of the graveyard, your hear\
 Death's distant shout echoing from far underground.";
	wait = 1;
	break;

    case 16: str =
	"Death screams : ONE DAY YOU WILL BE MINE!";
	break;

    case 17: tp->move_player("X",ROOM_END);
	/* no break */

    default:
	tp->set(LIV_NO_DEATH_MARK);	// Important
	destruct(this_object());
    }
    if (str)
	tp -> tell_me(str + "\n");
    return wait;
}
