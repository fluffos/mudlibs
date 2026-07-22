// /d/xingxiu/shanjiao.c
// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "天山脚下");
	set("long", @LONG
这里是天山脚下，西北方是高耸入云的天山，抬头仰望可以看到山顶上的
万年积雪。一道天山将西域分为两半，北疆是西域各族的聚居区，南疆是广阔
无边的大草原。从这里往西便是伊犁城，因为这是交通要津，时常有星宿派弟
子把关抢劫。
LONG);
	set("outdoors", "星宿");
	set("exits", ([
		"north" : __DIR__"xxh",
		"east" : __DIR__"yili/yili",
		"southeast" : __DIR__"silk9",
		"southwest" : "/d/hj/senlin1",
	]));
	set("objects", ([
		__DIR__"npc/xxdizi3" : 1,
		__DIR__"npc/boshou"  : 1,
	]));
	setup();
}

#include "/d/xingxiu/job2.h";
