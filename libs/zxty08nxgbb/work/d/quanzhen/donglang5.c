// donglang5.c 东厢走廊
// by kyd

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厢走廊");
	set("long", @LONG
你走在一条走廊上，人来人往很热闹。房顶一侧支在南面的雷祖殿上，
另一侧则与东北边三官殿的屋顶相连。走廊二边的墙上刻着的是二十四孝的
图形，每一幅图案都有一个生动的故事。
LONG
	);

	set("exits", ([
		"south" : __DIR__"leizudian",
		"northeast" : __DIR__"sanguandian",
	]));
	
       setup();
       replace_program(ROOM);

}

     
	
