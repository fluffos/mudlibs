//shanlu.c
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG 
道路到了这里已经变得崎岖不平，两旁的山崖把阳光
大部分都遮住了，偶尔有阴风阵阵，让你不寒而栗。这里
百草丛生，情景很是荒凉。
LONG
	);

	set("exits", ([
		"northup" : __DIR__"rukou",
		"southdown"	: __DIR__"road3",
	]));
	set("outdoors", "riyuejiao");
	setup();

}

