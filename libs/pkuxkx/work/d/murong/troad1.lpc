//troad1.c
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
		"north" : __DIR__"troad2",
		"east" : __DIR__"tbank",
    ]));
    
    set("outdoors", "murong");
    setup();

}
