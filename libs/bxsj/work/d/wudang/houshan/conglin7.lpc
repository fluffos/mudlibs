// Room : /d/wudang/conglin7.c 丛林
// By lius 99/8

#include <ansi.h>
#include "conglin.h"
inherit ROOM;

void create()
{
	set("short",YEL"落叶丛林"NOR);
	set("long", @LONG
这是一片落叶丛林，风吹叶落，你走在这又厚又软的落叶上，不会留下一
丝足迹，很快的你就发现迷失了自己的方向。
LONG                           
        );

	set("exits", ([               
		"east" : __DIR__"conglin"+(random(12)+1),
		"west" : __DIR__"conglin"+(random(12)+1),
		"south" : __DIR__"conglin"+(random(12)+1),
		"north" : __DIR__"conglin"+(random(12)+1),
		"northeast" : __DIR__"conglin6",
		"northwest" : __DIR__"conglin"+(random(12)+1),
		"southeast" : __DIR__"conglin"+(random(12)+1),
		"southwest" : __DIR__"conglin8",
	]));
	set("outdoors", "武当");

	set("objects", ([
		__DIR__"../npc/yezhu" : 1, 
		__DIR__"../npc/snake" : 1,
	]));
	set("caiyao_room", 1);

	setup();
}

void reset()
{
	::reset();
	set("caiyao_room", 1);
}

void init()
{
	add_action("do_zhao", ({"zhao","find"}));
}
