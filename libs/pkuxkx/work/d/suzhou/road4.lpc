#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道南边是个大湖。东面就是苏州城了。
西北方通向寒山寺。
LONG );


	set("exits", ([
		"northwest" : __DIR__"hanshansi",
		"east" : __DIR__"road3",
		"south" : "/d/murong/hubian1",
        "west" : __DIR__"hubian1",
	]));
	set("objects",([
		"/d/murong/npc/guo" : 1,
		"/d/murong/npc/cui" : 1,
		]));

	set("outdoors", "suzhou");
	setup();

}

