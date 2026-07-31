// conglinggu.c 葱岭谷(kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "葱岭谷");
		  set("long",@long
你的眼前突然为之一亮，只见一条象被一刀劈开的峡谷岩石间，高山的雪
水泻落到千丈以下的山涧里去，溅起的密密的飞沫激起一种惊心动魄的震憾。
就在这深山野谷的溪流边，却长满了各种各样的花草树木，春天繁花开遍峡谷
秋天果实压满山腰，人迹罕至，正是鸟兽们的乐园。
long);

		 set("exits",([
			"out" : __DIR__"shanlin"+(random(5)+1),
		 ]));

		 set("objects", ([
                        __DIR__"obj/huangqi.c" :  1,
                        __DIR__"obj/dongchongcao.c" : 2,
		 ]));

	setup();
	replace_program(ROOM);
}
