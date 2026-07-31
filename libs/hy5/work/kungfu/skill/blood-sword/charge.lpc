//XXDER/TIE
//charge.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int extra,damage;
    string msg;

            if(!target) target=offensive_target(me);
	     extra=me->query_skill("blood-sword",1);
            if(extra<50) return notify_fail("你的［血衣剑法］还不够精熟！\n");
            if(!target
       	||!target->is_character()
	       ||!me->is_fighting(target) )
            return notify_fail("［平青眼］只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);

  	     weapon=me->query_temp("weapon");
	     extra/=2;
	     extra+=me->query_skill("move")/2;

            msg=HIC"\n$N平平地举起" + weapon->query("name") + HIC"，剑尖向下微斜往左方微偏，冷然道：“我来了。”\n"NOR;
            msg+=HIC"\n$N的身影突然从人的肉眼中消失了！"NOR;
            me->add_temp("apply/damage",extra/5);
            me->add_temp("apply/attack",extra/5);
            damage=COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);
            me->add_temp("apply/attack",-extra/5);
            me->add_temp("apply/damage",-extra/5);
            if(damage>1) 
            {
            me->start_busy(2);
            return 1;
            }

            msg=HIR"$N一击不中，马上抽回剑身，踏前一步又向$n刺去！"NOR;
            me->add_temp("apply/damage",extra/2);
            me->add_temp("apply/attack",extra/2);
            damage=COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);
            me->add_temp("apply/attack",-extra/2);
            me->add_temp("apply/damage",-extra/2);
            if(damage>1) 
            {
            me->start_busy(2);
            return 1;
            }

            msg=HIR"$N后脚尚未着地，手中的" + weapon->query("name") + HIR"又闪电般地向$n刺去！"NOR;
            me->add_temp("apply/damage",extra);
            me->add_temp("apply/attack",extra);
            damage=COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);
            me->add_temp("apply/attack",-extra);
            me->add_temp("apply/damage",-extra);
            me->start_busy(2);
            return 1;
}

