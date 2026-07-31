// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","针叶林");
       set("long", @LONG
这是极西天山脚下的一片针叶林，林中鸟兽成群，满地铺盖着厚厚一
层松针。西北方的一座高耸的山脉便是天山了，山上终年积雪，山下却是
绿树成荫。往东南走便是大草原，有辛勤的哈萨克族人在那里放牧。你走
着走着，竟然迷失了道路。
LONG);
        set("exits", ([
             "east"  : __DIR__"senlin"+(1+random(4)),
             "west"  : __DIR__"senlin"+(1+random(4)),
             "south" : __DIR__"senlin"+(1+random(4)),
             "north" : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("objects", ([
                         __DIR__"npc/huilang" : 2,
        ]));

        set("outdoors", "tianshan");
        setup();           
}

int valid_leave(object me, string dir)
{
        if( dir != me->query_temp("correct_dir"))
                me->set_temp("ts_sl", 0);
        else    me->add_temp("ts_sl", 1);

        if( me->query_temp("ts_sl") > 5 + random(5) ) {
                me->move(__DIR__"senlin");
                me->delete_temp("ts_sl");
                me->delete_temp("correct_dir");
                return notify_fail("你累得半死，终於找到了正确的方向。\n");
 return 1;
        }
        return ::valid_leave(me,dir);
}