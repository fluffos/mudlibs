#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"白虎大街"NOR);
	set("long", @LONG
  这里是白虎大街的中段。往北走几步是白虎大街和东长
安街的十字路口。往东是一家肉铺。
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"baih5",
 "north" :__DIR__"dchjie3",
 "east" :__DIR__"roupu",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

