// zhujia.c 铸甲房
// 星星lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "商行");
        set("long", @LONG
这是一个很平常普通的商行！人来人往很热闹,如果你有什么
自制的东西可以在这里用sell买出去,用value估价。
LONG
        );

        set("exits", ([
                "north" : "d/xiangyang/dangpu",
        ]));
	set("objects", ([
		__DIR__"shangren" : 1,
	])); 

        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

