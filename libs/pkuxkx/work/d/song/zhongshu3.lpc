// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "水池");
	set("long", @LONG
这里是一方水池，里面养着一些鲤鱼。
LONG
	);
    set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"south" : __DIR__"zhongshucourt",
		//"north" : __DIR__"zhongshu3",
		//"west" : __DIR__"zhongshu2",//吏部
		"south" : __DIR__"zhongshu2",//礼部
	]));
	set("objects", ([
          __DIR__"npc/zhongshu_npc1" : 1,
		  __DIR__"npc/zhongshu_npc2" : 1,
        ]));
	setup();
}