inherit "/std/room";
#include "path.h"
#include "config.h"
object board;

void setup ()
{
set_short (GUILDHALL);
set_long (GUILDHALL+ "\n\nThis is where they wrack their "+
"brains thinking of new and improved ways of wracking brains.  Upstairs "+
   "is the fabled Round Table, where fighters gather from across the "+
   "realms to discuss deeds both great and mighty, and to talk of "+
   "matters pertaining to the Guild.\n\n");

	set_light (60);

	add_exit ("norte", ROOMS+"barracks", "door");
	add_exit ("arriba", ROOMS+"meeting", "door"); 
        add_exit("sur",ROOMS+"armory","door");
}

void reset ()
{
	if (!board)
	{
		board = clone_object ("/obj/misc/board");
		board-> move (this_object ());
		board-> set_datafile (DATAFILE);
	}
}

void dest_me ()
{
	if (board)
		board-> dest_me ();
	::dest_me ();
}
