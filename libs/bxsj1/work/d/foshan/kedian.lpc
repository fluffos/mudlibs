
#include <ansi.h>
inherit ROOM;

void create()
{
            set("short", HIC"英雄客栈"NOR);
        set("long", @LONG       
这是一间装修不错的客栈，正上方挂着一块金边的木匾，上书“英雄
客栈”，这是凤天南的产业之一，凭着南霸天的威名，这数年来一直无人
敢在此捣乱。来来往往的客商在此住宿也比较放心，店小二正里里外外不
停地忙乎着。客栈正面的墙上挂着一块醒目的牌子(paizi)。
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);
         set("no_fight",1);

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
        ]));

        set("objects", ([
        __DIR__"npc/xiaoer2" : 1,
        ]));

        set("exits", ([ /* sizeof() == 2 */
               "up" : __DIR__"kedian2",
               "east" : __DIR__"nanjie",
        ]));

        set("coor/x",-10);
  set("coor/y",-550);
   set("coor/z",0);
   setup();

}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("怎么着，想白住啊！\n");

        if ( me->query_temp("rent_paid") && dir == "east" )
                return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

        return ::valid_leave(me, dir);
}
