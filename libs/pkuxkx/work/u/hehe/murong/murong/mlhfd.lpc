//mlhfd.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "琅镮福地");
    set("long", @LONG
这里就是曼陀山庄的藏经重地“琅镮福地”，这里
放满了各门各派的武功秘籍，你看了之后不仅狂喜
起来。而且里面还收藏了一把宝刀。
LONG
    );

    set("exits", ([
		"north" : __DIR__"myunjin",
    ]));
	set("objects",([
		__DIR__"obj/yan-dao" : 1,
		]));
    
    set("outdoors", "murong");
    setup();

}
