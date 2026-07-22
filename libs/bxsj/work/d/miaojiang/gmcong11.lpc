// 苗疆 gmcong

#include <room.h>
inherit ROOM;


void create()
{
	set("short", "灌木丛");
	set("long", @LONG
这里是一片一人多高的灌木丛，这里已经罕见足迹。一阵风吹过，灌木丛
发出沙沙的声音。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gmcong"+(random(13)+1),
        "west" : __DIR__"gmcong"+(random(2)+12),
		"south" : __DIR__"gmcong"+(random(13)+1),
		"north" : __DIR__"gmcong"+(random(13)+1),
	]));

	set("outdoors", "苗疆");
	setup();
}
 

