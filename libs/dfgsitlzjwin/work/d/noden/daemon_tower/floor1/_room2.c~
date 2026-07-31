#include <../tower.h>

inherit ROOM;

void create()
{
	::create();
//	if ( !ob ) return ;
	set_short("恶魔塔内");
	set_long( @C_LONG_DESCRIPTION
这里是恶魔塔的第二个房间.
C_LONG_DESCRIPTION
	);
	set( "exits", ([ 
		"south" : TOWER_F1"room1", 
//		"north" : TOWER_F1"room1",
	]) );
/*
	ob->set("objects",([
		"orc" : MOB"orc",
		]) );
*/
	reset();
replace_program(ROOM);
}
