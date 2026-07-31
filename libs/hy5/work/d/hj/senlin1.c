// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","针叶林");
       set("long", @LONG
这是极西天山脚下的一片针叶林，林中鸟兽成群，满地铺盖着厚厚一
层松针。北方的一座高耸的山脉便是天山了，山上终年积雪，山下却是绿
树成荫。往南走便是大草原，有辛勤的哈萨克族人在那里放牧。你走着走
着，竟然迷失了道路。
LONG);
        set("exits", ([
             "east"  : __DIR__"senlin"+(1+random(4)),
             "west"  : __DIR__"senlin"+(1+random(4)),
             "south" : __DIR__"senlin"+(1+random(4)),
             "north" : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("outdoors", "tianshan");
        setup();            
}

void init()
{
        object me = this_player();
        if(userp(me) && me->query("jingli") < 10){
           switch(random(2)) {
            case 0 : me->move(__DIR__"shanqiu"); break;
            case 1 : me->move("/d/xingxiu/shanjiao"); break;
            }
           message_vision("$N昏昏沉沉地走了过来。\n",me);
           me->unconcious();
           }
        if(!me->query_temp("corredt_dir") && userp(me))
         me->set_temp("correct_dir", keys(query("exits"))[random(sizeof(query("exits")))]);
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

