#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"玄武大街"NOR);
	set("long", @LONG
这里是玄武大街的中段，西面是玄武大街和青龙大街的十字路口。
东面再过两条街就到了北大街。
LONG
	);

	set("exits", ([
 "west"  :__DIR__"xw3",
 "east"  :__DIR__"xw1",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

