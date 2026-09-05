//yroad7.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小道");
    set("long", @LONG
这是通向燕子坞花园的林间小道，鸟语花香令人心醉。北面
是慕容家的练武场，很多年轻的弟子正在那里勤修苦练。
LONG
    );

    set("exits", ([
		"west" : __DIR__"yroad6",
		"east" : __DIR__"yroad8",
		"north" : __DIR__"ylianwu1",
    ]));
    
    set("outdoors", "murong");
    setup();

}
