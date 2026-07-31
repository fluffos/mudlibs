#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"青龙大街"NOR);
	set("long", @LONG               
这里是青龙大街的中段，往北走几步就是青龙大街和玄武
大街的十字路口。西边是城里头一家有名的包子铺，进进
出出人流不断。
LONG
	);

	set("exits", ([
 "north"  :__DIR__"xw3",
 "south"  :__DIR__"ql3",
 "west"   :__DIR__"jjbz",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

