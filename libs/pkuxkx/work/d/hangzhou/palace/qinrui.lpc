// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", "庆瑞殿");
	set("long", @LONG
这里是庆瑞殿，官家一家人饮宴的地方。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"south" : __DIR__"yudaoh2",
		"east" : __DIR__"neidong",
		"north" : __DIR__"yudao1",
		"west" : __DIR__"hetong",
		"enter" : __DIR__"qinrui2",
	]));
	set("objects", ([
		"/d/song/npc/runei_duzhi" : 1,
    "/d/song/npc/dianqian_npc3" : 1,
        ])); 
	setup();
}