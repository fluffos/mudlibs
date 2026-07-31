
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "衙门");
	set("long", @LONG
这是徐州衙门的正门，这个衙门是新建的，只能算是一个大点的庭
院。
LONG );
	set("exits", ([
		"south" : __DIR__"nanmen",
                 "northeast" : __DIR__"eastdao",  
                "northwest" : __DIR__"westdao",
		///"east" : "/d/clone/room/cityroom/xucheng",
	]));
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

