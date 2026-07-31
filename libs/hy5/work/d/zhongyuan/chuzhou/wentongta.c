// 楚州文通塔 /d/city/chuzhou/wentongta.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"文通塔"NOR);
    set("long", @LONG
文通塔位于城西北的勺湖之滨，与城东南的龙光阁遥相对峙“以壮文峰”，
故得名文通塔。全塔高达十三层，据说登上塔可以看到整个楚州北半个城和一直
到渡口的大路的全部风光，真是个凭高远眺的好地方。
LONG
    );
    set( "no_kill",  "yangzhou" );
    set("exits", ([
        "southeast" : __DIR__"tianbao_lu",
        "up"        : __DIR__"wentongta2",
    ]));
    set("objects", ([
        __DIR__"npc/youke"  :   3,
    ]));
    setup();
}

int valid_leave( object me, string dir )
{
    if( me->query("no_leave_chuzhou")
    && dir == "up" )
        return notify_fail("你现在不能离开楚州。\n");
    return ::valid_leave( me, dir );
}
