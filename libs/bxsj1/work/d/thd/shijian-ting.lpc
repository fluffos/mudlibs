// ROOM : shijian-ting.c
// Created by Numa 1990830

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIW"试剑亭"NOR);
        set("long",@LONG
这是一座精巧的亭子，上方挂着一个匾牌(bian)。亭中央有一块巨
石，上面满是剑痕。石上刻着三个大字，但被剑痕划的已经看不清
楚了。亭子的北边有一间客房。
LONG
        );
        set("exits",([
                "east" : __DIR__"caodi",
                "north" : __DIR__"kefang1",
                ]));
        set("no_clean_up",0);
        set("item_desc",([
                "bian" : "

                试      剑      亭
                \n
",
        ]));
        setup();
}
