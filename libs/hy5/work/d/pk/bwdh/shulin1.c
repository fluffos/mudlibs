//shulin.c 树林

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIG"树林"NOR);
        set("long", @LONG
这是一片树林。几十丈高的大树簇在一块，密实的枝叶象一蓬蓬巨伞般伸
向天空，把阳光遮得丝毫也无。你走在树林中，将脚下的树叶踩的沙沙响。
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([
        "northeast" : __DIR__"caodi5",
        "north" : __DIR__"shulin2",

        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "试剑山庄");

        setup();
}

