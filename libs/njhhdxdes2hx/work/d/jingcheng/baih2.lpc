#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"白虎大街"NOR);
	set("long", @LONG
  这里是青龙大街的中段。路东有一个庙,西面是将军府。往北走几步
是白虎大街和玄武大街的丁字路口。
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"xw7",
 "south" :__DIR__"baih1", 
 "east" :__DIR__"miao",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

