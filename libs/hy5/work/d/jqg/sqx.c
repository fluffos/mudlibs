// Room: /u/dubei/u/gumu/jqg/sqx
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "三清轩");
	set("long", @LONG
这里是绝情谷谷主会客的地方，轩内墙壁上挂了许多书法
图画，门窗皆浮雕纹饰，四周是回廊。
LONG
	);

	set("exits", ([
                "north" : __DIR__"sf",
                "eastdown" : __DIR__"st",
                "south" : __DIR__"jt",
                "southwest": __DIR__"zl1",
	]));
	set("objects", ([
		__DIR__"npc/gsz" : 1,
	 ]));

       setup();
 
}
int valid_leave(object me, string dir)
{
          if (!me->query("jqg_pass")&&
          present("gongsun zhi", environment(me)) &&
	  (dir =="south" || dir =="north" || dir=="southeast"))
          return notify_fail("公孙止怒斥到，你以为你是小龙女啊，在我绝情谷里乱跑？！\n");
          return ::valid_leave(me, dir);
}
