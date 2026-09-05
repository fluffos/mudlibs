#include <ansi.h>
#include <skill.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    int i;

    if (!target) target = offensive_target(me);

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「绝剑」只能在战斗中使用。\n");

    if( (int)me->query_skill("linji-zhuang",1) < 150 )
        return notify_fail("你的临济十二庄不够火候，使不出「绝剑」。\n");

    if( (int)me->query_skill("fuliu-jian",1) < 150 )
        return notify_fail("你的回风拂柳剑不够火候，使不出「绝剑」。\n");

    if( me->query_temp("huifeng/jue"))
        return notify_fail("你已经在使用「绝剑」。\n");

    if( (int)me->query("max_neili", 1) < 1000 )
        return notify_fail("你的内力修为不够。\n");

    if( (int)me->query("neili", 1) < 500 )
        return notify_fail("你现在内力不够。\n");

    msg = HIW"$N纵身而起，使出峨嵋绝技「绝剑」心法，陡然气势大增！\n"NOR;
    me->add("neili", -200);
    me->start_busy(2);

    i = me->query_skill("fuliu-jian", 1);
    me->add_temp("apply/parry", i/10);
    me->add_temp("apply/sword", i/10);
    me->add_temp("apply/dodge", i/10);
    me->set_temp("huifeng/jue", 1);
    // 灭、绝互相配合，增加额外攻击
    if (target->query_temp("huifeng/mie"))
    {
           msg+= HIY"$N的灭剑、绝剑互相配合，攻击更胜！\n"NOR;
           me->add_temp("apply/damage",i/10);
           me->set_temp("huifeng/miejue",1);
           me->set_temp("active_buffer/fuliu-jian.juejian/effect4", "攻击伤害+"+i/10+"点");     //效果描述4
    }
    me->set_temp("active_buffer/family","峨嵋派");
    me->set_temp("active_buffer/fuliu-jian.juejian/name", "绝剑");                       //buff名称
    me->set_temp("active_buffer/fuliu-jian.juejian/last_time", time() + (int)me->query_skill("fuliu-jian")/20 );       //持续时间
    me->set_temp("active_buffer/fuliu-jian.juejian/effect1", "招架技能+"+(i/10)+"级");     //效果描述1
    me->set_temp("active_buffer/fuliu-jian.juejian/effect2", "轻功技能+"+(i/10)+"级");     //效果描述2
    me->set_temp("active_buffer/fuliu-jian.juejian/effect3", "剑法技能+"+(i/10)+"级");     //效果描述3
    message_vision(msg, me);
    call_out("remove_effect", (int)me->query_skill("fuliu-jian")/20, me, i);
    return 1;
}

void remove_effect(object me, int i)
{
    if ( !objectp(me) ) return;
    me->delete_temp("huifeng/jue");
    me->add_temp("apply/parry", -i/10);
    me->add_temp("apply/sword", -i/10);
    me->add_temp("apply/dodge", -i/10);
    if (me->query_temp("huifeng/miejue"))
    {
        me->add_temp("apply/damage",-i/10);
        me->delete_temp("huifeng/miejue");
    }
    me->delete_temp("active_buffer/fuliu-jian.juejian");
    if ( sizeof(me->query_temp("active_buffer"))==1 )
        me->delete_temp("active_buffer");
    message_vision(HIW"$N绝剑运使完毕，恢复了平常的攻击。\n"NOR, me);
}

