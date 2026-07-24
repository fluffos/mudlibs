// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a;
	object weapon;
        int ap, dp;
        int damage;	
	
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("太极剑法「连」字诀只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("taiji-jian", 1) < 50 )
		return notify_fail("你的太极剑法不够娴熟，不能用「连」字诀。\n");

	if( (int)me->query_skill("taiji-shengong", 1) < 60 )
		return notify_fail("你的太极神功不够娴熟，不能使用「连」字诀。\n");

	extra = me->query_skill("taiji-jian",1) / 20;
	extra += me->query_skill("taiji-shengong",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 300);
	msg = HIR  "$N运起［太极神功］，同时使出［太极剑法中］的「连」字诀，手中的"+ weapon->name() +" 一招连着一招画起圈来，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 16) a=16;


	for(i=0;i<a;i++)
	{
       if (random(2)==0 && !target->is_busy()) target->start_busy(2);
		
	msg = HIY "$N用剑画了一个圈，一剑又连了上来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -300);
	me->add("neili", - 20 * i);
	me->start_busy(3);
	

    if( (int)me->query_skill("taiji-jian", 1) > 200 )
    {
        msg = HIG "$N使出太极剑法「缠」字诀，剑意圈转，连绵不绝，连递数个虚招企图扰乱$n的攻势。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0) {
                msg += HIR " 结果$p被$P闹个手忙脚乱，惊慌失措，呆在当场，不知如何应对！\n" NOR;
                target->start_busy(6);
        } else {
                msg += "可是$p看破了$P的企图，镇定逾恒，全神应对自如。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
    
    
    if( (int)me->query_skill("taiji-jian", 1) > 300 )
    {
    	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 300);
    msg = HIC"$n看到剑光上一闪，剑光随着$n的上身画了第一个圈！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n看到剑光中一闪，剑光随着$n的中段画了第二个圈！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n看到剑光下一闪，剑光随着$n的下身画了第三个圈！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -300);

    }
}

    if( (int)me->query_skill("taiji-jian", 1) > 600 )
    {
   msg = HIW "$N" HIW "一声冷哼，手中" + weapon->name() +
              HIW "一振，剑身微颤，声若龙吟，剑光携着数个剑花"
              "同时洒向$n" HIW "。\n" NOR;

        
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        if ((int)target->query("shen") < 0) ap += ap / 5;

        me->start_busy(3);
        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                damage = me->query_skill("sword",1)+me->query_skill("taiji-jian",1)+500;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "只听$n" HIR "一声惨叫，被这一剑穿胸而入，顿"
                "时鲜血四处飞溅。\n" NOR;
        } else
        {
                msg += HIC "可$n" HIC "却是镇定逾恒，一丝不乱，"
                       "全神将此招化解开来。\n" NOR;
        }
        message_combatd(msg, me, target);

}	
	return 1;
}

