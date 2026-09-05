//road2.c	土路
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
		"northeast" : __DIR__"road3",
		"south"	: __DIR__"road1",
	]));
	set("outdoors", "riyuejiao");
	setup();

}

