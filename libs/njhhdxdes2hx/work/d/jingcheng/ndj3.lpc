#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIM"十字路口"NOR);
	set("long", @LONG
这里是南大街和朱雀大街的交叉路口。向北是城中心，远远的可
以望到钟楼。向南可以到京城的南门。往西走可以到青龙大街，
向东走则可以到白虎大街。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq1",
 "east" :__DIR__"zhq5",
 "north" :__DIR__"ndj2",
 "south" :__DIR__"ydmen",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

