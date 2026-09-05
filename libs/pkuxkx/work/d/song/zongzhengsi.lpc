// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "玉牒所宗正寺");
	set("long", @LONG
这里是宗正寺，负责管理宗室事宜。
LONG
	);
    //set("outdoors", "hangzhou");

	set("exits", ([
		"north" : __DIR__"taimiao",
		//"up" : __DIR__"fenghuang2",
		//"westup" : __DIR__"ruishi",
		"south" : "/d/hangzhou/wall1",
	]));
	set("objects", ([
    __DIR__"npc/zzs_npc1" : 1,
	__DIR__"npc/zzs_npc2" : 1,
	__DIR__"npc/zzs_npc3" : 1,
        ]));  
	set("at_hangzhou",1);
	setup();
}