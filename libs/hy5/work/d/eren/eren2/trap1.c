#include <ansi.h>
inherit ROOM; 
void create()
{
        object me;
        me = this_player();
        set("short", "陷坑");
        set("long", @LONG
这是一个深深的葫芦型的陷坑，四壁潮湿而又光滑。坑底甚为宽敞。
脚边是三具已经腐烂的尸体，旁边似乎还有几只大老鼠，正在黑暗中窥
视着你，仿佛在等着将你作为下一顿美餐。
LONG);
        set("indoors", "eren2");
        set("no_magic",1);
        set("objects", ([
                __DIR__"npc/rat" : 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{       
        add_action("do_climb", "climb");
}  
int do_climb(string arg)
{
    object obj, me;
    int kar;
    
    if(!arg || arg=="") return notify_fail("你要往哪里爬？\n");
    me = this_player();
    if( arg == "wall" || arg == "洞壁" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("你的动作还没有完成，不能移动。\n");
        message_vision("$N使出吃奶的力量，顺着洞壁向上爬去。\n", me);
        me->start_busy(1);
        call_out("climb_wall", 2, me);
        return 1;
    }
    return notify_fail("你不可以爬"+arg+"！\n");
}        
int climb_wall(object me)
{
    int kar;
    
    if (me->is_ghost()) return 0;
    kar = (int)me->query("kar");
    if( kar > 60 ) kar = 60;
    if( random(60 - kar) < 15 )
    {
        me->move(__DIR__"yongdao2a.c");
        message_vision("$N从陷阱中艰难地爬了出来。\n", me);
    }
    else message_vision("$N手上一个没抓稳，又掉了下来。\n", me);
    return 1;
}   
