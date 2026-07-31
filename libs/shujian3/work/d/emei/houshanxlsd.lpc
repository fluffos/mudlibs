// houshanty.c
// 后山修炼山洞小路
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG "山洞" NOR);
        set("long", @long
这里是一个潮湿阴冷的山洞，洞中有一块大石头，紧靠着山洞的后壁，后
壁上隐约有个盘坐的人形。
long);
        set("outdoors", "峨眉山");
        set("exits",([
             "out":__DIR__"houshansl",
]));
        setup();
}

void init()
{
//     add_action("do_panzuo", "panzuo");
//     add_action("do_xiulian", "xiulian");
}

int do_panzuo(string arg)
{
    object me=this_player();
    if (me->is_busy())
        return notify_fail("你现在正忙着呢！\n");
    if (!arg && arg!="stone" && arg!="shitou" && arg!="shi" )
        return 0;
    message_vision("$N盘腿坐在大石头上面，面向石壁。\n", me);
    me->set_temp("marks", "盘坐");
    return 1;
}

int do_xiulian()
{
    object me=this_player();
    if( me->query_temp("marks") != "盘坐" )
        return 0;
    message_vision("$N盘腿坐在大石头上面，面向石壁，陷入深深的思索之中。\n", me);
    me->delete_temp("marks");
    me->start_busy(30);
    call_out("end_xiulian", 60, me);
    return 1;
}

void end_xiulian(object me)
{
	if (!me) return;
    message_vision("过了良久，$N终于深有所悟。\n", me);
    if( (int)me->query("emsujia") < 2 ) me->add("emsujia", 1);
    me->add("potential", me->query_skill("linji-zhuang",1)/10);
        if((int)me->query("potential", 1)> (int)me->query("max_pot", 1))
           me->set("potential", (int)me->query("max_pot", 1));
    me->add("combat_exp", me->query_skill("linji-zhuang",1)/30);
    return;    
}
