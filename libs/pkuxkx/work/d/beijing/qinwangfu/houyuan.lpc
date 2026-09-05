
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是这座大宅子的后院，曲径通幽，让人心旷神怡。
LONG
	);

	set("exits", ([
		"enter" : __DIR__"sleeproom",
        "east" : __DIR__"huayuan",
        "west" : __DIR__"dating",
        "north" : __DIR__"xiangfang3",
        "south" : __DIR__"xiangfang4",
	]));
    set("max_contain_items",10);
	setup();
}

