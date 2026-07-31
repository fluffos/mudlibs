#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"石洞出口"NOR);
	set("long", @LONG
这是一个黑漆漆石洞，周围都是坚硬的石壁,前面有条往上的阶梯。
LONG CYN);
	set("exits", ([
		"east" : __DIR__"dong1",
		"west" : __DIR__"dong22",
                "up" : "/d/migong/lev1/dong100",
                	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
