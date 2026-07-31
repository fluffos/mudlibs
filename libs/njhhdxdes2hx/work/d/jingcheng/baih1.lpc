#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"白虎大街"NOR);
	set("long", @LONG
  白虎大街的南部是长安城有名的娱乐场所集中的地方。路东
有一家通宵不歇的小酒馆。
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"baih2",
 "south" :__DIR__"dchjie3",
 "east" :__DIR__"jiuguan1",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

