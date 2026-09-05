// Room: /d/xingxiu/shamo10.c
// Modified by iszt@pkuxkx, 2007-03-31

inherit ROOM;

#include "shamo.h"

void create()
{
	set("short","大沙漠");
	set("long", @LONG
这是一片一望无际的大沙漠。你一进来就迷失了方向。看来要走出这块沙漠
并非易事。
LONG);
	set("outdoors", "xingxiuhai");
	set("exits", ([
		"east" : __DIR__"shamo9",
		"west" : "/d/baituo/gebi",
		"south" : __DIR__"shamo9",
		"north" : __FILE__,
	]));
	setup();
}