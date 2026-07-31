// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <room.h>
inherit ROOM;

void create()
{
	set("short","牢房");
	set("long", @LONG
四壁都是钢铁铸成,阴暗潮湿,一看就不是什么好地方.
这里是日月神教关押犯人的地方.
LONG
	);

	set("exits", ([
		"south" :__DIR__"laofang15",
		"north" :__DIR__"laofang14",
		"west"  :__DIR__"laofang10",
  	]));
	create_door("north", "铁门", "south", DOOR_CLOSED);
	create_door("south", "铁门", "north", DOOR_CLOSED);
	setup();
}

