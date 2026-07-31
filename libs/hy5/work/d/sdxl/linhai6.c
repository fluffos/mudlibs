// sdxl
// by dubei
#include <room.h>
inherit ROOM;


void create()
{
	set("short", "林海");
	set("long", @LONG
这里是一片一望无垠林海，每棵树木都有十来丈高，周围阡陌
交错，你进来感觉到自己迷路了
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"linhai"+(random(13)+1),
		"southeast" : __DIR__"linhai7",
		"northwest" : __DIR__"linhai"+(random(13)+1),
		"southwest" : __DIR__"linhai"+(random(13)+1),
		"south" : __DIR__"linhai"+(random(13)+1),
		"east" : __DIR__"linhai5",
		"north" : __DIR__"linhai"+(random(13)+1),
		"west" : __DIR__"linhai"+(random(13)+1),
	]));

	set("outdoors", "xiangyang");
	setup();
            replace_program(ROOM);
}
 

