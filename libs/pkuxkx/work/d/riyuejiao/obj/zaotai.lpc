
inherit ITEM;
#include "/d/riyuejiao/bonus.h"
#include <ansi.h>
void create()
{
        set_name(WHT"灶台"NOR, ({"zao tai", "zao","zaotai"}));
        set_weight(8000000);
        set("bonus",28);
        set("long", "这是一个灶台，上面油腻腻脏兮兮的。\n");
                set("unit", "个");
                set("value", 0);
                set("no_get",1);
        setup();
}

void init()
{
    add_action("do_dianhuo","dianhuo");
    add_action("do_add","add");
    add_action("do_shao","zuocai");
}

int finish(object me)
{
    object env,food;
    if (!me||!living(me))
    {
        return 1;
    }
    env=environment(me);
    if (!env)
    {
        return 1;
    }
    if (!me->query_temp("rynewbiejob/chufang/shicai"))
    {
        return 1;
    }
    if (me->query_temp("rynewbiejob/chufang/zuocai_degree")<10+random(10))
    {
        me->add_temp("rynewbiejob/chufang/zuocai_degree",1);
        message_vision("$N不断地翻炒锅里的菜。\n",me);
        call_out("finish",2,me);
        return 1;
    }
    if (base_name(env)=="/d/riyuejiao/chufang")
    {
        if (me->query_temp("rynewbiejob/chufang/shicai")==1)
        {
            food=new("/d/shaolin/obj/mala-doufu");
        }
        if (me->query_temp("rynewbiejob/chufang/shicai")==2)
        {
            food=new("/d/shaolin/obj/bocai-fentiao");
        }
        if (me->query_temp("rynewbiejob/chufang/shicai")==3)
        {
            food=new("/d/shaolin/obj/shanhu-baicai");
        }
        if (me->query_temp("rynewbiejob/chufang/shicai")==4)
        {
            food=new("/d/shaolin/obj/liuli-qiezi");
        }
        food->set("owner",me->query("id"));
        food->set("shicai",me->query_temp("rynewbiejob/chufang/shicai"));
        food->move(me);
        me->delete_temp("rynewbiejob/chufang/startshaocai");
        me->delete_temp("rynewbiejob/chufang/zuocai_degree");
        me->delete_temp("rynewbiejob/chufang/dian");
        message_vision("$N端出了一盘"+food->name()+"香气四溢，十分诱人。\n",me);
        return 1;
    }
    else
    {
        tell_object(me,"你跑到哪里去了？菜都烧糊了！\n");
        return 1;
    }

}

int do_shao(string arg)
{
    object me=this_player();
    object shi;
    int i,count=0;
    object *all=all_inventory(me);
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_shicai"))
        {
            count=1;
        }
    }
    if (me->query("family/family_name")!="日月神教")
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query("rynewbiejob/chufang/start",1))
    {
        tell_object(me,"大师傅没让你做饭，不要帮倒忙。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/chufang/startshaocai"))
    {
        tell_object(me,"你已经在烧菜了。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要做什么菜？\n");
        return 1;
    }
    if (arg!="dou fu"&&arg!="bai cai"&&arg!="qie zi"&&arg!="fen tiao")
    {
        tell_object(me,"你要烧的东西不是大师傅给你的食材。\n");
        return 1;
    }
    if (arg&&!present(arg,me))
    {
        tell_object(me,"你身上没有大师傅要你烧的食材。\n");
        return 1;
    }
    shi=present(arg,me);
    if (!me->query_temp("rynewbiejob/chufang/dian"))
    {
        tell_object(me,"你还没有点火呢，怎么做饭？\n");
        return 1;
    }
    if (shi->query("shicai")!=me->query_temp("rynewbiejob/chufang/shicai"))
    {
        tell_object(me,"这不是大师傅要你做的食物。\n");
        return 1;
    }
    message_vision("$N把"+shi->name()+"倒进了灶台上的锅里，开始炒菜。\n",me);
    me->set_temp("rynewbiejob/chufang/startshaocai",1);
    destruct(shi);
    call_out("finish",2,me);
    return 1;
}

int do_add(string arg)
{
    object me=this_player();
    object chai;
    if (me->query("family/family_name")!="日月神教")
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query("rynewbiejob/chufang/start"))
    {
        tell_object(me,"大师傅没让你做饭，不要帮倒忙。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要往灶台里加什么？\n");
        return 1;
    }
    if (arg!="chai huo"&&arg!="chaihuo"&&arg!="chai")
    {
        tell_object(me,"灶台不是垃圾箱，别乱装东西。\n");
        return 1;
    }
    if (!present("chai huo",me))
    {
        tell_object(me,"你身上没有柴火，你要往灶台里加什么？\n");
        return 1;
    }
    chai=present("chai huo",me);
    if (!chai->query("is_chai"))
    {
        tell_object(me,"你身上没有柴火，你要往灶台里加什么？\n");
        return 1;
    }
    message_vision("$N往灶台里添加了一条柴火。\n",me);
    destruct(chai);
    me->add_busy(1+random(2));
    me->add_temp("rynewbiejob/chufang/chai",1);
    return 1;
}

int do_dianhuo()
{
    object me=this_player();
    if (me->query("family/family_name")!="日月神教")
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query("rynewbiejob/chufang/start"))
    {
        tell_object(me,"大师傅没让你做饭，不要帮倒忙。\n");
        return 1;
    }
    if (!present("fire",me))
    {
        tell_object(me,"你身上没有火折，不能点火烧饭。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/chufang/chai")<3)
    {
        tell_object(me,"灶台里柴火不足，这时候是无论如何也无法点燃的。\n");
        return 1;
    }
    if (random(100)>40)
    {
        message_vision("$N努力把灶台里的柴火点着，可惜没有成功。\n",me);
        me->add_busy(1);
        return 1;
    }
    else
    {
        message_vision("$N努力点燃灶台里的柴火，终于成功了。\n",me);
        me->delete_temp("rynewbiejob/chufang/chai");
        me->set_temp("rynewbiejob/chufang/dian",1);
        if (me->query("rynewbiejob/chufang/start")==1)
        {
            me->delete("rynewbiejob/chufang/start");
            bonus(me);
        }
        return 1;
    }

}