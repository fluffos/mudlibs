#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"青龙大街"NOR);
	set("long", @LONG               
这里是青龙大街的中段。东面有一扇小门通向殷开山丞相的府第。
当然门是从里面闩上了，只是紧急时的出口。北面是青龙大街和
西长安街的十字路口。
LONG
	);

	set("exits", ([
 "south"  :__DIR__"ql5",
 "north"  :__DIR__"xchjie3",
 "west"   :__DIR__"westyf",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

