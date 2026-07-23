#include <ansi.h>
int update_condition(object me, int duration)
{                                        
        string job;
        object target;
        if (duration < 1) {
                job=me->query_temp("xy");
                if(!( target = find_object("/d/xiangyang/npc/mengge")))
                   target = load_object("/d/xiangyang/npc/mengge"); 
                if (job){
                if (job=="sljob"&&target->query("sljob")<3)
                   target->add("sljob",1);
                if (job=="xsjob"&&target->query("xsjob")<2)
                   target->add("xsjob",1);     
                if (job=="xxjob"&&target->query("xxjob")<4)
                   target->add("xxjob",1);     
                if (job=="gjob"&&target->query("sljob")<1)
                   target->add("gjob",1);
                if (job=="job"&&target->query("job")<5)
                   target->add("job",1);               
                me->delete_temp("xy");
                tell_object(me, HIR"你正在执行的蒙古任务已经被取消了！\n"NOR);
// condition 是 xyjob，不是 xy_job，我没写错 :)
                me->apply_condition("xyjob",random(5)+10);
                }
        return 0;        
        }
        me->apply_condition("xy_job", duration - 1);
        return 1;
}

