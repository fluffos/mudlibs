// Room : /d/wudang/conglin10.c 丛林
// By lius 99/8

#include <ansi.h>
#include "conglin.h"
inherit ROOM;

void create()
{
        set("short",HIW"积雪丛林"NOR);
        set("long", @LONG
海拔越走越高，气候越转寒冷，路上、树上都布满厚厚的积雪，行进越来
越艰难，加之野兽的袭击，你只盼能早日离开这片丛林。
LONG                           
        );

	set("exits", ([               
		"east" : __DIR__"conglin"+(random(12)+5),
		"west" : __DIR__"conglin"+(random(4)+5),
		"south" : __DIR__"conglin"+(random(12)+5),
		"north" : __DIR__"conglin9",
		"northeast" : __DIR__"conglin11",
		"northwest" : __DIR__"conglin"+(random(12)+5),
		"southeast" : __DIR__"conglin"+(random(12)+5),
		"southwest" : __DIR__"conglin"+(random(4)+5),
	]));

	set("outdoors", "武当");

	set("objects", ([
		__DIR__"../npc/xiong" : 1, 
		__DIR__"../npc/bao" : 1,
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

int valid_leave(object me, string dir)
{
	me->add_busy(2);
	me->add("jingli",-30);
	return ::valid_leave(me,dir);
}
