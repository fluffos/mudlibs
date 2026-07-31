//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厂暗道");
	set("long", @LONG
这是一条暗道，是专为鳌拜从鳌府直接到东厂用的。暗道里一片漆黑
，伸手不见五指，黑暗中更传来阵阵悉所的声响，令人毛骨悚然。不知道
会有什么不幸的事情发生。
LONG );
	set("exits", ([
		"southwest" : __DIR__"aobai10",
		"northeast" : __DIR__"aobai12",
	]));

	setup();
	replace_program(ROOM);
}
