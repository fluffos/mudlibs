//road1.c	土路
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","土路");
	set("long",@LONG 
这是一条山间的土路。由于偏离了大道，行人已经渐渐稀少。
但道路两旁不时有行色匆匆的旅客来来往往。道路仍算宽阔，所以
还有快马来回驰骋。远远望见前面有一座山峰。
LONG
	);

	set("exits", ([
		"north" : __DIR__"road2",
        "southdown" : "/d/jinyang/guandaoe2",
	]));
    set("objects", ([
        "/d/riyuejiao/npc/qinweibang" : 1,
    ]));
	set("outdoors", "riyuejiao");
	setup();

}

