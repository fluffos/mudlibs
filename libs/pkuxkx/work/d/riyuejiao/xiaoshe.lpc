//xiaoshe.c	小舍
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","小舍");
	set("long",@LONG 
一进门，便闻到一阵浓冽的花香，见房中挂着一幅仕女图，图中绘着三个美女，
椅上铺了绣花锦垫。似是一处闺中女子所住之所。
LONG
	);
	set("exits", ([
		"south" : __DIR__"huayuan",
		"west" : __DIR__"guifang",
	]));
        set("no_task",1);
	setup();
}

