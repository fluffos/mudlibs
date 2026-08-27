#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(80);
	set_short("Southwest tower of Daggerford");
	set_long(
"\n"+
"You now stand below what was once known as the Tower of Mystics.  The "+
"Mystics, strange bedfellows of the Mages, wielded amazing magical powers "+
"to deceive the mind.  Through their actions, truth became fiction; fiction "+
"became truth.  Sight was belief.  The Mystics disappeared long ago, but "+
"this single monument (their former haven) still stand to do honor to their "+
"work.\n\n");

	add_exit("north", ROOM+"wall17", "road");
	add_exit("east", ROOM+"wall18","road");

	add_item("tower",
"This stone tower rises to about the height of three men.  It is difficult "+
"to say for sure, because the winds of Time have effaced most of the arcane "+
"markings which once graced the tower, but you believe that you see "+
"something like \"p'zno__kleshti____r~__drak\" among the writings.  There is "+
"still an entrance to the tower, leading up into a heavy mist, but it is "+
"forbidden to enter this once great tower, for dangerous magic lives on "+
"within it.\n");

	set_zone("city");

	set_monster(NUM, "city");
}

void reset()
{
	::reset();
        if(!present("cityguard"))
	{
		guard=clone_object(CHAR+"cityguard");
		guard->move(this_object());
	}
}
