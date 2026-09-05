// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", HIR"延和殿"NOR);
	set("long", @LONG
这里是延和殿，皇家举行宴会的地方。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"west" : __DIR__"chuigong",
		"east" : __DIR__"duancheng",
		"south" : __DIR__"yudao3",
		//"northwest" : __DIR__"zhulin",
		"north" : __DIR__"yudao2",
		"enter" : __DIR__"yanhe2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/song/npc/dianqian_npc3" : 1,
        ])); 
	set("WAICHAO",1);
	set("ZHUDI",1);
	setup();
}