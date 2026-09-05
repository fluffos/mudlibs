//ylianwu1.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "练武场");
    set("long", @LONG
这里是慕容家的练武场，旁边摆满了十八般兵器，这里设备
齐全，很多年轻弟子正在这里勤修苦练。
LONG
    );

    set("exits", ([
		"north" : __DIR__"ylianwu2",
		"east" : __DIR__"ybingqi",
		"west" : __DIR__"yshitang",
		"south" : __DIR__"yroad7",
    ]));
    
	set("objects", ([
		__DIR__"npc/bao" : 1,
		__DIR__"npc/ding" : 2,
		]));

    set("outdoors", "murong");
    setup();

}
