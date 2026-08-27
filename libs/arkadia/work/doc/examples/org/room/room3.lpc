/* room3.c
   Mort 911004 */

inherit "/std/room";

/*
 * Function name: create_room()
 * Description  : Create the room.
 * In this function, we declare everything that should be fixed
 * when the room is started, and not changed in resets.
 */

create_room() {
    
    set_short("A room with items, and a special exit");
    set_long("You are in room that have a curtain on the wall.\n" +
	     "You can look at it, but not get it.\n");
    add_exit("/doc/examples/room/room2", "south", 0);
    add_exit("/doc/examples/room/room4", "north", "@@construction");
    add_item("curtain", 
	     "The curtain is made of silk. It looks very expensive.\n");

}

/*
 * Function name: construction()
 * Description  : This function is run every time someone tries to move north.
 * The returning value decides what will happen to the player.
 * Negative values means that you delay the player one heart_beat 
 * for every number below 0 you go. 0 means that the player isn't delayed.
 * 1 means that the player don't move, and that no other exits are tried.
 * 2 and more also stops the player, but the player can still move if 
 * there's another exit in the same dir. 2 is a very good value if you want
 * to make an 'enter mansion' direction.
 */

construction() 
{
    write("This area is still under construction. Please come back later.\n");
    return 1;
}
