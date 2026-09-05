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
		"west" : __DIR__"menggubao2",
		"southeast" : __DIR__"kongdi",
		"south" : __DIR__"menggubao1",
		"southwest" : __DIR__"tuo_bao",
        "northwest" : __DIR__"menggubao0",
	]));
	set("sleep_room", "1");
	set("objects", ([
        	__DIR__"npc/muyangren" : random(2),
	]));
	set("no_robber",1);
	set("outdoors", "menggu_e");
    setup();
}
