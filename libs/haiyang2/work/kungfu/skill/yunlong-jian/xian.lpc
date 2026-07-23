// xian.c  云龙三现

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	int extra;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("云龙三现只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
		
	if( (int)me->query_skill("yunlong-jian", 1) < 50 )
		return notify_fail("你的云龙剑法不够娴熟，不会使用「云龙三现」。\n");
	                        
	if( (int)me->query_skill("yunlong-shengong", 1) < 50 )
		return notify_fail("你的云龙神功不够高，不能。\n");
			
	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用「云龙三现」。\n");
			
	extra = me->query_skill("yunlong-jian",1) / 15;
	extra += me->query_skill("yunlong-jian",1) /15;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
if ((int)me->query_skill("yunlong-jian",1) > 249 && (int)me->query_skill("yunlong-shengong",1) > 250)
{
        msg = HIB "云龙听梵音第一剑" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "我心化云龙之第二剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIG "高处不胜寒之第三剑！!" NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        me->start_busy(1);
}
	msg = CYN "$N微微一笑，猛吸一口气,欲使出以气驭剑绝技攻击$n。"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "第一道剑气"+HIR+"击向$n周身，$n只觉得全身气脉通道阻塞，真气立受干挠！\n"NOR;   
        message_vision(msg, me, target);
  if( !target->is_busy() )
{
        target->start_busy(3);
}
        }
      	msg = HIR"只见$N手中剑光幻作一条金龙,腾空而起,倏的罩向$n！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "第二道剑气"+HIM+"扫中$n的身上,$n只觉得全身一阵急痛！\n"NOR;   
                message_vision(msg, me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra);
        }
        msg = HIG  "剑若游龙，直上而下，只见一条青龙向$n串区！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "最后一道剑气"+HIB+"扫中$n的章门穴,$n只觉得全身内力提不起来了！\n"NOR;   
        message_vision(msg, me, target);
        target->add("neili",-extra*4);
        target->add("eff_neili",-extra*4);
        }
	me->add("neili",-300);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(3);
	return 1;
}
