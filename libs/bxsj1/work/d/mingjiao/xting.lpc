// xting.c 小厅
// Modify By River@SJ 99.06

#include <ansi.h>
inherit ROOM;

void create()
{
       set("short", "小厅");
       set("long", @LONG
这是聚义厅前的一个小厅，北面的院子是聚义厅，南边是练武场，东西两
边分别通向厨房和休息室。
LONG);
	set("exits", ([
		"east" : __DIR__"sleeproom",
		"north" : __DIR__"jyt",
		"west" : __DIR__"eatroom",
		"south" : __DIR__"wu1",
	]));
	set("objects",([
		__DIR__"npc/f-dizi" : 1,
		__DIR__"npc/m-dizi" : 1,
		CLASS_D("mingjiao") + "/zhou" : 1,
        ]));
	setup();
}
