// dali_xuncheng

#include <ansi.h>
#include <login.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if (duration < 2){
                 if (me->query_temp("wudu_xs/huayuan1")&&me->query_temp("wudu_xs/huayuan2")
&&me->query_temp("wudu_xs/huayuan3")&&me->query_temp("wudu_xs/huating1")
&&me->query_temp("wudu_xs/huating2")&&me->query_temp("wudu_xs/huating3")
&&me->query_temp("wudu_xs/beiyuan")&&me->query_temp("wudu_xs/bingqi")
&&me->query_temp("wudu_xs/shufang")&&me->query_temp("wudu_xs/jingshi")
&&me->query_temp("wudu_xs/chufang")&&me->query_temp("wudu_xs/damen")
&&me->query_temp("wudu_xs/lianwu")&&me->query_temp("wudu_xs/dating")
&&me->query_temp("wudu_xs/yaoshi")&&me->query_temp("wudu_xs/xiangfang")
&&me->query_temp("wudu_xs/nanyuan")&&me->query_temp("wudu_xs/liandu"))
             {   me->set_temp("xunshan_ok");               
                 tell_object(me, HIY "你巡山完毕，可以回去覆命（task ok)了！\n" NOR);
                  me->clear_condition("wudu_xunshan");
             } else {
                  me->apply_condition("wudu_xunshan", 5);

                     }
        }

     me->apply_condition("wudu_xunshan", duration - 1);
     if (!duration) return 0;
     return CND_CONTINUE;

}

string query_type(object me)
{
        return "job";
}

