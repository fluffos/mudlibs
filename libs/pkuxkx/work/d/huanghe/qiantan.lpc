//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "浅滩");
        set("long", @LONG
这里是一处浅滩，黄河的宽度降到正常的一半，流速却快了许多。岸边有许
多石块(shikuai)。
LONG
        );
        set("exits", ([
             "south" : __DIR__"hhn17",
        ]));
       
        set("couldfish",1);
        

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");

        setup();
}

void init()
{
    add_action("do_swim",({"you","swim"}));
    add_action("do_find",({"ban"}));
}

int do_find()
{
    object stone;
    object me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (present("da shikuai",me))
    {
        tell_object(me,"你身上不是有一块石块了吗？\n");
        return 1;
    }
    else if (me->query("family/family_name")=="明教")
    {
        stone=new(__DIR__"obj/shi");
        stone->set("owner",me->query("id"));
        stone->move(me);
        message_vision("$N随手搬起了一块大石块。\n",me);
        return 1;
    }
    else
    {
        stone=new(__DIR__"obj/shi");
        stone->move(me);
        message_vision("$N吃力的举起了一块大石块。\n",me);
        return 1;
    }
}

int do_swim()
{
    object stone;
    object me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("family/family_name")!="明教")
    {
        tell_object(me,"你下水洗了个澡，赶紧爬回了岸边。\n");
        return 1;
    }
    if (!present("da shikuai",me))
    {
        tell_object(me,"此处水流湍急，无重物恐怕要被黄河冲走。\n");
        return 1;
    }
    stone=present("da shikuai",me);
    message_vision("$N搬起一块大石块，走进湍急的河水中。\n",me);
    me->move(__DIR__"hezhong");
    me->add_busy(7);
    me->set_temp("明教过黄河",0);
    call_out("pass",1,me,stone);
    return 1;
}

int pass(object me,object stone)
{
    if (!me)
    {
        return 1;
    }
    if (!living(me))
    {
        me->move(this_object());
        return 1;
    }
    tell_object(me,"你抱着大石块在黄河中载沉载浮，缓缓前进。\n");
    me->add_temp("明教过黄河",1);
    if (me->query_temp("明教过黄河")>=4)
    {
        tell_object(me,"半晌，你终于游到了对岸，随手扔掉了石块。\n");
        me->delete_temp("明教过黄河");
        me->move("/d/huanghenorth/qiantan2");
        destruct(stone);
        return 1;
    }
    else
    {
        call_out("pass",2,me,stone);
        return 1;
    }
}