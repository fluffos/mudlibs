#include <ansi.h>
inherit F_SSERVER;

protected int remove_effect_ryb(object me, int amount);

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self";
}

int perform(object me)
{
        object weapon = me->query_temp("weapon");
        int skill;

        if(!me->is_fighting() )
                return notify_fail("「金刚伏魔圈」只能在战斗中使用。\n");

        if((int)me->query_skill("hunyuan-yiqi", 1) < 150 )
                return notify_fail("你的内功等级不够，不能使用「金刚伏魔圈」。\n");

        if ((int)me->query_skill("riyue-bian", 1) < 150 )
                return notify_fail("你的日月鞭法不够娴熟，不能真正发挥「金刚伏魔圈」。\n");

        if ( !objectp(weapon) || weapon->query("skill_type") != "whip" )
/*         || me->query_skill_mapped("whip") != "riyue-bian") */
                return notify_fail("你必须装备鞭类武器才能使用「金刚伏魔圈」。\n");

        if ((int)me->query("neili") < 500 )
                return notify_fail("你现在内力太弱，不能使用「金刚伏魔圈」。\n");

        if ( (int)me->query_temp("ryb_fumo") )
                return notify_fail("你正在使用「金刚伏魔圈」。\n");

        message_vision(HIG "$N这时一声高喝，脸上殷红如血，僧袍都鼓了起来，手中"+weapon->name()+"急速转动，渐渐收短，\n"+
                           "守御相当严密。"+weapon->name()+"似有无穷弹力，似真似幻，无论敌人怎么变招抢攻，总是被弹了出去。\n"NOR, me);
        me->start_busy(1);
        me->start_perform(1,"「金刚伏魔圈」");
        skill = me->query_skill("riyue-bian",1)/2;
        me->add("neili", -skill/2);

        me->add_temp("apply/armor",  skill);
        me->add_temp("apply/parry",  skill);
        me->add_temp("apply/dodge",  skill);
        me->add_temp("apply/strength",  skill/10);
        me->set_temp("active_buffer/family","少林派");
        me->set_temp("active_buffer/riyue-bian.fumoquan/name", "金刚伏魔圈");                  //buff名称
        me->set_temp("active_buffer/riyue-bian.fumoquan/last_time", time() + skill/3+3);       //持续时间
        me->set_temp("active_buffer/riyue-bian.fumoquan/effect1", "护甲防御+"+skill+"点");     //效果描述1
        me->set_temp("active_buffer/riyue-bian.fumoquan/effect2", "招架技能+"+skill+"级");     //效果描述2
        me->set_temp("active_buffer/riyue-bian.fumoquan/effect3", "轻功技能+"+skill+"级");     //效果描述3
        me->set_temp("active_buffer/riyue-bian.fumoquan/effect4", "后天膂力+"+(skill/10)+"点");  //效果描述4
        me->set_temp("ryb_fumo", 1);

        call_out("remove_effect_ryb", skill/3+3, me,skill);
        return 1;
}

protected int remove_effect_ryb(object me, int amount)
{
        int skill;
        if (!me)	return 0;
        //skill = me->query_skill("riyue-bian");
 				skill=amount;
        me->add_temp("apply/strength",-skill/10);
        me->add_temp("apply/parry", -skill);
        me->add_temp("apply/dodge", -skill);
        me->add_temp("apply/armor",  -skill);
        me->delete_temp("active_buffer/riyue-bian.fumoquan");
        if ( sizeof(me->query_temp("active_buffer"))==1 )
        	me->delete_temp("active_buffer");
        me->delete_temp("ryb_fumo");
        if(living(me) && !me->is_ghost())
                message_vision(GRN"良久，$N所使金刚伏魔圈的威力渐渐平息，一切又恢复了原状。\n"NOR, me);
        return 0;
}

