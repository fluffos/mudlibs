// by binlang
//shamo4
#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_view();
void create()
{
        set("short","大沙漠");
        set("long", @LONG
这是一片一望无际的大沙漠，连着明教和中原，
你一进来就迷失了方向，赶快离开吧。
    这片沙漠中，你总觉得这里跟其他地方有点不同。
LONG
        );
        set("exits", ([
                "south" :__DIR__"shamo5",
                "north" :__DIR__"shamo6",
                "east"  :__FILE__,
                "west"  :__FILE__,
        ]));
        set("outdoors", "mingjiao");
        setup();
}
void init()
{        
        add_action("do_view", "view");
        add_action("do_view", "chakan");
        add_action("do_view", "kan");
        add_action("do_enter","enter");
        add_action("do_enter","zuan");
}
int valid_leave(object me, string dir)
{
        if ( dir == "west")
                me->add_temp("mark/steps",1);
        if ( dir == "east")
                me->add_temp("mark/steps",-1);
        return ::valid_leave(me,dir);
}
int do_view()
{
        object me=this_player();
        if (random(20)) 
        {
              tell_object(me,HIY"你四处查看，也没有发现什么异常。\n"NOR);
        }
        else
        {
              me->set_temp("yyd/can_enter",1);
              tell_object(me,HIY"你四处查看，发现不远的前方有一个小洞（hole）似乎可以钻进去。\n"NOR);                 
        }
        return 1;       
}
int do_enter(string arg)
{
        object me=this_player();
        if( !arg || arg=="" || arg!="hole") 
             return notify_fail("你要钻什么？\n");
        if(me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着呢！\n"); 
        if (arg=="hole" && me->query_temp("yyd/can_enter")>0)
        {
             message("vision",me->name() + "一弯腰往洞里走了进去。\n",environment(me), ({me}) );
             me->move("/d/reborn/jinyong/yyd_hole");
             message("vision",me->name() + "从洞外走了进来。\n",environment(me), ({me}) );
             return 1;
        }
        return 0;
}
