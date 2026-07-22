// Room: donglang2.c  东厢走廊
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "西厢走廊");
        set("long", @LONG
你走在一条木制结构的走廊上，南面是一间大屋，门口挂有一标记，门牌
(pai)是白的。再往西是一座楼阁。
LONG
    );
        set("exits", ([
            "east" : __DIR__"xiaolu1",
            "south":__DIR__"xiuxishi2",
            "west" : __DIR__"jingge",
        ]));
                                                    
        set("item_desc",([
           "pai" : HIW"\t\t\t坤\n"NOR,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if ((me->query("gender") =="男性") && dir =="south" )
           return notify_fail("想学宋青书去偷窥别人的闺房么？！\n");
        return ::valid_leave(me, dir);
}
