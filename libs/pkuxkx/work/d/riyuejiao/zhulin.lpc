//竹林

#include <ansi.h>
inherit ROOM;
#include "bamboo.h"
void create()
{
	set("short",HIG"竹林"NOR);
	set("long",@LONG 
这里是一大片竹林，竹林间偶尔有小动物穿行。
LONG
	);

	set("exits", ([
		"south" : __DIR__"zhulin3",
		"west" : __DIR__"rukou",
		"north"	: __DIR__"zhulin1",
        "east" : __DIR__"zhulin2",
	]));
	/*set("objects",([
               CLASS_D("riyuejiao") + "/tong" : 1,
		__DIR__"npc/jiaozhong1"	: 4,
		]));*/
	set("outdoors", "riyuejiao");
	setup();

}
void init()
{
    add_action("do_pi", ({ "pi","chop" }));
}
int valid_leave(object me, string dir)
{
    object kd;
    if (present("kan dao",me))
    {
        kd=present("kan dao",me);
    }
    if (kd&&kd->query("is_kandao")&&dir=="west")
	return notify_fail("连柴刀都偷，你也太没品了吧。\n");
        return ::valid_leave(me, dir);
}






