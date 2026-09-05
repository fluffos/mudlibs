// xiaowu.c 小屋
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这是后山的一座小院，布置简简单单，除了一床、一桌、
一椅、一蒲团，再也没有别的什物。比较引人注目的是墙上挂
着一把剑。这里就是武当开山祖师张三丰的练功所在。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaoyuan",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhang" : 1 ]));
	create_door("south", "竹门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

