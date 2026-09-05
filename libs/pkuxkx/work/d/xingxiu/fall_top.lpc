// 谷底
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
#include "/d/xingxiu/climb_fall.h"
string look_fall();
void create()
{
	set("short", HIW"瀑布顶端"NOR);
	set("long", @LONG
这里是大瀑布的顶端，水流日夜不停的向下冲去，旁边一块大石，正是观瀑
的好所在，你可以游(swim)过去。你也可以向下爬(climb)回去。
LONG
	);
    set("exits", ([
             "down" : __DIR__"fall3",
        ]));
    set("climb_bonus",15);
    set("outdoors", "xingxiuhai");
    setup();
    ::create();
}
int valid_leave(object me,string dir)
{
    if (dir=="down")
    {
        return notify_fail("别做梦了，这样的大瀑布你想直接走上去？老老实实爬(climb)吧。\n");
    }
    return ::valid_leave(me,dir);
}

void init()
{
    add_action("do_swim","swim");
    add_action("do_climb","climb");
    add_action("do_none", "");
}

int do_swim()
{
    object rm,me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    rm=load_object(__DIR__"fall_top2");
    message_vision(HIG"$N使出吃奶的劲，向"+rm->query("short")+HIG+"游了过去。\n"NOR,me);
    me->add_busy(3);
    tell_room(rm,me->name()+"十分艰难地游了过来。\n");
    me->move(rm);
    return 1;
}

int do_climb(string arg)
{
    object ob,rm,me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_skill("dodge",1)<300||((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance())>30)
    {
        tell_object(me,"你爬了一半，脚下一滑，重重的摔了下去。\n");
        me->unconcious();
        return 1;
    }
    else if (arg=="down")
    {
        rm=load_object(__DIR__"fall2");
        message_vision(HIW"$N手脚并用，抓着瀑布下的突起，向下爬去。\n"NOR,me);
        me->add_busy(2+random(3));
        climb_down(me);
        tell_room(rm,me->name()+"十分艰难地爬了过来。\n");
        me->move(rm);
        return 1;
    }
    else
    {
        tell_object(me,"你要往哪个方向爬？\n");
        return 1;
    }
}
