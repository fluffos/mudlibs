// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", HIR"大庆殿"NOR);
	set("long", @LONG
这里是大庆殿，也是官家接待重臣使节的地方。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"northeast" : __DIR__"duancheng",
		"south" : __DIR__"yudao4",
		"northwest" : __DIR__"chuigong",
		"west" : __DIR__"shuichi",
		//"southeast" : __DIR__"huapu",
		"north" : __DIR__"yudao3",
		"enter" : __DIR__"daqing2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/song/npc/dianqian_npc3" : 1,
        ])); 
	set("WAICHAO",1);
	set("ZHUDI",1);
	setup();
}