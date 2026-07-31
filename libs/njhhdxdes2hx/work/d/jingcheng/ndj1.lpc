#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIM"南大街"NOR);
	set("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路通向南方。
东边是城中最大的一家旅店，豪华气派。西边有一家当铺，进进
出出的人们有喜有忧。
LONG
	);

	set("exits", ([
 "north" :__DIR__"tamgch",
 "west"  :__DIR__"djdp",
 "south" :__DIR__"ndj2",
 "east"  :__DIR__"nchkzh",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

