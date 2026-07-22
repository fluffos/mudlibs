// shanjiao.c 终南山脚
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "终南山脚");
        set("long", @LONG
这里是终南山的山脚，终南山号称西北的第一山，以山势奇峻，环
境清幽著称。这里的山势还很平缓，一道石阶蜿蜒通往山上。面前是一
座高山，如同擎天一柱般插向天空，所以古人的诗句中有“终南一柱”
的说法。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"xiaolu1",
                "westdown" : __DIR__"shanlu4",
        ]));
//        set("objects",([
//                __DIR__"npc/youke" : 1,
//                __DIR__"npc/xiangke" : 2,
//        ]));

        setup();
        replace_program(ROOM);
}


