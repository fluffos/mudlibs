// Room: /d/datong/ylinn2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "客栈二楼");
	set("long", @LONG
你正走在客店二楼的走廊上，可以听到从客房里不时地呼呼
的打酣声，一阵高过一阵。不时有睡意朦胧的旅客进进出出，到
楼下的掌柜处付了钱再上来睡觉。
LONG
	);

	set("exits", ([
		"down" : __DIR__"ylinn",
		"east" : __DIR__"ylinn3",
		"north" : __DIR__"ylinn4",
	]));

	setup();
	create_door("east", "房门", "west", DOOR_CLOSED);
	create_door("north", "房门", "south", DOOR_CLOSED);
}

int valid_leave(object me,string arg)
{
	object room;
	if(arg == "east")
	{
	room = find_object(__DIR__"kezhan3");
	if(!room) return ::valid_leave(me,arg);
	if(room->query_temp("have_person"))
		return notify_fail("这间客房里有人了。\n");
	return ::valid_leave(me,arg);
	}
	if(arg == "north")
	{
	room = find_object(__DIR__"kezhan4");
	if(!room) return ::valid_leave(me,arg);
	if(room->query_temp("have_person"))
		return notify_fail("这间客房里有人了。\n");
	return ::valid_leave(me,arg);
	}

	return ::valid_leave(me,arg);
}