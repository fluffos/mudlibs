// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "蒙古包");
	set("long", @LONG
这是一顶蒙古包，牧人们的住家。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"menggubao6",
		"south" : __DIR__"menggubao2",
		"southwest" : __DIR__"menggubao4",
        "northwest" : __DIR__"dahanerduo_path2",
	]));
	set("sleep_room", "1");
	set("objects", ([
        	__DIR__"npc/muyangren" : random(3),
	]));
	set("no_robber",1);
	set("outdoors", "menggu_e");
    setup();
}
