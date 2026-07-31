// Room: shanlu3.c
// By River@SJ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"翠谷"NOR);
        set("long", @LONG
你面前是个花团锦簇的翠谷，红花绿树，交相掩映。脚下踏着的是柔软细
草，鼻中闻到的是清幽花香，鸣禽间关，鲜果悬枝，不由的心旷神怡。
LONG    );
        set("exits", ([
                "north" : __DIR__"shanlu6",
                "south" : __DIR__"cuigu",
        ]));
        set("objects",([
		__DIR__"npc/shanyang" : 1,
        ]));

        set("outdoors", "昆仑翠谷");
        set("no_clean_up", 0);

        setup();
}
