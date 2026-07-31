// Room: /u/dubei/u/gumu/jqg/zl2
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条典雅的回廊，上面画满当代名人的书画。
LONG
	);

	set("exits", ([
                "south" : __DIR__"xf",
                "northeast" : __DIR__"zl1",
                "north" : __DIR__"df",
	]));
	set("objects", ([
		__DIR__"npc/puren1" : 1,
	 ]));
 	setup();
	 
}
int valid_leave(object me, string dir)
{
          if (!me->query("jqg_pass")&&
          present("pu ren", environment(me)) &&
	  (dir=="north"))
          return notify_fail("仆人拦住你说道，丹房没经谷主同意，不能随便进入。\n");
          return ::valid_leave(me, dir);
}
