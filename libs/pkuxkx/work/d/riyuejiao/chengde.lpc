//chengde.c	成德殿
//by bing
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","成德殿门");
	set("long",@LONG 
这里是一座富丽堂皇的大殿。殿门宽约两丈，高约三丈，两边盘龙柱子
矗立，正中门额上横挂着一只大牌子，上书「成德殿」三个镏金大字，门前
有若干日月教弟子守卫。东、西是两个大练武场。
LONG
	);
	set("exits", ([
		"south"	: __DIR__"yading",
		"enter"	: __DIR__"changlang1",
        "west" : __DIR__"lianwu1",
        "east" : __DIR__"lianwu2",
	]));
	set("objects", ([
                __DIR__"npc/shizhe": 3,
        ]));

	set("outdoors", "riyuejiao");
	setup();
	"/clone/board/ry_b"->foo();
}

int valid_leave(object me,string dir)
{
    if (!me->query_temp("rynewbiejob/lianwu/start")&&(dir=="west"||dir=="east"))
    {
        return notify_fail("没有教主之令，任何人不得擅入练武场。\n");
    }
    return ::valid_leave(me,dir);
}