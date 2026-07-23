 // silencer@fengyun 苍龙乍现 命中时，NPC, players 不能 pfm,
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, my_exp,your_exp, lvl, duration;

        lvl= me->query_skill("lansha-shou",1);
        if (lvl<80)
                return notify_fail("你的蓝砂手还不够熟练\n");         
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［苍龙乍现］只能对战斗中的对手使用。\n");
    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");        
                if (extra> 200) extra=200;
        
        extra = me->query_skill("lansha-shou",1);
        me->add_temp("apply/attack", extra);    
        msg = HIR  "$N"+HIR"脚下一转，突然身形飞起，双脚如矫龙般腾空一卷，猛地向$n"+HIR"踢出！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add("neili",-200);
                 me->start_busy(2);
        if (me->query_skill("lansha-shou",1)>188 && random(3)==0 ) {
                target->receive_wound("qi",(extra*5+300));
                message_vision(RED"$n"+RED"一声惨叫，被$N"+RED"踢得狂喷鲜血。\n\n"NOR,me,target);
        }               
        
        my_exp=me->query("combat_exp");
        your_exp=target->query("combat_exp");
        
        if (your_exp>5000000) your_exp = your_exp*3/2;
                
        // lvl = 160/30 = 5+1 = random(6)
   lvl=lvl/30;
        if (lvl<1) lvl=1;
                        
        if ((lvl+1)*random(my_exp)>your_exp) {  
                if (!target->query_temp("till_death/lockup")) {
                        message_vision(HIW"$N"+HIW"凌厉的腿风扫过，$n"+HIW"只觉胸闷气滞，一口真气竟提不上来。\n"NOR,me,target);
                        target->start_busy(5);
                        target->receive_wound("qi",(extra*3));
                        duration = 10+ random(lvl*2);
                        if (your_exp>=5000000)  duration = 6+random(lvl);
                        if (target->query("big_boss") || target->query("boss")) duration = random(4);
                        target->start_call_out( (: call_other, __FILE__, "remove_effect",target:),duration );           
                }
                if (me->query_skill("lansha-shou",1)>149 && !target->is_busy()) {
                                        target->start_busy(3);
                                        message_vision(HIY"$N"+HIY"脚步踉跄，双手捂着前胸,似站立不稳。\n"NOR,target);
                } else if (me->query_skill("lansha-shou",1)>99 && !target->is_busy()) {
                                                target->start_busy(3);
                        message_vision(HIY"$N"+HIY"脚步踉跄，双手捂着前胸,似站立不稳。\n"NOR,target);   
                }
        }
        
        return 1;
}  
void remove_effect(object target)
{
        target->delete_temp("till_death/lockup");
        tell_object(target,HIG"你深吸一口气，真气流转如常。\n"NOR);
}     
