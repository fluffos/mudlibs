// The specail rooms, inherit base ROOM, and define some specail functions
// or effects when he arrive these rooms.

#include <mudlib.h>
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set("flamezone", 1);
}

void init()
{
	FLAMEZONE->apply_effect(this_player(), 3, 4);
}
