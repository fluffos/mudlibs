// piwen 刑部

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"批文"NOR, ({ "pi wen","wen","paper" }) );
        set_weight(3000);
        set("unit", "张");
        set("value",0);
        set("long","这是一张临安府开具的提取物资的批文。\n");
        set("material", "paper");
                
        
        setup();
}

int dest(object ob)
{
    if (ob)
    {
        destruct(ob);
    }
    return 1;
}

void init()
{
    object ob=this_object();
    object me=environment(ob);
    add_action("do_ling","ling");
    if (me->query_temp("songtasks/xingbu/task1no")==1)
    {
        ob->set("long","这是一张临安府开具的领取囚衣的批文。\n");
        return;
    }
    if (me->query_temp("songtasks/xingbu/task1no")==2)
    {
        ob->set("long","这是一张临安府开具的领取囚粮的批文。\n");
        return;
    }
    if (me->query_temp("songtasks/xingbu/task1no")==3)
    {
        ob->set("long","这是一张临安府开具的领取药品的批文。\n");
        return;
    }
    else
    {
        call_out("dest",1,ob);
    }
}

int do_ling()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    if (me->query_temp("songtasks/xingbu/che/can_go"))
    {
        tell_object(me,"你不是领过物资了吗？快送去吧。\n");
        return 1;
    }
    if (ob->query("owner")!=me->query("id"))
    {
        tell_object(me,"这张批文上并未写上你的名字。\n");
        return 1;
    }
    if (base_name(environment(me))=="/d/hangzhou/changping")
    {
        if (me->query_temp("songtasks/xingbu/task1no")==2)
        {
            thing=new(__DIR__"qiuliang");
            thing->set("owner",me->query("id"));
            thing->move(environment(me));
            message_vision("几个小吏给$N推出一车囚粮。\n",me);
            me->set_temp("songtasks/xingbu/che/can_go",1);
            return 1;
        }
        else
        {
            tell_object(me,"你要运送的是什么？\n");
            return 1;
        }
    }
    if (base_name(environment(me))=="/d/song/taiyiju")
    {
        if (me->query_temp("songtasks/xingbu/task1no")==3)
        {
            thing=new(__DIR__"qiuyao");
            thing->set("owner",me->query("id"));
            thing->move(environment(me));
            message_vision("几个小吏给$N推出一车药品。\n",me);
            me->set_temp("songtasks/xingbu/che/can_go",1);
            return 1;
        }
        else
        {
            tell_object(me,"你要运送的是什么？\n");
            return 1;
        }
    }
    if (base_name(environment(me))=="/d/song/xing_ku")
    {
        if (me->query_temp("songtasks/xingbu/task1no")==1)
        {
            thing=new(__DIR__"qiufu");
            thing->set("owner",me->query("id"));
            thing->move(environment(me));
            message_vision("几个小吏给$N推出一车囚服。\n",me);
            me->set_temp("songtasks/xingbu/che/can_go",1);
            return 1;
        }
        else
        {
            tell_object(me,"你要运送的是什么？\n");
            return 1;
        }
    }
    else
    {
        tell_object(me,"临安府尹的批文让你去哪里领东西的？\n");
        return 1;
    }
}