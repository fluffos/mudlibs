#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"玄武大街"NOR);
	set("long", @LONG
这里是玄武大街的中段。北面是一座大房子，门匾上有四个大字
“京都武馆”。南面的一所宅院是当朝将军的宅第。往东走几步
就是玄武大街和白虎大街的十字路口。
LONG
	);

	set("exits", ([
 "east"  :__DIR__"xw7",
 "west"  :__DIR__"xw5",
 "south" :__DIR__"jiangjun",
 "north" :__DIR__"jdwg",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

