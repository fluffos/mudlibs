//mgongju.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "工具房");
    set("long", @LONG
这里放满了各种工具，还有很多茶花的种子，想要栽种茶花的话，
可以在这里找到需要的东西。
LONG
    );

    set("exits", ([
		"north" : __DIR__"mroad7",
    ]));

	set("objects",([
		__DIR__"obj/huazhong" : 1,
		__DIR__"obj/chutou" : 1,
        ]));

    
    set("outdoors", "murong");
    setup();

}
