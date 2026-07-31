// Room: /d/datong/ylinn4.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间很小的客房，陈设十分简陋但非常干净。靠墙放了
一张木床，墙上开了一扇不大的窗户。
LONG
);
	
	set("sleep_room", 1);
	
	set("hotel",1);

	set("exits", ([
		"south" : __DIR__"ylinn2",
	]));
	setup();
	create_door("south", "房门", "north", DOOR_CLOSED);
}

void init()
{
	object me = this_player();
	if(!wizardp(me))
	{
		add_action("do_leave","quit");
		set_temp("have_person",1);
	}
	return;
}

int do_leave(string arg)
{
	delete_temp("have_person");
	return 0;
}

int valid_leave(object me,string arg)
{
	delete_temp("have_person");
	return ::valid_leave(me,arg);
}
