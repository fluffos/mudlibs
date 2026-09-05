//troad4.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条鹅卵石铺成小路，此处甚为幽静。西面有座农舍，也
甚为别致。
LONG
    );

    set("exits", ([
		"west" : __DIR__"thouse1",
		"north" : __DIR__"troad5",
		"southeast" : __DIR__"troad3",
    ]));
    
    set("outdoors", "murong");
    setup();

}
