// yadi.c 崖底

#include <room.h>
void init();
int do_dive();
inherit ROOM;

void create()
{
	set("short", "山崖底");
	set("long", @LONG
眼前突然一亮，你看到自己站在山崖底，只见崖底的四周都被高山所包围，无
路可寻。不要说人，就算是鸟也飞不出去。东边有一个只能容一人通过的山洞。
西边有一个小湖（dive），湖水黑黑的，深不见底，给人一种不祥的感觉。
LONG
	);
        set("outdoors", "quanzhen");

         set("objects", ([
                  __DIR__"npc/qilin":1,
                          ]) );
	set("exits", ([
		"east" : __DIR__"yuxudong",
		"south" :__DIR__"qingsonglin14",
	]));
	setup();
}

void init()
{
        add_action("do_dive","dive");
}

int do_dive()
{
        object me = this_player();
        message_vision("$N纵身跃起，空中一个浪里翻花，头下脚上，结果呛了个半死，赶紧爬了上来。\n", me);
        me->move("/d/quanzhen/yadi");
        return 1;
}
