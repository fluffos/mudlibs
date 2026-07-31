
// Room: /city/ximen.c
// YZC 1995/12/04

#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", WHT "西门" NOR);
        set("long", @LONG
        这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城门正上
方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通缉告示(gaoshi)。
这里是罪犯逃往西域的必经之地，官兵们戒备森严，动不动就截住行人盘问。一条
笔直的青石板大道向东西两边延伸。西边是郊外，骑马的、座轿的、走路的，行人
匆匆。东边是城里。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
        "east" : __DIR__"xidajie1",
        ]));
        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));
        setup();
}
