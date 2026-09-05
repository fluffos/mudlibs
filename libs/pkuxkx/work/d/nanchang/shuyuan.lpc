#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"书院正门"NOR);
	set("long", @LONG
这里是岳麓书院的正门，曲径幽深，是个做学问的所在。
LONG );
	set("outdoors", "nanchang");
	set("no_clean_up", 0);
	set("exits", ([
		"enter" : __DIR__"shuyuan2",
        "southdown" : __DIR__"guandaow3",
	]));
	setup();
	
}

