// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "baoxiao.h"
void create()
{
	set("short", "台厅");
	set("long", @LONG
这里是御史台的台厅，厅内列竖宋代诸帝有关的诏书石碑，其中以神宗《诏
保举台官令》为首。
LONG
	);
       // set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"yushitai",
		"south" : __DIR__"yushitai4",
		"north" : __DIR__"yushitai2",//吏部
		//"east" : __DIR__"libu2",//礼部
	]));
	set("objects", ([
    __DIR__"npc/yushi1" : 1,
	__DIR__"npc/yushi2" : 1,
        ]));
	set("yamen_id","御史台");
	setup();
}