#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	 set("short","后院门");
	 set("long",@long
往东走就是昆仑派弟子的休息处所和吃东西的地方了，这里是连接后院的
大门，不断看见各种打扮的江湖人士走过，看过廊外，是一片青色的树林，幽
静雅致，只听见不断传来的鸟鸣声。
long);
	 set("exits",([
            "west" : __DIR__"lang",
            "east" : __DIR__"shilu2",
         ]));

         set("outdoors", "昆仑");
         setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query("family/family_name") != "昆仑派")
		return notify_fail("那里是昆仑派的后院，恕不接待外客。\n");
	return ::valid_leave(me, dir);
}
