#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞入口"NOR);
	set("long", BLU @LONG
 你越走越深，周围的墙壁似乎有些松软了,左面有条往下的小路。 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong99",
		"south" : __DIR__"dong10",
                "east" : __DIR__"shop",
                "west" : __DIR__"dong101",
                "down" : "/d/migong/lev5/dong21"
                	]));
         set("objects", ([
              "/clone/box/gbox" : 1,
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
