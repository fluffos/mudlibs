// By River@SJ

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "武威");
	set("long", @LONG
武威是西夏国的西南重镇，驻有重兵，城楼高达三丈，门口有两排官兵正
在认真的盘查过往行人，城门口的告示上画着最近通缉的江洋大盗的图形，城
里头看上去还挺热闹。东南就是去永登的方向了，西南面就是祁连山脉。
LONG );
	set("exits", ([
		"southeast" : __DIR__"wuqiao",
		"east"     : __DIR__"tumenzi",
		"northwest" : "/d/xingxiu/road4",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 3,
	]));

	set("outdoors", "兰州");
	setup();
}
