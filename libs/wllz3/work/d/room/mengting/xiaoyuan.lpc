// rouw_room 梦庭院
// Design By Sbird add from 2001.2.21

#include <room.h>

/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short","前院");
	set("long",@LONG
这是一所十分别致的院子，院中种满了各式各样的名贵花草，争先斗
艳，十分美丽。院子旁边有一口井，井水清澈见底，十分凉爽。院子虽然
不是很大，但打扫的十分干净。
LONG
);
	set("item_desc", ([
/**/		"paizi"   : "梦庭院 - 鲁班\n",
//**		"paizi"   : "ROOM_NAME - ROOM_OWNER\n",
	]));

/**/	set("default_long", "这是一所十分别致的院子，院中种满了各式各样的名贵花草，争先斗艳，十分美丽。院子旁边有一口井，井水清澈见底，十分凉爽。院子虽然不是很大，但打扫的十分干净。");
	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");
	set("exits", ([
		"out" : "/d/room/xiaoyuan",
		"north" : __DIR__"room1",
	]));
	set("playerhouse",1);
	set("resource/water", 1);
	set("outdoors","playerroom");
//**	set("valid_startroom", 1);
	create_door("north", "木门", "south", DOOR_CLOSED);
	setup();
}
