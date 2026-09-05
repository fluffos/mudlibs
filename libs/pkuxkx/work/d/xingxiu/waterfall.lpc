// 谷底
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
#include "/d/xingxiu/flower.h"
string look_fall();
void create()
{
	set("short", HIW"小溪源头"NOR);
	set("long", @LONG
这里是谷底小溪的源头，再往上一道瀑布(fall)直坠而下。隆隆的水声震慑
着每个人的心扉，提醒着人们大自然的造化之功。
LONG
	);
    set("exits", ([
             "southdown" : __DIR__"gu4",
             "up": __DIR__"fall2",
        ]));
	set("resource/water", 1);
    set("couldfish",1);
    set("outdoors", "xingxiuhai");
	set("item_desc", ([ 
        "fall" : (:look_fall:),
    ])); 
    setup();
	::create();
}
int gene()
{
    object obs,*ob=all_inventory(this_object());
    int i;
    if (sizeof(ob)>3||time()-(int)this_object()->query("gene_time")<10)
    {
        return 1;
    }
    else
    {
        obs=new(flower);
        obs->move(this_object());
        obs=new(flower);
        obs->move(this_object());
        this_object()->set("gene_time",time());
        return 1;
    }
}

string look_fall()
{
    object me=this_player();
    object ob;
    string msg;
    if (me->is_busy()||me->is_fighting())
    {
        msg="你正忙着呢，还有闲情逸致欣赏瀑布。\n";
        return msg;
    }
    else
    {
        msg="这夺天造化的大瀑布一颗也不停歇的流淌着。\n";
        return msg;
    }
}


void init()
{
    add_action("do_climb","climb");
    add_action("do_drink", "drink");
    gene();
}

int valid_leave(object me,string dir)
{
    if (dir=="up")
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
    if (!arg)
    {
        tell_object(me,"你要爬什么？\n");
        return 1;
    }
    if (arg=="fall"||arg=="瀑布")
    {
        tell_object(me,"你可以用的命令是climb <方向>。\n");
        return 1;
    }
    if (arg!="up")
    {
        tell_object(me,"你要往哪个方向爬？\n");
        return 1;
    }
    if (me->query_skill("dodge",1)<300||((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance())>30)
    {
        tell_object(me,"你爬了一半，脚下一滑，重重的摔了下去。\n");
        me->unconcious();
        return 1;
    }
    message_vision(HIW"$N手脚并用，抓着瀑布下的突起，向上爬去。\n"NOR,me);
    me->add_busy(2+random(3));
    rm=load_object(__DIR__"fall2");
    tell_room(rm,me->name()+"十分艰难地爬了过来。\n");
    me->move(rm);
    return 1;
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 250);
                message("vision", me->name()+"趴在小溪源头，一通牛饮。\n",
                        environment(me), ({me}) );
                write("你趴在小溪源头，咕噜咕噜喝起水来了。\n");
        }
        else write("你已经不渴了，还是别喝了。\n");

        return 1;
}