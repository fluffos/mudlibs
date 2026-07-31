// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "雪坑小洞");
	set("long", @LONG
这里是大雪山雪坑下的一个密洞。里面破破烂烂的，丢满各种杂物，
还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"  : "d/xuedao/hollow",
		"northeast" : __DIR__"xsandao2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

