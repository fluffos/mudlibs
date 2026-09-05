// xinzha Zine 户部任务

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"信扎"NOR, ({ "xin zha","xin" }) );
        set_weight(3000);
        set("unit", "封");
        set("long","这是一封信扎，你可以打开(open)它。\n");
        set("material", "paper");
                
        
        setup();
}

void init()
{
    add_action("do_open","open");
}

int do_open(string arg)
{
    object me=this_player();
    object ob=this_object();
    int n;
    string* taskwhere=({"镇江","苏州","扬州","江州","岳阳","南昌","泉州","闽南"});
    string* taskid=({"库房看守","冯正东","唐楠","温峤","李保长","楚大业","戚家军千总","林平之"});
    if (!arg)
    {
        tell_object(me,"你要打开什么？\n");
        return 1;
    }
    if (arg!="xin zha"&&arg!="xin")
    {
        tell_object(me,"你要打开什么？\n");
        return 1;
    }
    else
    {
        n=random(sizeof(taskwhere));
        message_vision("$N打开了户部密封的信扎，原来要求去"+taskwhere[n]+"地图造册。\n",me);
        tell_object(me,"你暗自寻思也许找到"+taskid[n]+"打听(dating)一下，会有帮助完成地图。\n");
        me->set_temp("songtasks/hubu/task_where",taskwhere[n]);
        destruct(ob);
        return 1;
    }
}