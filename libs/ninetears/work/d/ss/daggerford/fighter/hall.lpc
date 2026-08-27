inherit "/std/room";
#include "path.h"
object board;

void setup ()
{
set_short ("Guildhall of Fighters");
set_long (""+
"  This is the Guildhall of Fighters.  This is where they wrack their "+
"brains thinking of new and improved ways of wracking brains.  Upstairs "+
   "is the fabled Round Table, where fighters gather from across the "+
   "realms to discuss deeds both great and mighty, and to talk of "+
   "matters pertaining to the Guild.\n");

	set_light (60);

	add_exit ("north", ROOM +"barracks", "door");
	add_exit ("up", ROOM +"meeting", "door"); 
}

void reset ()
{
	if (!board)
	{
		board = clone_object ("/obj/misc/board");
		board-> move (this_object ());
		board-> set_datafile ("fighterguild");
	}
}

void dest_me ()
{
	if (board)
		board-> dest_me ();
	::dest_me ();
}
