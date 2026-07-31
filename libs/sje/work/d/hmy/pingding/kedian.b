// kedian.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"平定客店"NOR);
        set("long", @LONG       
这里就是平定客店，老板的生意非常兴隆。外地游客多选择这里落脚。店
小二里里外外忙得团团转，接待着南腔北调的客人。当你走了进来，店小二连
忙迎上前去。客栈正面的墙上挂着一块醒目的牌子(paizi)。
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);
         set("no_fight",1);

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
        ]));

        set("objects", ([
         __DIR__"npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"cj3",
                "north" : __DIR__"kefang",
                "up" : __DIR__"kedian2",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("怎么着，想白住啊！\n");

        if ( me->query_temp("rent_paid") && dir == "west" )
                return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

        return ::valid_leave(me, dir);
}

