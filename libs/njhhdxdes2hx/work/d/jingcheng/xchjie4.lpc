#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"西长安街"NOR);
	set("long", @LONG
你走在一条宽阔的石板大街上，东面就快到城中心了。西面是西门大
街和青龙大街的十字路口。南边有一座大府邸，一定是什么大官住的
地方。北面是长安城的总督衙门，飞檐挂角，显的极有气势。
LONG
	);

	set("exits", ([
 "west" :__DIR__"xchjie3",
 "east" :__DIR__"xchjie5",
 "north":__DIR__"chanf",
 "south":__DIR__"zgf",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

