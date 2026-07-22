// /area/jiangbei/wudang/gsdao6.c 古神道
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", YEL"古神道"NOR);
        set("long", @LONG
古神道其实就是通往武当山上的小道，相传远古时有神从次经过，形成人
可以走的道路从而得名。实际上古神道是在条峡谷之中，这里剑河水长年不断
地涓涓流淌，山上古树参天，峡谷中林荫浓密，是武当山一风景绝佳之处。
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"qtguan",
                "eastup" : __DIR__"hldong",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "武当");

        set("objects",([
                __DIR__"npc/jxk" : random(2)+1,
        ]));

        setup();
}
