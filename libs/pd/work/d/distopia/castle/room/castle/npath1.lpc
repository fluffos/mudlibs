#include <std.h>
#include <discastle.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 2, "night light" : 1, "forest" : 1])
	);
	set_short("Road out of Lodos.");
	set_day_long
	(
	        "The castle is visable to the north, the tall spires rising high "
	        "in the distance.  To the south is that raised platform, just thinking "
	        "about it gives a person goosebumps.  The road is beaten "
	        "and battered.  Various debris lies on the side of the road, it seemed like "
	        "someone was trying to set up a barricade."
	);

    set_listen("default", "A soft laughing runs around you.");
	set_night_long
	(
		"There is a glow to the north.  It seems that there is a major population centre "
		"there.  To the south the brilliant light of the dias continues unabaited. "
		"The road is dark, hard to follow, but with enough concentration the moon barely "
		"lights the way."
	);
	set_items
	(
	        ([
	                "castle" : "It looks beautiful",
	                "spires" : "They are so huge",
	                "platform" : "It's so strange. You can't get over it",
	                "debris" : "Pieces of wood line the road everywhere. It looks like they were broken through."
	        ])
	);

	set_exits
	(([
		"north" : ROOMS"npath2",
		"south" : "/d/distopia/room/nexus"
	]));
}
void reset() 
{
	::reset();
	if(!present("brigand"))
	{
		new(MOB"brigand")->move(this_object());
	}
}
