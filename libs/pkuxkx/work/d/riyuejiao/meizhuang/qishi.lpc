//qishi.c   棋室
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","棋室");
	set("long",@LONG 只见好大一间房中，除了一张石几、两只软椅之外，空荡荡的一无所有，石几
上刻着纵横十九道棋路，对放着一盒黑子、一盒白子。这棋室中除了几椅棋子之外
不设一物，当是免得对局者分心。
LONG
	);

	set("exits", ([
		"east"	: __DIR__"yuanzi",
	]));
	set("objects",([
		__DIR__"npc/heibai":1,
		]));

	setup();

}




