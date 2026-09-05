// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", HIW"垂拱殿内"NOR);
	set("long", @LONG
这里是垂拱殿内，也是官家和外臣议事的正殿，两个小黄门在认真打扫着。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"east" : __DIR__"walla",
		//"south" : __DIR__"yudao2",
		//"west" : __DIR__"wall1",
		//"north" : __DIR__"yudao1",
		"out" : __DIR__"chuigong",
	]));
	set("objects", ([
	"/d/hangzhou/npc/ding" : 1,
    "/d/hangzhou/npc/huangmen_g" : 2,
        ])); 
	set("WAICHAO",1);
	set("ZHUDI",1);
	setup();
}