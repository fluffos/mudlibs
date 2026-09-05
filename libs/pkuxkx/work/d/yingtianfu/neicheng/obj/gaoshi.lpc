//告示 Zine 4/4/2011
#include <ansi.h>
inherit ITEM;
#define HEADER CYN"┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR
#define TAIL   CYN"┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR 
#define LINE   CYN"┃━━━━━━━━━━━━━━━━━━━━━━━━━┃\n"NOR
void create()
{
        set_name(CYN"告示"NOR, ({ "gao shi", "notice" }) );
        set_weight(300);
        set("unit", "份");
        set("long", "这是一份大明招募勇士抵御女真入侵的告示，你可以查看说明(shuoming)，也可以查询(chaxun)完成情况。\n");
     
        set("value", 10);
        set("material", "paper");
               
        setup();
}

void init()
{
    add_action("do_shuoming","shuoming");
    add_action("do_chaxun","chaxun");
}

int do_shuoming()
{
    object ob=this_object();
    object me=this_player();
    if (me->query("id")!=ob->query("owner"))
    {
        return notify_fail("这张告示你从哪里捡来的？\n");
    }
    else
    {
        message_vision("$N开始仔细阅读告示……\n",me);
        tell_object(me,"大明边事告急，特简提拔官员。为考核计，以甄能吏。\n");
        tell_object(me,"在一小时内完成告示上所有任务者，可以入围，速度最快者可晋升大明六品武职。\n");
        tell_object(me,"榜单上写着，四次胡一刀任务，四次护镖任务，一次鄱阳湖寻宝任务，六次韩元外任务。累计两次萧峰或TASK。\n");
        tell_object(me,"你可以用查询(chaxun)命令随时查询任务完成情况。\n");
        tell_object(me,"所有任务完成后回到洪武门复命(fuming)。\n");
        return 1;
    }
}

int do_chaxun()
{
    object ob=this_object();
    object me=this_player();
    string msg,info;
    int remain;
    int sta1,sta2,sta3,sta4,sta5;
    if (me->query("id")!=ob->query("owner"))
    {
        return notify_fail("这张告示你从哪里捡来的？\n");
    }
    else
    {
        if (!me->query_temp("mingtask/entry"))
        {
            return notify_fail("你的大明官员简拔试炼失败了。\n");
        }
        sta1=me->query("jobs/completed/huyidao")-me->query_temp("mingtask/entry/huyidao");
        sta2=me->query("jobs/completed/hubiao")-me->query_temp("mingtask/entry/hubiao");
        sta3=me->query("jobs/completed/xiaofeng")+me->query("jobs/completed/task")-me->query_temp("mingtask/entry/xiaofeng")-me->query_temp("mingtask/entry/task");
        sta4=me->query("newjobs/completed/pyh")-me->query_temp("mingtask/entry/pyh");
        sta5=me->query("newjobs/completed/hyw")-me->query_temp("mingtask/entry/hyw");
        remain=3600+(int)me->query_temp("mingtask/entry/start")-time();
        msg="\n\n";
        msg+=HEADER;
        info=CYN"              ★★★大明官员简拔试炼★★★\n"NOR;
        msg+=info;
        msg+=LINE;
        if (sta1>=4)
        {
            info="        胡一刀："+HIG+sta1+NOR+"/4"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        胡一刀："+CYN+sta1+NOR+"/4\n";
        }
        msg+=info;
        if (sta2>=4)
        {
            info="        护镖："+HIG+sta2+NOR+"/4"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        护镖："+CYN+sta2+NOR+"/4\n";
        }
        msg+=info;
        if (sta3>=2)
        {
            info="        萧峰/TASK："+HIG+sta3+NOR+"/2"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        萧峰/TASK："+CYN+sta3+NOR+"/2\n";
        }
        msg+=info;
        if (sta4>=1)
        {
            info="        鄱阳湖寻宝："+HIG+sta4+NOR+"/1"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        鄱阳湖寻宝："+CYN+sta4+NOR+"/1\n";
        }
        msg+=info;
        if (sta5>=6)
        {
            info="        韩元外复仇："+HIG+sta5+NOR+"/6"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        韩元外复仇："+CYN+sta5+NOR+"/6\n";
        }
        msg+=info;
        msg+=LINE;
        if (remain>0)
        {
            if (remain<600)
            {
                info="        剩余时间："+RED+chinese_number(remain)+"秒/三千六百秒\n"+NOR;
            }
            else
            {
                info="        剩余时间："+CYN+chinese_number(remain)+"秒/三千六百秒\n"+NOR;
            }
        }
        else
        {
            info=RED"        已经超过一小时，你的试炼任务失败了。\n"NOR;
        }
        msg+=info;
        msg+=TAIL;
        tell_object(me,msg);
        return 1;
    }

}