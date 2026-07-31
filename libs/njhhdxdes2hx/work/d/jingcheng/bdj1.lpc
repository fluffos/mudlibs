#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"北大街"NOR);
	set("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路通向北方。
西边是城中有名的柳记布庄，专门经销各类服饰。东边是一座兵营，
门口一对石狮子怒目相向。
LONG
	);

	set("exits", ([
 "north" :__DIR__"bdj2",  
 "south" :__DIR__"tamgch",
 "west"  :__DIR__"ljbzh",
 "east"  :__DIR__"jwby",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

