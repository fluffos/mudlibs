//yroad3.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "大道");
    set("long", @LONG
这是通向燕子坞的大道。路面的湖面上铺满了荷叶，荷花与
莲蓬交相辉映。
LONG
    );

    set("exits", ([
		"south" : __DIR__"yroad2",
		"north" : __DIR__"yroad4",
		"west" : __DIR__"yhetang",
    ]));
    
    set("outdoors", "murong");
    setup();

}
