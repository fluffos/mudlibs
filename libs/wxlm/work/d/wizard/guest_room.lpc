// /d/wizard/guest_room.c

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "巫师会客室");
	set("long", @LONG
这是巫师会客的地方。
LONG );

	set("objects", ([
		"/adm/npc/wizard" : 1,
		"/clone/misc/msgd" : 1,
	]));
	set("exits", ([
//		"up": __DIR__"wizard_room",
		"southeast": "/d/city/wumiao"
	]));

	set("no_study", "1");
	set("no_learn", "1");
	set("no_dazuo", "1");
	set("no_fight", 1);

	create_door("southeast", "竹门", "northwest", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "up" && ! wizardp(me))
		return notify_fail("那里只有巫师才能进去。\n");
	return ::valid_leave(me, dir);
}
