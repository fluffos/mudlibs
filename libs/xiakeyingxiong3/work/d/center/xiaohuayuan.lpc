// xiaohuayuan.c - 小花园
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com		1997.7

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "小花园");
	set("long", @LONG

    这里是侠客城的小花园。小花园中间有一口水井。
LONG
	);

        set("outdoors", "center");

        set("resource/water", 1);		// 设置可以装水

	set("exits", ([
                "east"	: __DIR__"caichang",
                "west"	: __DIR__"chaguan",
                "north"	: __DIR__"yuqidian",
        ]) );			

        set("objects", ([
                __DIR__"npc/dog": 1 ,
                __DIR__"npc/butterfly": 1,
                __DIR__"npc/bee": 1,
	]) );

	setup();

	replace_program(ROOM);
}
