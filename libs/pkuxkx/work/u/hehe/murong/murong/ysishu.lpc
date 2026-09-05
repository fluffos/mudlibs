//ysishu.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "私塾");
    set("long", @LONG
这里是慕容家的私塾，慕容家的子弟都在这里学习文化。
一个老学究正在指点一群学童读书。
LONG
    );

    set("exits", ([
		"east" : __DIR__"ylianwu2",
    ]));

	set("objects", ([
		__DIR__"npc/shusheng" : 1,
		__DIR__"npc/xiaotong" : 2,
		]));
    
    set("outdoors", "murong");
    setup();

}
