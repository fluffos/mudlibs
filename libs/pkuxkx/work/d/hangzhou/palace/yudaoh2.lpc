// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", WHT"御道"NOR);
	set("long", @LONG
这里是一段白石铺就的御道，南面通往宫后苑，南面是坤宁宫。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"zhulin",
		"south" : __DIR__"kunning",
		"west" : __DIR__"huapu",
		"north" : __DIR__"qinrui",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/hangzhou/npc/songbing_y" : 1,
        ])); 
	setup();
}