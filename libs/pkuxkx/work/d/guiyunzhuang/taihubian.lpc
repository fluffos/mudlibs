//taihubian.c 太湖边
//Made By:pingpang
//modified by Zine 2012
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"大石桥"NOR);
    set("long", @LONG
这里是一座大石桥，前面楼阁纡连，竟是好大一座庄院。
LONG);
        set("exits", ([
//+
//+
 /* sizeof() == 4*/
        "east" : __DIR__"gate",
    "west" : __DIR__"bridge2",
        ]));
        set("objects",([__DIR__"npc/youke":2,]));
        set("outdoors","guiyunzhuang");
        setup();
        replace_program(ROOM);
}

