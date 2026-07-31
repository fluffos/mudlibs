#include <ansi.h>
inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object me, string arg)
{
        int mark;
        mapping quest;
        string *site;

        site=({"玄武门内","青龙门内","朱雀门内","白虎门内"});
        if(!(quest =  me->query("guo_shoucheng")))
        return notify_fail(
               HIW"你并没有做过任何郭靖任务，想试一下吗？\n"NOR);

        mark = me->query_temp("guo_shoucheng/mark_shadi");

        if( mark && mark < 5 )
             write(HIW"\n你现在的任务是去协助"HIR+site[mark-1]
                     +HIW"的宋军，抗击蒙古鞑子的入侵！\n"NOR);
         
        else
          if( me->query_temp("guo_shoucheng/mark_jianlou") )
             write(HIW"\n你现在的任务是去协助青龙门内"HIR"东城箭楼"
                    +HIW"的宋军，担任狙击蒙古弓箭手的任务！\n"NOR);
        else
             write(
HIW"\n===============================================================\n"NOR
+HIR"            到目前为止，你通过郭靖任务共获得了：\n"NOR
+HIW+chinese_number(quest["reward_exp"])+NOR
+HIR"点实战经验和"NOR+HIW+chinese_number(quest["reward_potential"])+NOR
+HIR"点潜能奖励！\n"NOR
+HIR"            你已经荣立军功"HIY
+chinese_number(quest["reward"])+HIR"策！\n"NOR+
HIW"===============================================================\n"NOR);

       return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quest5  这个指令可以显示出你已经参与郭靖任务情况。
HELP
        );
        return 1;
}

