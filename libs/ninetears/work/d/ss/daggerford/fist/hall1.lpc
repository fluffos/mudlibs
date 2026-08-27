inherit "/std/room";
#include "path.h"
object board;

void setup ()
{
  set_short("Hall of the Silver Fist");
  set_long("You are standing in the halls of the fabled Band of the Silver "+
   "fist.  Only the mightiest men and women from across the lands may set "+
   "foot in this hall.\n");

	set_light (60);

   add_exit("north",ROOM+"hall2","door");
   add_exit("south",ROOM+"hall3","door");
   add_exit("east",ROOM+"entrance","door");
   add_exit("west",ROOM+"hall4","door");
}

void reset ()
{
	if (!board)
	{
		board = clone_object ("/obj/misc/board");
		board-> move (this_object ());
		board-> set_datafile ("silverfist");
	}
}

void dest_me ()
{
	if (board)
		board-> dest_me ();
	::dest_me ();
}
