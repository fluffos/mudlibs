// Room: d/gb/xinglin9.c
// by pishou
// Modify by Looklove@SJ for update npc

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"杏子林"NOR);
	set("long", @LONG
这儿是杏子林中间的一片空地，四周的杏树上开满了花。一群蜜蜂飞来飞
去繁忙地采蜜。树下有几个乞丐围坐在一起，旁边站着两个年轻乞丐。他们脸
色凝重，好像在商议着什么。
LONG
	);
	set("outdoors", "苏州");

	set("exits", ([
		"south" : __DIR__"xinglin8",
		"west" : __DIR__"kongdi2",
		"north" : __DIR__"pomiao",
	]));

	set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
		CLASS_D("gaibang/liang") : 1,
        ]));

	setup();
}