// guangming.c

#include <ansi.h>

int exert(object me, object target)
{
            int gm_skill,skill,age,dur;
            if (me->query("family/family_name")!="日月神教")
            {
                return 0;
            }
            if (me->query("betrayer")>3)
            {
                return 0;
            }
            if (me->is_busy())
            {
                tell_object(me,"你正忙着呢。\n");
                return 1;
            }
            if( me->is_fighting())
            {
                tell_object(me,"你在战斗中无法运转大光明心法。\n");
                return 1;
            }
            if (me->query("eff_jing")<me->query("max_jing"))
            {
                tell_object(me,"你现在精血不足，无法施展大光明心法。\n");
                return 1;
            }
            if (me->query("eff_qi")<me->query("max_qi"))
            {
                tell_object(me,"你现在气血不足，无法施展大光明心法。\n");
                return 1;
            }
            if (me->query_skill("riyue-shengong",1)<150)
            {
                tell_object(me,"你的日月神功境界太低，无法施展大光明心法。\n");
                return 1;
            }
            if (me->query_skill("kuihua-shengong",1)<800)
            {
                tell_object(me,"你的葵花神功境界太低，无法施展大光明心法。\n");
                return 1;
            }
            if (me->query_skill("daguangming-xinfa",1)<150)
            {
                tell_object(me,"你的大光明心法境界太低，无法施展大光明心法。\n");
                return 1;
            }
            if( (int)me->query("neili") < 1000 )
            return notify_fail("你的真气不够。\n");
/*            age=(int)me->query("age");
            if (age>80)
            {
                age=80+(age-80)/2;
            }
            gm_skill=(int)me->query_skill("daguangming-xinfa",1)/2-age; */
            gm_skill=(int)me->query_skill("daguangming-xinfa",1)/2;
            if (me->query_temp("daguangming/apply"))
            {
                tell_object(me,"你正在运转大光明心法。\n");
                return 1;
            }
            if (gm_skill<0)
            {
                gm_skill=0;
                tell_object(me,"你的大光明心法境界太低，无法施展大光明心法。\n");
                return 1;
            }
            skill=(int)me->query_skill("kuihua-shengong",1)/40;
            //skill=(int)me->query_skill("xixing-dafa",1)/50;
            message_vision(HIY"$N开始按照大光明心法的行气路线运转真气，片刻之后，脸上增加了一抹嫣红。\n"NOR,me);
            me->set_temp("daguangming/apply",1);
            if (!me->query_temp("daguangming/minus"))
            {
                me->add_temp("apply/constitution",-8);
                me->add_temp("apply/intelligence",-8);
                me->set_temp("daguangming/minus",1);
                me->set_temp("active_debuff/kuihua-shengong.guangming/name", "大光明心法");                            //buff名称
                me->set_temp("active_debuff/kuihua-shengong.guangming/effect1", "后天根骨-8点");                       //效果描述1
                me->set_temp("active_debuff/kuihua-shengong.guangming/effect2", "后天悟性-8点");                       //效果描述2
            }
//            dur=to_int(sqrt(to_float(me->query_skill("kuihua-shengong",1))));
//            me->apply_condition("daguangming",dur);
            me->set_temp("daguangming/qi",gm_skill*skill);
            me->set_temp("daguangming/jing",gm_skill*skill/5*3);

            me->add_temp("apply/max_jing", gm_skill*skill/5*3);
            me->add_temp("apply/max_qi", gm_skill*skill);            
            me->set("max_jing", me->query_max_jing() );
            me->add("eff_jing",gm_skill*skill/5*3);
            me->add("jing",gm_skill*skill/5*3);
            me->set("max_qi", me->query_max_qi() );
            me->add("eff_qi",gm_skill*skill);
            me->add("qi",gm_skill*skill);
            me->add("neili",-100);
            me->set_temp("active_force_buffer/kuihua-shengong.guangming/name", "大光明心法");                            //buff名称
//            me->set_temp("active_force_buffer/kuihua-shengong.guangming/last_time", time() + dur*10 );                   //持续时间
            me->set_temp("active_force_buffer/kuihua-shengong.guangming/effect1", "最大气血+"+(gm_skill*skill)+"点");    //效果描述1   
            me->set_temp("active_force_buffer/kuihua-shengong.guangming/effect2", "最大精神+"+(gm_skill*skill/5*3)+"点");//效果描述2
            return 1;
}

void remove_effect(object me)
{
            int max_qi,max_jing,refresh_qi, last_time;
            if (!me->query_temp("daguangming/apply")) return;
            max_qi=(int)me->query_temp("daguangming/qi");
            max_jing=(int)me->query_temp("daguangming/jing");
            me->add_temp("apply/max_jing", -max_jing);
            me->add_temp("apply/max_qi", -max_qi);
            
            if (me->query("eff_qi")>max_qi)//仍然处于加气状态
            {
                me->add("eff_qi",-max_qi);
            }
            if (me->query("qi")>max_qi)
            {
                me->add("qi",-max_qi);
            }
            me->set("max_qi",me->query_max_qi());//不处于加气状态不回复
            if (me->query("eff_jing")>max_jing)
            {
                me->add("eff_jing",-max_jing);
            }
            if (me->query("jing")>max_jing)
            {
                me->add("jing",-max_jing);
            }
            me->set("max_jing",me->query_max_jing());
            me->delete_temp("daguangming/apply");
            tell_object(me, CYN+"你的大光明心法运转一圈，渐渐恢复平静。\n"NOR);
            me->delete_temp("active_force_buffer/kuihua-shengong.guangming");
            me->delete_temp("active_force_buffer/riyue-shengong.guangming");
            me->delete_temp("active_force_buffer/xixing-dafa.guangming");
}