// feilaifeng.c - 飞来峰
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com		1997.7

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "飞来峰");
	set("long", @LONG

    这里是侠客城飞来峰。
LONG
	);

        set("outdoors", "center");

	set("exits", ([
                "east"	: __DIR__"caifengdian",
                "west"	: __DIR__"heisonglin",
                "north"	: __DIR__"xiaoxihu",
        ]) );			

        set("objects", ([
                __DIR__"npc/kid": 2,
	]) );

	setup();

	replace_program(ROOM);
}
