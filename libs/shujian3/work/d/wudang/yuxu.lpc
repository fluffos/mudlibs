// /area/jiangbei/wudang/yuxu.c 玉虚宫
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"玉虚宫"NOR);
        set("long", @LONG
武当山建造的规模宏大的皇家庙观，而玉虚宫则是整个建筑群中最大的庙
宇。玉虚宫是城内套城，共有三城，即外乐城，里乐城和紫金城。三城都各有
宫墙间隔连围，形成等级鲜明，规模宏大的宫城。后来，玉虚宫又得到了大规
模的扩建。放眼望去，飞金流碧，富丽辉煌，了无边际。
LONG
        );

        set("exits", ([
                "southup" : __DIR__"mozhen",
                "eastdown" : __DIR__"shanlu1",
        ]));

        set("objects",([
                __DIR__"npc/daotong" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "武当");

        setup();
}
