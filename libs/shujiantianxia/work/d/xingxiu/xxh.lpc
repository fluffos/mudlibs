// Room: /d/xingxiu/xxh.c
// Modify by Lklv 2001.10.16

#include <wanted.h>
inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
这里是天山脚下的星宿海海边。因为方圆几百里都是一望无际的湖泊和沼
泽，所以被当地牧人称为“海”。一旦有几只离群的羊迷失在“海”里，便再
也找不着了。臭名昭著的星宿派总坛便设在北面的海中央。
LONG
        );
	set("outdoors", "星宿");
        set("exits", ([
             "north" : __DIR__"xxh1",
             "south" : __DIR__"shanjiao",
             "southeast" : __DIR__"yili/yili",
	]));
	set("objects", ([
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
                __DIR__"npc/azi" : 1,
        ]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if (is_wanted(me) && dir == "north")
		return 0;
	return ::valid_leave(me, dir);
}
