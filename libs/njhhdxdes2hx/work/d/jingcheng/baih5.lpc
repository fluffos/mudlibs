#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"白虎大街"NOR);
	set("long", @LONG
  白虎大街的南部是长安城有名的娱乐场所集中的地方。路东
有一家通宵不歇的小酒馆，南面就是白虎大街和朱雀大街的十
字路口。
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"zhq7",
 "north" :__DIR__"baih4",
 "east" :__DIR__"jiuguan",  
 "west" :__DIR__"huadian",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

