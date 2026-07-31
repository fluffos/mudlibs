// Room: /d/lumaji/kezhan2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "客栈二楼");
	set("long", @LONG
这里是客店的二楼，可以听到从旁边客房里不时地呼呼的打
酣声，一阵高过一阵。不时有睡意朦胧的旅客进进出出。
LONG
	);

	set("exits", ([
		"down" : __DIR__"kezhan",
		"east" : __DIR__"kezhan3",
	]));

	setup();
	
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
	return ::valid_leave(me,arg);
}