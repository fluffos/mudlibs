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
这里是一段白石铺就的御道，南面是延和殿，北面通往内廷。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"east" : __DIR__"walla",
		"south" : __DIR__"yanhe",
		//"west" : __DIR__"wall1",
		"north" : __DIR__"qinzheng",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/hangzhou/npc/songbing_y" : 2,
        ])); 
	set("WAICHAO",1);
	setup();
}