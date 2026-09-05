// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", HIC"端诚殿"NOR);
	set("long", @LONG
这里是端诚殿，作为明堂郊祀时称“端诚”。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"southwest" : __DIR__"daqing",
		//"south" : __DIR__"yudao2",
		"west" : __DIR__"yanhe",
		//"north" : __DIR__"yudao1",
		"enter" : __DIR__"duancheng2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/song/npc/dianqian_npc3" : 1,
        ])); 
	set("WAICHAO",1);
	set("ZHUDI",1);
	setup();
}