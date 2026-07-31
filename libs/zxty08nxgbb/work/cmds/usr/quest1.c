#include <ansi.h>
inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object me, string arg)
{
        int nowtime = time();
        mapping quest;

        if(!(quest =  me->query("kill_quest")))
        return notify_fail(
               HIW"你并没有做过任何独孤求败任务，想试一下吗？\n"NOR);

        if(me->query_temp("kill_quest/have_task"))
        {
        write(HIW"你现在的任务是去除掉在"+quest["killed_place_name"]
           +"一带活动的"+quest["killed_name"]
           +"("+quest["killed"]+")。\n"NOR);
        
        nowtime =(int) quest["time"]+900-time();
        if( nowtime  > 0 )
        time_period(nowtime, me);
        else
        write(HIW"可是你已经没有足够时间来完成了，再去要一个吧。\n"NOR);
        write(HIW"你在此轮任务中已完成了"NOR
        +HIR+chinese_number(me->query_temp("kill_quest/count"))+NOR 
           +HIW"个任务，加油呀！\n");
        } else
        write(
        HIW"===============================================================\n"NOR
       +HIG"            到目前为止，你通过独孤求拜任务共获得了：\n"NOR
  +HIR+me->query("kill_quest/reward_exp")+NOR
+HIG"点实战经验和"NOR+HIR+me->query("kill_quest/reward_potential")+NOR
       +HIG"点潜能奖励！\n"NOR
       +HIG"            你现在并没有任何任务，去要一个吧！\n"NOR+
        HIW"===============================================================\n"NOR);

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
        if(d) 
                time = chinese_number(d) + "天";
        else 
                time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        tell_object(me,HIW"你还有" + time + "去完成它。\n"NOR);
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : quest1  这个指令可以显示出你当前的独孤求败任务。
HELP
        );
        return 1;
}


