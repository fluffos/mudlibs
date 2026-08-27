
inherit "/std/room";
#include <ss_types.h>
#include <macros.h>

#define HARD_TO_SWIM  20 /* how hard is it to swim across the water? */
/* Note that a player with the requisite skill will always manage to swim 
   but with lower in that skill he will only succeed if he's lucky. */

/*
 * Function name: create_room()
 * Description  : Create the room.
 * In this function, we declare everything that should be fixed
 * when the room is started, and not changed in resets.
 */

create_room()
{
    set_short("South Bank of the Fords of Isen");
    set_long("You are standing on the south shore of a wide and swift-flowing river.\n" +
	"A stone marker or obelisk stands nearby.\n" +
	"In the middle of the stream is a rocky eyot, or small island.\n" +
	"The road here crosses the stream and advances up the other side.\n" +
	"In the distance you see another road which parallels the far shore.\n");
    add_exit("/d/Gondor/zephram/dunland/road/r01", "northwest", "@@swim");
    add_item(({"ford","fords","fords of Isen","Fords of Isen","fords of isen"}),
	"The river Isen runs swiftly over wide shallows here.\n" +
	"It looks like anyone with a minimum of skill could swim across.\n");
    add_item("water",
	"The water is cool and clear, shallow but swiftly flowing.\n");
    add_item(({"stone","marker","obelisk"}),
	"The marker says, 'Here is established the border of the Realm of Rohan.\n" +
	"By order of Cirion, Lord Steward of Gondor, and King Eorl of Rohan.'\n");
}

/*
 * Function name: swim
 * Description  : This function is run every time someone tries to swim
 * The returning value decides what will happen to the player.
 * 0 means that the player isn't delayed.
 * 1 means that the player don't move, and that no other exits are tried.
 * 2 and more also stops the player, but the player can still move if 
 * there's another exit in the same dir. 2 is a very good value if you want
 * to make an 'enter mansion' direction.
 */

swim()
{   
    int DIFFICULT;
    DIFFICULT=random(HARD_TO_SWIM)-2;
    if (this_player()->query_skill(SS_SWIM) < DIFFICULT)
    {
        write("This water is too difficult for you to swim safely.\n");
	write("You are struggling.\n");
        write("You start to inhale water!\n");
	this_player()->reduce_hit_point(DIFFICULT-this_player()->query_skill(SS_SWIM));
	write("Your body washes back to near your starting point.\n");
        say(QCTNAME(this_player()) + " fails to make it to the other shore.\n");
        return 1;
    }

    write("You swim across the ford.\n");
    return 0;
}

