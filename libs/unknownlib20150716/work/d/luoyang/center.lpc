//changan city
#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "洛阳广场");
        set ("long", @LONG
这里便是洛阳城的中心，四条大街交汇于此。一座巍峨高大的钟
楼耸立于前，很是有些气势。每到清晨，响亮的钟声便会伴着淡淡雾
气传向洛阳城的大街小巷。路口车水马龙，来往人潮不断。
LONG);


        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"qianyuan1",
                "north" : __DIR__"chengyun1",
                "west" : __DIR__"dingde1",
                "east" : __DIR__"congming1",
        ]));
        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
//		"/d/qujing/wuzhuang/npc/zhangguolao": 1,
        ]));

        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
 replace_program(ROOM);
}

