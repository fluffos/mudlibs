// 楚州杂货铺 /d/city/chuzhou/zahuopu.c
// by lala, 1997-12-10

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short",YEL"杂货铺"NOR);
    set("long",@LONG
一间普普通通的杂货铺，出售居民日常所需的各种杂货物品，大不过锄头铁
锹，小则到针头线脑。由于地处的位置不是很好所以生意也很一般，见不到什么
顾客进来买东西。铺子的老板也看起来普普通通，但是让人总是觉得似乎有些什
么东西显得很别扭，不大对头。
LONG);
    set("exits",([
        "north" : __DIR__"dongshi",
    ]));
    set("objects",([
        __DIR__"npc/shopboss"   :   1,
    ]));        
    set("no_kill", "yangzhou");
    setup();
}
