//信物 Zine 4/4/2011
#include <ansi.h>
inherit ITEM;
#define HEADER CYN"┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR
#define TAIL   CYN"┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR 
#define LINE   CYN"┃━━━━━━━━━━━━━━━━━━━━━━━━━┃\n"NOR
void create()
{
        set_name(WHT"信物"NOR, ({ "xin wu"}) );
        set_weight(300);
        set("unit", "份");
        set("long", "这是一份南海神尼给你的信物，可以查询(chaxun)考验任务完成情况。\n");
     
        set("value", 0);
        set("material", "paper");
               
        setup();
        call_out("dest",1860);
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
    }
    return 1;
}

void init()
{
    add_action("do_chaxun","chaxun");
}

int do_chaxun()
{
    object ob=this_object();
    object me=this_player();
    object partner;
    string msg,info;
    int remain;
    int st1,st2,st3,st4,st5,st6;
    partner=find_player(ob->query("partner"));
    if (!partner)
    {
        st1=me->query("jobs/completed/huyidao")-ob->query("st1");
        st2=me->query("jobs/completed/hubiao")-ob->query("st2");
        st3=me->query("jobs/completed/xiaofeng")-ob->query("st3");
        //st4=me->query("jobs/completed/task")-ob->query("st4");
        st5=me->query("newjobs/completed/pyh")-ob->query("st5");
        st6=me->query("newjobs/completed/hyw")-ob->query("st6");
    }
    else
    {
        st1=me->query("jobs/completed/huyidao")+partner->query("jobs/completed/huyidao")-ob->query("st1");
        st2=me->query("jobs/completed/hubiao")+partner->query("jobs/completed/hubiao")-ob->query("st2");
        st3=me->query("jobs/completed/xiaofeng")+partner->query("jobs/completed/xiaofeng")-ob->query("st3");
        //st4=me->query("jobs/completed/task")+partner->query("jobs/completed/task")-ob->query("st4");
        st5=me->query("newjobs/completed/pyh")+partner->query("newjobs/completed/pyh")-ob->query("st5");
        st6=me->query("newjobs/completed/hyw")+partner->query("newjobs/completed/hyw")-ob->query("st6");
    }
    if (!me->query_temp("shilian/start"))
    {
        return notify_fail("你的考验任务失败了。\n");
    }
    
        remain=1800+(int)me->query_temp("shilian/start")-time();
        remain=remain-(int)me->query_temp("shilian/level")*90;
        msg="\n\n";
        msg+=HEADER;
        info=WHT"              ★★★南海神尼的考验★★★\n"NOR;
        msg+=info;
        msg+=LINE;
        if (st1>=4)
        {
            info="        胡一刀："+HIG+st1+NOR+"/4"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        胡一刀："+CYN+st1+NOR+"/4\n";
        }
        msg+=info;
        if (st2>=4)
        {
            info="        护镖："+HIG+st2+NOR+"/4"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        护镖："+CYN+st2+NOR+"/4\n";
        }
        msg+=info;
        if (st3>=2)
        {
            info="        萧峰："+HIG+st3+NOR+"/2"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        萧峰："+CYN+st3+NOR+"/2\n";
        }
        msg+=info;
        if (st5>=1)
        {
            info="        鄱阳湖寻宝："+HIG+st5+NOR+"/1"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        鄱阳湖寻宝："+CYN+st5+NOR+"/1\n";
        }
        msg+=info;
        if (st6>=4)
        {
            info="        韩员外复仇："+HIG+st6+NOR+"/4"+HIG+"  √\n"+NOR;
        }
        else
        {
            info="        韩员外复仇："+CYN+st6+NOR+"/4\n";
        }
        msg+=info;
        msg+=LINE;
        if (remain>0)
        {
            if (remain<600)
            {
                info="        剩余时间："+RED+chinese_number(remain)+"秒/一千八百秒\n"+NOR;
            }
            else
            {
                info="        剩余时间："+CYN+chinese_number(remain)+"秒/一千八百秒\n"+NOR;
            }
        }
        else
        {
            info=RED"        已经超过半小时，你的考验任务失败了。\n"NOR;
        }
        
        msg+=info;
        if (partner)
        {
            msg+=LINE;
            info="           你的搭档是："+HIW+ob->query("partnername")+NOR+"。\n";
            msg+=info;
        }
        msg+=TAIL;
        tell_object(me,msg);
        return 1;

}