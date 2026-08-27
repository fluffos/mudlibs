/*
   sc_room.c 
   a room to show how one can use the swim and climb skill
*/

inherit "/std/room";
#include <ss_types.h>
#include <macros.h>

#define HARD_TO_CLIMB 40 /* how hard is it to climb the tree ? */
#define HARD_TO_SWIM  40 /* how hard is it to swim in the lake? */
#define DAMAGE        10 /* What's the damage if you don't succeed? */
/* Note that a player with the skill 40 will always manage to swim or climb
   but with lower in that skill he will only succees if he's lucky. */

/*
 * Function name: create_room()
 * Description  : Create the room.
 * In this function, we declare everything that should be fixed
 * when the room is started, and not changed in resets.
 */

create_room()
{
    set_short("A room with a tree, and a lake");
    set_long("You are in room that has a tree standing in it.\n" +
	     "There is also a lake here, you could either swim\n" +
	     "in the lake by trying to go east or climb the,\n" +
	     "tree trying to go up.\n");
    add_exit("/doc/examples/room/tree", "up", "@@climb");
    add_exit("/doc/examples/room/lake", "east", "@@swim");
    add_item("tree", 
	     "It's a high tree and it looks hard to climb, but.\n" +
	     "you can manage.\n");
    add_item("lake",
             "The lake looks inviting to the people who can swim.\n");
}

/*
 * Function name: climb and swim
 * Description  : This function is run every time someone tries to move up
 *                or as we think of it, tries to climb the tree.
 * The returning value decides what will happen to the player.
 * 0 means that the player isn't delayed.
 * 1 means that the player don't move, and that no other exits are tried.
 * 2 and more also stops the player, but the player can still move if 
 * there's another exit in the same dir. 2 is a very good value if you want
 * to make an 'enter mansion' direction.
 */

climb() 
{
    if (this_player()->query_skill(SS_CLIMB) < random(HARD_TO_CLIMB))
    {
	write("You didn't manage to climb the tree and fell down.\n");
	write("Oouch, that hurt!\n");
	this_player()->reduce_hit_point(DAMAGE);
	say(QCTNAME(this_player()) + " fell down the tree and got hurt.\n");
	return 1;
    }

    write("You climb up the tree.\n");
    return 0;
}

swim()
{
    if (this_player()->query_skill(SS_SWIM) < random(HARD_TO_SWIM))
    {
        write("The waves where too much for you, you get thrown up on land.\n");
        write("Oouch, that hurt!\n");
        this_player()->reduce_hit_point(DAMAGE);
        say(QCTNAME(this_player()) + " tried to swim but the waves where to big.\n");
        return 1;
    }

    write("You swim out the lake.\n");
    return 0;
}

