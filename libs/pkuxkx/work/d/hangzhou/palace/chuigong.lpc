// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", HIW"垂拱殿"NOR);
	set("long", @LONG
这里是垂拱殿，也是官家和外臣议事的正殿。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"southeast" : __DIR__"daqing",
		"east" : __DIR__"yanhe",
		//"southwest" : __DIR__"shuichi",
		//"north" : __DIR__"yudao1",
		"enter" : __DIR__"chuigong2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/song/npc/dianqian_npc3" : 1,
        ])); 
	set("WAICHAO",1);
	set("ZHUDI",1);
	setup();
}