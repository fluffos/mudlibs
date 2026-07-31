// suodi.c 飞天御剑流.抄刃止刃

#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("飞天御剑流.抄刃止刃只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 60)
   return notify_fail("你的杀意心法火候不够。\n");

                
	if((int)me->query_skill("huoxinliu-jianfa",1) < 60)
		return notify_fail("你的神谷活心流的修为不够, 不能使用这一绝技 !\n");
	if((int)me->query_skill("blade") < 30)
		return notify_fail("你的刀法修为不够， 目前不能使用! \n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的内力不够。\n");

        msg = HIW "$N双手交叉,以手背抵挡$n的武器,使出了这至高防御止刃术。\n";

if (!target->is_busy())
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIW " 结果$p被$P一把架住动弹不得！\n" NOR;
                target->start_busy( (int)me->query_skill("huoxinliu-jianfa",1) / 60 + 2 );
        } else {
                msg += HIC"可是$p看破了$P的企图，收回了手中的武器。\n"NOR NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
	me->add("neili", - 60);
        if(!target->is_fighting(me)) target->fight_ob(me);
}
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
         {
         attack_time = random((int)me->query_skill("huoxinliu-jianfa", 1) / 30);
        msg = HIC "$N双手交叉,以手背抵挡武器,使出了高防御止刃术。\n";
        target->start_busy(1);
        message_combatd(msg, me, target);
  
        for(i = 0; i < attack_time; i++){
         msg = HIM "$N以刀柄刺对手怀内,使出了至高攻击抄刃术！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                                        }
         }
	me->add("neili", - 30*i);
                me->start_busy(3);
        return 1;
}

