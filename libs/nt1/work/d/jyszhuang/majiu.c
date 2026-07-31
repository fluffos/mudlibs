// Room: /city/majiu.c
// Modified by Lonely Nitan@Mud

#include <ansi.h>
#include <room.h>
inherit TRANS_ROOM; 

void create()
{
        set("short", YEL"马厩"NOR);
        set("long",
"这是客栈边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人\n"
"只要住店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷\n"
"得干乾净净。一直伺候到客人离店上路。马厩中堆放著几堆草料，正中有\n"
"一口泔槽。墙上挂着一个牌子(paizi)！\n"
);

        set("objects", ([
                "/clone/npc/mafu" : 1,
		"/clone/horse/zaohongma" : 1,
		"/clone/horse/huangbiaoma" : 1,
		"/clone/horse/ziliuma" : 1,

        ]));

        set("exits", ([
		"south" : __DIR__"kedian",
        ]));



        set("outdoors", "city");
        set("no_fight",  1);
        set("no_beg", 1);
        set("no_clean_up", 0);
        set("resource/water", 1);

        setup();
}
