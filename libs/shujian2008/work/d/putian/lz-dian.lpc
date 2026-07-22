// Room: /d/putian/lzdian.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"六祖殿"NOR);
        set("long", @LONG
这里是六祖殿，里面供奉着少林历史上六位有名的祖师：初祖达摩，二祖
惠可，三祖僧璨，四祖道信，五祖弘忍，六祖慧能的塑像。个个栩栩如生，活
灵活现。一位僧人正坐在蒲团上闭目养神。
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaoyuan4",
        ]));
        set("objects",([
                __DIR__"npc/shami" : 1,
                CLASS_D("putian") + "/yuanai": 1,
        ]));
        setup();
}
