//yroad8.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小道");
    set("long", @LONG
这是通向燕子坞花园的林间小道，鸟语花香令人心醉。再往
东就到慕容家的后花园了。
LONG
    );

    set("exits", ([
		"west" : __DIR__"yroad7",
		"east" : __DIR__"yhuayuan",
    ]));
    
    set("outdoors", "murong");
    setup();

}
