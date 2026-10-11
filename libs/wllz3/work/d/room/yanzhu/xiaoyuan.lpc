// rouw_room 烟竹小筑
// Design By Sbird add from 2001.2.21

#include <room.h>

/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short","小院");
	set("long",@LONG
这是一所十分别致的小院。只见小院之中种满了各式各样的花草，十
分亮丽。蝴蝶，蜻蜓在花丛中不停的飞舞，一片生机勃勃的景象。
LONG
);
	set("item_desc", ([
/**/		"paizi"   : "彩虹居 - 鲁班\n",
//**		"paizi"   : "ROOM_NAME - ROOM_OWNER\n",
	]));

/**/	set("default_long", "这是一所十分别致的小院。只见小院之中种满了各式各样的花草，十分亮丽。蝴蝶，蜻蜓在花丛中不停的飞舞，一片生机勃勃的景象。");
	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");
	set("exits", ([
		"out" : "/d/room/xiaoyuan",
		"north" : __DIR__"room1",
	]));
	set("playerhouse",1);
	set("outdoors","playerroom");
//**	set("valid_startroom", 1);
	create_door("north", "木门", "south", DOOR_CLOSED);
	setup();
}
