/*
  /room/start.c

  This object is the default start location if none defined in /secure/config.h

*/
#pragma save_binary

inherit "/std/room";

reset_room(arg)
{
    if (arg) return;

    set_short("Platform in the middle of nowhere");
    set_long(break_string(
	"You are standing on a platform floating just above the ground " +
	"in the middle of nowhere. There is transparent walls all around " +
	"you, except for a small opening in the south corner.\n",76));

    add_exit("*map|x500.0y500.0", "south", "*go_off");

    add_item( ({ "wall", "surroundings" }),
	     "There is simply nothing to see, all is empty.\n");
    add_item( ({ "matrix", "cyberspace" }),
	     "Yes, that is what is out there, and all empty.\n");
}

go_off(dest)
{
    write("As you leave the platform it dissolves behind you.\n");
    return 0;
}

