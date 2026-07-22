//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "景泰");
	set("long", @LONG
景泰是西夏国的重镇，驻有重兵，城楼高达三丈，门口有两排官兵正在认
真的盘查过往行人，城门口的告示上画着最近通缉的江洋大盗的图形，城里头
看上去还挺热闹。东南方向过了黄河就是崆峒山了。
LONG );

	set("exits", ([
		"northwest" : __DIR__"hongsx",
		"southeast" : __DIR__"huanghe_2",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 1,
	]));

	set("outdoors", "西夏");
	setup();
}
