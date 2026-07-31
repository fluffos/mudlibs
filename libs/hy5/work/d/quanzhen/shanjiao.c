// shanjiao.c 终南山脚
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "终南山脚");
        set("long", @LONG
这里是终南山的山脚，终南山号称西北的第一山，以山势奇峻，
环境清幽著称。这里的山势还很平缓，一道石阶蜿蜒通往山上。面前
是一座高山，如同擎天一柱般插向天空，所以古人的诗句中有‘终南
一柱’的说法。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
//                "northup" : __DIR__"shijie1",
 "eastdown"   : "/d/zhongyuan/shouyang_shan",
                "north"    : "/d/gumu/shanlu13",
                "westdown" : __DIR__"shanlu4",
        ]));
        set("objects",([
  "/clone/misc/dache" : 1 ,
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
