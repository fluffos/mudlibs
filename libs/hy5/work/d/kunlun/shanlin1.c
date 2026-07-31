// shanlin1.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "云杉林");
		  set("long",@long
这是一片蜿蜒无尽的翠绿的树林，密密的云杉像撑天的巨伞，重重叠叠的
枝丫，只漏下斑斑点点细碎的日影。林子十分幽静，连鸟雀也少飞来，只偶尔
能听到远处的几声鸟鸣。
long);
		 set("exits",([
"west" : __DIR__"shanlin2",
"southeast" : __DIR__"jiuqulang2",
"northeast" : __DIR__"shanlin3",
]));

	set("objects",([
		__DIR__"obj/da-shugan.c" :  1,
		__DIR__"obj/xiao-shuzhi.c" :  1,
	]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
