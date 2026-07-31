// xiaolu.c

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIY"谷中小路"NOR);
    set("long", @LONG
你脚踏柔软的青草，走在一条小路上面。四下里树影婆娑，花香扑鼻。迎
面有一座小茅屋，门口地面上长满了青苔，侧耳倾听，四周静悄悄的，决无人
声鸟语，唯有玉蜂的嗡嗡微响。
LONG
        );

    set("outdoors", "绝情谷");

    set("objects", ([
               __DIR__"obj/guo" : 2,
    ]));

    set("exits", ([
	  "south" : __DIR__"tanan",
	  "enter" : __DIR__"zhongtang",
    ]));	
    setup();
    replace_program(ROOM);
}    
