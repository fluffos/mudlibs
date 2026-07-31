// /d/wudang/gudao2.c  古道

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"古道"NOR);
        set("long", @LONG
你沿着古道往上爬，灌木丛生，乔木遮云，正是野兽的理想天堂，不想成
为老虎的晚餐的话还是赶快离开的好。
LONG                           
        );
        set("exits", ([
                "southup" : __DIR__"husunchou",
                "northdown":__DIR__"gudao3",
                "westdown":__DIR__"gudao1",
        ]));

        set("objects",([
                __DIR__"npc/laohu" : 1,

        ]));
        setup();
        replace_program(ROOM);

}

