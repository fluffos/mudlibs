#include <room.h>

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
一间坐落在紫禁城西边的房子，里面的摆设也很简单。屋子的正中放着一
个水缸，也不知道是用来干什么的。水缸旁边做着一位年老的太监，身旁还有
一个小太监在伺候。
LONG );
	set("exits", ([
		"east" : __DIR__"hg",
	]));

	set("objects", ([
		__DIR__"npc/haigonggong" : 1,
		__DIR__"npc/xiaoguizi" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_body", "tang");
}

