
// tea_corridor.c

#include <room.h>

inherit ROOM;

void create()
{
	set("coor",({1890,3900,0}));
	set("short", "场院前厅");
	set("long",
"这里是这座场院的前厅，简单的陈设中透出一股尊贵不凡的气派。一张黑漆镶金的八仙桌摆\n"
"放在大厅中央，两只黝黑的太师椅座在这张桌子的两旁。\n"
);

        set("exits", ([
                "east"          : __DIR__"god1",
	]) );

	set("objects", ([
//    __DIR__"npc/god" : 1,
    ]) );

        setup();

}


