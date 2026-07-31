#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"十字路口"NOR);
	set("long", @LONG
你来到了青龙大街和朱雀大街的十字路口。东南方向有一座京城
最大的道观－清虚观。西边有一家杂货铺，人来人往，还挺热闹。
向南远远的就可看到城墙了。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq4",
 "east" :__DIR__"zhq2",
 "north":__DIR__"ql5",
 "south":__DIR__"ql6",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

