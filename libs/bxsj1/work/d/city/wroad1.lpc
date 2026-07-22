// /d/city/wroad1.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "西郊");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时有人骑着马匆匆而过。
大道往西进入安徽境内。东边通向扬州城。
LONG
	);
        set("outdoors", "扬州");

	set("exits", ([
		"east" : __DIR__"ximen",
                "west" : __DIR__"wroad2",
                "northwest" : __DIR__"winmo",
	]));
   	setup();
}
