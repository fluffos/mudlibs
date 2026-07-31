// /u/jpei/thd/chufang1.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是给桃花岛弟子们做饭用的厨房，供应弟子们每日的饭食。屋中充斥着
青菜和调料的味道。几个厨师正在忙碌着。偶尔会有些吃不完的主食和做菜时
剩下的猪肉留在这里。
LONG
	);

	set("exits", ([
		"south" : __DIR__"fanting1",
	]));
	
	set("objects",([
		__DIR__"obj/meat" : 2,
		__DIR__"obj/baozi" : 1,
		__DIR__"obj/rice" : 1,
	]));
	
	setup();
}
