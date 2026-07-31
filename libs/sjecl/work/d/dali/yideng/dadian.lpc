// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "禅院大殿");
	set("long", @LONG
只见大殿上佛前供着一盏油灯，映照着佛像宝相庄严，殿内烟火缭绕，几
个小沙弥正参宗颂佛，大殿东西各有一个厢房，看来是供休息之用，倒是大佛
侧面的门口被红布帘遮挡着，不能看见其通往何处。
LONG
	);
	set("exits", ([
		"south" : __DIR__"shiqiao",
		"north" : __DIR__"houyuan",
		"east" : __DIR__"dfang",
		"west" : __DIR__"xfang",
	]));
	set("objects", ([
		__DIR__"npc/shami" : 1+random(2),
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") != "男性" && dir == "east" && !me->query("no_quest")) 
		return notify_fail("那里是供男施主休息的厢房。\n");
	if ( me->query("gender") == "男性" && dir == "west" && !me->query("no_quest")) 
		return notify_fail("那里是供女施主休息的厢房。\n");
	return ::valid_leave(me, dir);
}
