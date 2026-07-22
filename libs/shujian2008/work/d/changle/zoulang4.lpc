// Room: /d/changle/zoulang.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"走廊"NOR);
	set("long", @long
宽敞的走廊人来人往，再向内便是总舵的内宅了。空中弥漫着烟酒气味。
地上显得甚是肮脏。一些日常守卫的帮众警惕地注视着每个人。
long
	);

	set("exits", ([
		"south" : __DIR__"dating",
		"north" : __DIR__"xiaoting",
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"zoulang3",
	]));

	set("objects", ([
		__DIR__"npc/bangzhong" : 2,
	]));

	set("outdoors", "长乐帮");
	setup();
}
       