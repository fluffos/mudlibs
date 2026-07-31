#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"十字路口"NOR);
	set("long", @LONG
这里是西长安街和青龙大街的十字路口。一直向西走可以到京城的
西门。西南方向有一座规模不小的寺院，而东南方向就是当朝丞相
殷开山的府第了。
LONG
	);

	set("exits", ([
 "west" :__DIR__"xchjie2",
 "east" :__DIR__"xchjie4",
 "north":__DIR__"ql3",
 "south":__DIR__"ql4",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

