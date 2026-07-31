#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"东长安街"NOR);
	set("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路通向东方。
北边是驿站，管理着各处的信件，时不时有飞马奔出。南边的铺子
是振远镖局开的，专卖一些兵器。西面就是城市的中央广场了
LONG
	);

	set("exits", ([
 "west" :__DIR__"tamgch",
 "east" :__DIR__"dchjie2",
 "south" :__DIR__"bqpu",
 "north" :__DIR__"postoffice",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

