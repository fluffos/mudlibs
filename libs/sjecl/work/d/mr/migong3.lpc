// /d/mr/migong3.c

inherit ROOM;

void create()
{
	set("short","迷宫");
	set("long",@LONG
这里是姑苏慕容的地下迷宫。显然是通向一个重要的地方。四周的墙壁上
挂着露水，并无任何特殊标记，你一走进来便迷失了方向。
LONG);

	set("exits",([
		"east" : __DIR__"migong2",
		"west" : __DIR__"migong4",
		"north" : __DIR__"migong3",
		"south" : __DIR__"migong1",
	]));

	setup();
}

#include "migong.h"
