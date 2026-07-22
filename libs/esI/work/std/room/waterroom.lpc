// The specail rooms, inherit base ROOM, and define some specail functions
// or effects when he arrive these rooms.

#include <mudlib.h>
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set("underwater", 1);
}

void init()
{
	UNDERWATER->apply_effect(this_player(), 3, 1);
}
