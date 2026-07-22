// Room: donglang2.c  东厢走廊

#include <ansi.h>


inherit ROOM;

void create()
{
    set("short", "东厢走廊");
    set("long", @LONG
你走在一条木制结构的走廊上，南面是一间大屋，门口挂有一标记，门牌
(pai)是蓝的，东边是武当派弟子平时用膳的场所。
LONG
    );
        set("exits", ([
            "east" : __DIR__"chufang",
            "south":__DIR__"xiuxishi1",
            "west" : __DIR__"xiaolu1",
        ]));

        set("item_desc",([
           "pai" : HIB"\t\t\t乾\n"NOR,
        ]));
        setup();
}


int valid_leave(object me, string dir)
{
        if ((me->query("gender") == "女性") && dir == "south") 
           return notify_fail("女子人家还是不要到那去的好，否则就不好找婆家了。\n");
        return ::valid_leave(me, dir);
}
