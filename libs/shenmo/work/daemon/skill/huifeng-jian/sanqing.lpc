// sanqing.c 一剑化三清

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int extra;
        int count;
 	if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("「一剑化三清」只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("「一剑化三清」开始时必须拿着一把剑！\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("huifeng-jian",1) < 100 )
                return notify_fail("你的回风拂柳剑还不到家，无法使用「一剑化三清」！\n");

	extra = me->query_skill("huifeng-jian",1) / 15;
	extra += me->query_skill("huifeng-jian",1) /15;
 
        msg = YEL "$N使出回风拂柳剑绝技「一剑化三清」，一招连环三剑，手中的"+ weapon->name()+  "闪电般攻出第一剑！" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", extra*4);
        me->add_temp("apply/damage", extra*2);

if ((int)me->query_skill("linji-zhuang",1) > 249 && (int)me->query_skill("huifeng-jian",1) > 250 )
{
        msg = HIC "风云庄之第一剑" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY "龙鹤庄之第二剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW "大小庄之第三剑！!" NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        me->start_busy(1);
}
        msg = HIY "只见$N右手一抖，"+ weapon->name()+ HIY"划向$n的左肩！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "第一道剑气"+HIR+"击向$n周身，$n只觉得全身气脉通道阻塞，真气立受干挠！\n"NOR;   
        message_vision(msg, me, target);
  if( !target->is_busy() )
{
        target->start_busy(2);
}
        }
        msg =  HIW "$N凌空一劈，"+ weapon->name()+ GRN"削向$n的右肩！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "第二道剑气"+HIM+"扫中$n的身上,$n只觉得全身一阵急痛！\n"NOR;   
                message_vision(msg, me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra);
        }
        msg = CYN "$N长啸一声，聚功力于左手，使出剑法的最高境界--灭剑，朝$n的胸前劈去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "最后一道剑气"+HIB+"扫中$n的章门穴,$n只觉得全身内力提不起来了！\n"NOR;   
        message_vision(msg, me, target);
        target->add("neili",-extra*4);
        target->add("eff_neili",-extra*4);
        }
        me->add("neili", -300);
        me->add_temp("apply/attack", - extra*4);
        me->add_temp("apply/damage", - extra*2);
        me->start_busy(3);

        return 1;
}

