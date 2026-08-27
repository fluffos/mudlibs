/* room2.c
   Mort 911004 */

inherit "/std/room";

/*
 * Function name: create_room()
 * Description  : Create the room.
 * In this function, we declare everything that should be fixed
 * when the room is started, and not changed in resets.
 */

create_room() {

    set_short("A room with items");
    set_long("You are in room that have some torches on the wall.\n" +
	     "You can look at them, but not get them.\n");
    add_exit("/doc/examples/room/room1", "south",0);
    add_exit("/doc/examples/room/room3", "north", 0);
    add_item( ({ "torch", "torches" }) , 
	      "The torches are all lit.\n");

}

/*
 * Function name:
 * Description  :
 */

