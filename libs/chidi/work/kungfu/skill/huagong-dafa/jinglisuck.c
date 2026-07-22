// jinglisuck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp, skill, top_limit;
    int my_max, tg_max,max_suck;
       if ( target == me ) target = offensive_target(me);
    if( !objectp(target) || environment(me)!=environment(target)||target->query("id") == "mu ren"|| target->query("id") == "tong ren")
        return notify_fail("你要吸取谁的丹元？\n");
        my_max = me->query("max_jingli");
        tg_max = target->query("max_jingli");
    //if ( me->query_temp("sucked") )
    //    return notify_fail("你刚刚吸取过丹元！\n");
     if (target->query("age") < 18)
        return notify_fail("小孩子能有什么精力?\n");
    if( objectp(me->query_temp("weapon")) )
        return notify_fail("你必须空手才能施用化功大法吸人丹元！\n");
    //if( (int)me->query_skill("huagong-dafa",1) < 100 )
      //  return notify_fail("你的化功大法功力不够，不能吸取对方的丹元！n");
    
    skill=(int)me->query_skill("huagong-dafa",1);
    
      if (skill > 10000) skill = 10000;
     if(  skill < 50 || (int)me->query("max_jingli") >= skill*1800)
        return notify_fail("你的化功大法功力不够，只能达到目前的状态！n");
     
    if( (int)me->query("neili",1) < 20 )
        return notify_fail("你的内力不够，不能使用化功大法。\n");
    if( (int)me->query("max_jingli",1) >= 20000000 )
        return notify_fail("你的精力不能靠化功大法吸取。\n");
    if( (int)target->query("max_jingli") < 10 || !living(target) )
        return notify_fail( target->name() +
            "丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");
            if (target->query("no_suck"))   return notify_fail(target->name()+"没有任何精力!\n");
if (target->query("no_suck2"))   return notify_fail(target->name()+"没有任何精力!\n");

        if( (int)target->query("max_jingli") < (int)me->query("max_jingli")/2 )
        return notify_fail( target->name() +
            "的精力修为远不如你，你无法从他体内吸取精元！\n");
    message_vision(
        HIR "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n\n" NOR,
        me, target );
        if ( living(target) )
           { if( !target->is_killing(me) ) target->kill_ob(me); }
        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");
    me->set_temp("sucked", 1);      
      if (( random(sp) > random(dp) ) )
    {
        tell_object(target, HIR "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);
        tell_object(me, HIG "你觉得" + target->name() + "丹元自手掌源源不绝地流了进来。\n" NOR);
        max_suck=(int)target->query("max_jingli") - (int)me->query("max_jingli")/2;
        if (max_suck<1) max_suck=1+random(2);
        else max_suck/=15;
        if (max_suck > 1000 )
            max_suck=1000;
        max_suck=max_suck+skill + target->query("jiali");
        max_suck/=20;
        if ( target->query("max_jingli") < max_suck )
            max_suck=target->query("max_jingli");
        target->add("max_jingli",  -max_suck*3/2 );
        me->add("neili",-max_suck*3/2);
        if (userp(target))
            max_suck/=7;
       if (top_limit>4 )//自己内力>对方内力四倍
             me->add("max_jingli", (int)(max_suck / 5 ) + 1);
       else {
              me->add("max_jingli",  max_suck );
        }
       if ( target->query("max_jingli") <1 )
            target->set("max_jingli",0);
        if ( me->query("neili") <1 )
            me->set("neili",0);
        me->start_busy(1);
        target->start_busy(random(1));
    }
    else
    {   
        message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
        me->start_busy(1);
    }
    call_out("del_sucked", 6, me);
    return 1;
}
void del_sucked(object me)
{
    if ( me && me->query_temp("sucked"))
    me->delete_temp("sucked");
}
