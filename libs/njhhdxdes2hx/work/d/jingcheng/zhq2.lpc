#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"朱雀大街"NOR);
	set("long", @LONG
这里是朱雀大街的中段。路南是京城最大的一所道观－－“清虚
观”。西面是朱雀大街和青龙大街的十字路口。东面是京城的热
闹去处，外地来的人多会于那里。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq3",
 "east" :__DIR__"zhq1",
 "south" :__DIR__"qxguan",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

