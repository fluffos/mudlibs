
// mr_job.c

#include <ansi.h>

int update_condition(object me, int duration)
{                                        
        string skill;
        if (duration < 1) {
                                             
                tell_object(me, HIY"你正在执行的任务已经被取消了！\n"NOR);     
               
                if(stringp( skill = me->query("doing_job") )) {
                    me->delete_skill(skill);
                    me->reset_action();                            
                }
                
                if(present("paper", me))
                {  
                      destruct(present("paper",me));
                }
                
                me->delete_temp("skill_target");
                me->delete_temp("skill_id");
                me->delete_temp("skill_type");
                me->delete_temp("skill_lvl");
                me->delete_temp("job_done");
                me->delete_temp("mr_job");
                me->delete_temp("mr_job_done");                
                me->delete("doing_job");
                me->clear_condition("mr_job");
                me->apply_condition("wait_mr_job", 50-(me->query_int()));
                return 0;
        }
        me->apply_condition("mr_job", duration - 1);
        return 1;
}