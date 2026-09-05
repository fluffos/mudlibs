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
这里是一段白石铺就的御道，北面是举行朝会的宫殿。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"yudaoe1",
		"south" : "/d/hangzhou/lizhengmen",
		"west" : __DIR__"jiashan",
		"north" : __DIR__"daqing",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/hangzhou/npc/songbing_y" : 2,
        ])); 
	set("song_palace","north");
	set("WAICHAO",1);
	set("ZHUDI",1);
	setup();
}