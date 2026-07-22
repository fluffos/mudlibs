// Room : /d/wudang/conglin14.c 丛林
// By lius 99/8

#include <ansi.h>
#include "conglin.h"
inherit ROOM;

void create()
{
	set("short",HIG"阔叶丛林"NOR);
	set("long", @LONG
你突觉眼前一亮，走进了一片翠绿生生的丛林，虽说林深叶阔，日照不
多，却已能听到欢快的雀鸣，和远处山泉的叮咚声，你精神为之一振。
LONG                           
        );

	set("exits", ([               
		"east" : __DIR__"conglin"+(random(8)+9),
		"west" : __DIR__"conglin"+(random(8)+9),
		"south" : __DIR__"conglin"+(random(8)+9),
		"north" : __DIR__"conglin"+(random(8)+9),
		"northeast" : __DIR__"conglin"+(random(8)+9),
		"northwest" : __DIR__"conglin"+(random(8)+9),
		"southeast" : __DIR__"conglin15",
		"southwest" : __DIR__"conglin13",
	]));

	set("outdoors", "武当");

	set("objects", ([
		__DIR__"../npc/bird" : 1, 
		__DIR__"../npc/monkey" : 1,
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
