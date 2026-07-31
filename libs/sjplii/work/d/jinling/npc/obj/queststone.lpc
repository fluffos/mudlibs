// queststone.c written by john darks
#include <ansi.h>
inherit EQUIP;
int time_period(int timep, object me);

void create()
{
        set_name("任务时间探测器", ({ "questtime","detector", "glass", "device" }) );
        set_weight(300);
        set("unit", "个");
        set("long",
                "这是来自「七龙珠」的战斗力探测器，被王乞儿改装了一下，现在你可以用它来\n"
                "探测(questtime)有关任务的完成度了。\n");
        set("value", 500);
        set("no_drop",1);
        set("type", "misc");
        set("apply", ([
                "头部": 0,
        ]) );
}

void init()
{
        add_action("do_detect", "questtime");
}

int do_detect(string arg)
{
        int nowtime = time();
        int i;
        object me;
        object ob = this_player();
        if (!wizardp(ob) || arg == "") me = ob;
        else
        {
                if( arg ){
                        me = present(arg, environment(ob));
                        if (!me) me =  find_player(arg);
                        if (!me) return notify_fail("你要察看谁的任务？\n");
                }
                else
                        me = ob;
        }
        if(!me->query("wqrquest") && !me->query("quest"))
                return notify_fail("你现在没有任何任务！\n");
        if( mapp(me->query("wqrquest")))
        {
                mapping quest;
                quest =  me->query("wqrquest");
                write("你现在在王乞儿处的任务是" + quest["quest_type"] + "『" + quest["quest"] + "』。\n");
                nowtime = (int) me->query("wangqier/time") - time();
                if( nowtime  > 0 )
                        time_period(nowtime, me);
                else
                        write("但是你已经没有足够的时间来完成它了。\n");
        }
        if( mapp(me->query("quest")))
        {
                mapping quest;
                quest =  me->query("quest");
                write("你现在在李总管处的任务是" + quest["quest_type"] + "『" + quest["quest"] + "』。\n");
                nowtime = (int) me->query("task_time") - time();
                if( nowtime  > 0 )
                        time_period(nowtime, me);
                else
                        write("但是你已经没有足够的时间来完成它了。\n");
        }else write("无法监测到有效的任务。\n");
        return 1;
}


int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        tell_object(me,"你还有" + time + "去完成它。\n");
        return 1;
}

