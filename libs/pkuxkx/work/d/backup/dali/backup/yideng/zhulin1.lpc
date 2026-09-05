//竹林小径
//by icer

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "竹林小径");        set("long", @LONG
这是一条竹林中的小径，青石铺就。只觉周围绿荫森森，幽静无比，
令人烦俗尽消。竹林中隐着三间石屋。
LONG
);
set("exits", ([
                "south" :__DIR__"xiangfang",
		"north":__DIR__"zhulin1",
		"northwest":__DIR__"shiwu",
]));
        create_door("northwest", "竹门", "southeast", DOOR_CLOSED);


setup();
}

