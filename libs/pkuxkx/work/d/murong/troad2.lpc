//troad2.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条鹅卵石铺成小路，此处甚为幽静，真是一个好去处。
LONG
    );

    set("exits", ([
		"south" : __DIR__"troad1",
		"west" : __DIR__"troad3",
    ]));
    
    set("outdoors", "murong");
    setup();

}
