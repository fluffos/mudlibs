#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"朱雀大街"NOR);
	set("long", @LONG
这里是朱雀大街的西段。往东走几步是朱雀大街和青龙大街的十
字路口。周围看不到几个行人。偶尔有几家院落，却也是残橼倒
壁，破烂不堪。听说是在这里要给几位将军盖府第，把老百姓都
赶走了。
LONG         
	);

	set("exits", ([ 
 "east" :__DIR__"zhq3",  
 "south" :__DIR__"mzh10",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

