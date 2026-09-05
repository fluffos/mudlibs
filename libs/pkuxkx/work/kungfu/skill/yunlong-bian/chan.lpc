// chan.c 日月鞭法「缠绕」诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        if(!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n"); 
        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_skill("whip") < 100  ) 
                return notify_fail("你的鞭法不够熟练。\n");                
	      msg = WHT "$N" WHT "使出云龙鞭法「缠」字诀，连挥" + weapon->name() +
              WHT"企图把$n"  WHT "的全身缠住。\n" NOR;

        me->start_busy(2);
        if (random(me->query_skill("whip")) > target->query_skill("parry")* 3/ 5) 
        {
					msg += HIY "结果$p" HIR "顿时被$P" HIR "的鞭势牢牢缠住，"
                       "攻得措手不及！\n" NOR;
					target->start_busy((int)me->query_skill("whip") / 40 + 1);
				} 
				else
        {
					msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，并没有上"
                "当。\n" NOR;
				}
				me->add("neili", -100);
        message_vision(msg, me, target);

        return 1;
}

