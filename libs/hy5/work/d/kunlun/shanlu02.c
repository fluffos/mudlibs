// shanlu01.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "山路");
		  set("long",@long
这是一条盘山的路，路边花草满地，路面似乎很久没有修整了，显得
有些破旧，但是从遗留的痕迹依稀可以看出当年的辉煌。北面是山下，
南面山上是昆仑派的所在。
long);
		 set("exits",([
"northdown" : __DIR__"shanlu01",
"southup" : __DIR__"shanlu03",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
