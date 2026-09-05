// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", CYN"勤政殿"NOR);
	set("long", @LONG
这里是勤政殿，也是官家接待会见近臣的敌方。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"south" : __DIR__"yudao2",
		"north" : __DIR__"chongzheng",
		//"southwest" : __DIR__"shuichi",
		//"north" : __DIR__"yudao1",
		"enter" : __DIR__"qinzheng2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/song/npc/dianqian_npc3" : 1,
        ])); 
	set("WAICHAO",1);
	setup();
}