// miejian.c  回风拂柳剑  (灭剑)
//create bye cuer
// Modified by iszt@pkuxkx, 2007-03-23

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

void end(object me, object target,int damage);

int perform(object me, object target)
{
    int damage, pflv;
    string msg;
    object weapon;

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query("sword") != 1)
        return notify_fail("你还没有学会回风拂柳剑的特殊攻击。\n");

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("灭剑攻击只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
/*    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword") */
        return notify_fail("你右手无剑，如何使得剑法绝招？\n");

    if( (int)me->query_skill("fuliu-jian", 1) < 80 )
        return notify_fail("你的回风拂柳剑不够娴熟，不会使用「灭剑」。\n");

    if( (int)me->query_skill("linji-zhuang", 1) < 30 )
        return notify_fail("你的临济十二庄不够高，不能用内力使出灭剑。\n");

    if( (int)me->query("neili", 1) < 200 )
        return notify_fail("你现在内力太弱，不能使出灭剑。\n");

    if( target->query_temp("huifeng/mie")==1 ) 
        return notify_fail("对方已被你「灭剑」心法困扰！\n");

    msg = HIW "\n$N飘身而起，使出峨嵋绝技「灭剑」心法，顿时剑意空灵飘逸，似万千柳絮飞舞，又如和风阵阵拂过。\n" NOR;

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "峨嵋派")  pflv=0;
	if (pflv>5) pflv=5;

    me->add("neili", -100);
    //B-
    if( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target) )
    {  
        msg += CYN"$p虽已加倍提防，但仍感攻势频频收挫，被攻了个措手不及！\n"NOR;            
        F_KUNGFU->hit_busy( "confuse", me->query_skill("fuliu-jian",1)/20, target );
        me->add("neili",-100);            
        damage = me->query_skill("fuliu-jian",1);
        damage = 0- damage/10 - random(damage/10);
		if (pflv>=4)
			damage = damage * (pflv-2) ;

        if(!target->query_temp("apply/attack"))
            target->set_temp("apply/attack", damage);
        else 
            target->add_temp("apply/attack", damage);

        if(!target->query_temp("apply/defense"))
            target->set_temp("apply/defense", damage);
        else 
            target->add_temp("apply/defense", damage);

        target->set_temp("huifeng/mie",1);
        target->set_temp("active_debuff/fuliu-jian.miejian/name", "灭剑");                       //buff名称
        target->set_temp("active_debuff/fuliu-jian.miejian/last_time", time() + me->query("int") );       //持续时间
        target->set_temp("active_debuff/fuliu-jian.miejian/effect1", "攻击命中-"+(damage*(-1))+"级");     //效果描述1
        target->set_temp("active_debuff/fuliu-jian.miejian/effect2", "防御躲闪-"+(damage*(-1))+"级");     //效果描述2
        call_out("end", me->query("int"), me, target, damage);
    }                                                                                                
    else
    { 
        msg += CYN"$p沉着应战，一点都不受影响！\n"NOR;                    
    }
    message_vision(msg, me, target);
    me->start_busy(2);
    return 1;
}

void end(object me, object target,int damage)
{
    if ( !objectp(target) ) return;
    target->delete_temp("huifeng/mie");
//	if ( !target->is_busy() )
    target->start_busy(1);
    target->add_temp("apply/attack", 0 - damage);
    target->add_temp("apply/defense", 0 - damage);
    target->delete_temp("active_debuff/fuliu-jian.miejian");
    if ( target->is_ghost() || !objectp(me) ) return;
    message_vision(HIY "\n\n$N渐渐适应了$n的剑路，攻守自如多了。\n" NOR, target, me); 
}


