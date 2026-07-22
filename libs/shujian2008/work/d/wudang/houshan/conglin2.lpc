// Room : /d/wudang/conglin2.c 丛林
// By lius 99/8

#include <ansi.h>
#include "conglin.h"
inherit ROOM;

void create()
{
	set("short",HIR"烈火丛林"NOR);
	set("long", @LONG
这里是一片红色的海洋，由于地处丛林的外围，独特的地理气候，使得这
里满山红枫，你惊叹自然之神奇，不知不觉的迷失了方向。
LONG                           
        );

	set("exits", ([               
		"east" : __DIR__"conglin"+(random(4)+1),
		"west" : __DIR__"conglin"+(random(8)+1),
		"south" : __DIR__"conglin"+(random(4)+1),
		"north" : __DIR__"conglin3",
		"northeast" : __DIR__"conglin"+(random(8)+1),
		"northwest" : __DIR__"conglin"+(random(8)+1),
		"southeast" : __DIR__"conglin1",
		"southwest" : __DIR__"conglin"+(random(4)+1),
	]));

	set("outdoors", "武当");

	set("objects", ([
		__DIR__"../npc/yetu" : 1, 
		__DIR__"../npc/shanji" : 1, 
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
