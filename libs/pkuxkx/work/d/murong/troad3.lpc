//troad3.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条鹅卵石铺成小路，此处甚为幽静，真是一个好去处。
东南边有一块邻水的空地，看来有点名堂。
LONG
    );

    set("exits", ([
		"east" : __DIR__"troad2",
		"northwest" : __DIR__"troad4",
		"southwest" : __DIR__"tdiaoyu",
    ]));
    
    set("outdoors", "murong");
    setup();

}
