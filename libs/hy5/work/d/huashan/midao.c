// Room: /d/huashan/modao.c
// Date: Look 99/03/25

#include <room.h>

inherit ROOM;

void create()
{
	set("short","密道");
	set("long", @LONG
这里是山洞入口处的一条密道。山洞里面漆黑一团，你根本分不清东南西
北，只好胡乱瞎闯了。
LONG
	);
	set("exits", ([
		"left" : __DIR__"rukou",
		"south" : __DIR__"midong",
	]));             
       set("objects", ([
         __DIR__"npc/feng_bp" : 1,
         __DIR__"npc/cheng_by":1,
         __DIR__"npc/cong_bq":1,
       ]));
	set("indoors", "华山" );

        setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    if((objectp(present("feng buping", environment(me))) ||
        objectp(present("cheng buyou", environment(me))) ||
        objectp(present("cong buqi", environment(me)))))
    return notify_fail("剑宗弟子大声高呼：你偷窥我剑宗禁地，不留下性命休想离开！\n");
}                              
