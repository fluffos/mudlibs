//yneishi.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "内室");
    set("long", @LONG
这是慕容家的内室，有几个丫鬟正在布置房间。
LONG
    );

    set("exits", ([
		"south" : __DIR__"yketing",
    ]));

	set("objects", ([
		__DIR__"npc/yahuan" : 2,
		]));
    
    set("outdoors", "murong");
    setup();

}
