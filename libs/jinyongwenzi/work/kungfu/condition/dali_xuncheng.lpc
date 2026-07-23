// dali_xuncheng

#include <ansi.h>
#include <login.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if (duration < 2){
                 if (me->query_temp("dali_xc/anning")&&me->query_temp("dali_xc/dg3")
&&me->query_temp("dali_xc/xishuang")&&me->query_temp("dali_xc/hg2")
&&me->query_temp("dali_xc/hg3")&&me->query_temp("dali_xc/xueshan")
&&me->query_temp("dali_xc/tianchi2")&&me->query_temp("dali_xc/yuelong")
&&me->query_temp("dali_xc/ylf1")&&me->query_temp("dali_xc/nianhuasimen")
&&me->query_temp("dali_xc/xs2")&&me->query_temp("dali_xc/sl")
&&me->query_temp("dali_xc/yzh")&&me->query_temp("dali_xc/ydxxxxxx"))
             {   me->set_temp("xuncheng_ok");               
                 tell_object(me, HIY "你巡城完毕，可以回去覆命（task ok)了！\n" NOR);
                  me->clear_condition("dali_xuncheng");
             } else {
                  me->apply_condition("dali_xuncheng", 5);

                     }
        }

     me->apply_condition("dali_xuncheng", duration - 1);
     if (!duration) return 0;
     return CND_CONTINUE;

}

string query_type(object me)
{
	return "job";
}
