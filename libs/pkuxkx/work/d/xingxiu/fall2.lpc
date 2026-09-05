// 谷底
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
#include "/d/xingxiu/climb_fall.h"
void create()
{
	set("short", HIW"瀑布"NOR);
	set("long", @LONG
这里是一条大瀑布，水流日夜不停的向下冲去。
LONG
	);
    set("exits", ([
             "down" : __DIR__"waterfall",
             "up": __DIR__"fall3",
        ]));
    set("climb_bonus",9);
    set("outdoors", "xingxiuhai");
    setup();
	::create();
}

int entry(object pl)
{
    return 1;
}

void init()
{
    add_action("do_climb","climb");
    add_action("do_none", "");
    if ((userp(this_player())&&!random(20))||wizardp(this_player()))
    {
        remove_call_out("entry");
        call_out("entry",10,this_player());
        this_player()->set_temp("xx_valley_quest_fall_hide_room",time());
        return;
    }
}

int valid_leave(object me,string dir)
{
    if (dir=="up"||dir=="down")
    {
        return notify_fail("别做梦了，这样的大瀑布你想直接走上去？老老实实爬(climb)吧。\n");
    }
    return ::valid_leave(me,dir);
}

int do_climb(string arg)
{
    object rm,me=this_player();
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
    if (arg=="up")
    {
        rm=load_object(__DIR__"fall3");
        message_vision(HIW"$N手脚并用，抓着瀑布下的突起，向上爬去。\n"NOR,me);
        me->add_busy(2+random(3));
        climb_up(me);
        tell_room(rm,me->name()+"十分艰难地爬了过来。\n");
        me->move(rm);
        return 1;
    }
    else if (arg=="down")
    {
        rm=load_object(__DIR__"waterfall");
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

