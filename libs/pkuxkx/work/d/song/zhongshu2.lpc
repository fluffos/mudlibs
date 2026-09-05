// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "baoxiao.h"
void create()
{
	set("short", "中书省官厅");
	set("long", @LONG
这里中书省的官厅，几个中书舍人正在起草文书，东西两面分别是两间耳房。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"south" : __DIR__"zhongshucourt",
		"north" : __DIR__"zhongshu3",
		"west" : __DIR__"zhongshu4",//吏部
		"east" : __DIR__"zhongshu5",//礼部
	]));
	set("yamen_id","中书省");
	setup();
}