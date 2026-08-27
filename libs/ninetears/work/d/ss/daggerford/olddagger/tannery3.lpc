#include "path.h"

inherit "/std/room";


void
setup()
{
		set_light( 50 );
		set_short( "Vic's Bed Room" );
		set_long( "Vic's bedroom is quite small.  A fur covered bed nearly "+
			"fills the room.  A small empty nightstand is by the bed, and a "+
			"window looks down on the road below.  An open door leads "+
			"east.\n" );

		add_exit( "east" , ROOM+"tannery2" , "door"  );

		add_alias( "iron handle"         , "handle" );
		add_alias( "wrought iron handle" , "handle" );

		add_item( "nightstand", "Just a place to put a book or drink.\n" );
		add_item( "bed",
			"It's a fairly large bed.  After all, Vic is a big man.  It "+
			"just about fills the whole room.  A beautiful blanket made "+
			"of fox fur covers it.\n");
		add_item( "door",
			"The door leads east into the living room.\n");
		add_item( "fur",
			"The bed is covered with beautiful red fox fur.  It seems Vic "+
			"is rather partial to fox.\n");
		add_item( "road",
			"It's the Tanner's Road.  Strange place for it to be huh ?  "+
			"Just outside the Tanner.\n");
		add_item( "window",
			"The window looks out onto the road below.\n");
}
