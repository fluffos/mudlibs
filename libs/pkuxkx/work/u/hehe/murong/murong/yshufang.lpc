//yshufang.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "书房");
    set("long", @LONG
这是燕子坞的书房，里面摆满了各种书籍，慕容公子平时就在这里看书。
LONG
    );

    set("exits", ([
		"east" : __DIR__"yketing",
    ]));

	set("objects", ([
		__DIR__"npc/murongfu" : 1,
		]));

    set("outdoors", "murong");
    setup();

}
