//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "戏台");
	set("long", @LONG
这里是戏台，虽然有些小，但是很干净。一个戏子正在表演。你一踏
上戏台，情不自禁地就唱起歌来。
LONG
);
	set("exits", ([
		"down" : __DIR__"xiyuan",
		"southdown":__DIR__"houtai",
	]));
	set("objects", ([
		"/d/city2/npc/xizi": 1,
	]));

	setup();
}
