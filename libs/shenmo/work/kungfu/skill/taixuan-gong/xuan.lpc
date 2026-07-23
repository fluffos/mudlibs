
#include <ansi.h>

inherit F_SSERVER;

#define XUAN "「" HIW "太玄激劲" NOR "」"
 
int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i, ap, dp,t;
        object weapon;

        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(XUAN "只能对战斗中的对手使用。\n");
        
	if ((int)me->query("neili") < 800)
		return notify_fail("你的真气不够，无法施展" XUAN "！\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("你的内力修为还不足以使出" XUAN "。\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功火候不够，难以施展" XUAN "！\n");

	if ((lvl = (int)me->query_skill("taixuan-gong", 1)) < 240)
		return notify_fail("你的太玄功还不够熟练，无法使用" XUAN "！\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得太玄神功深奥之极，一时间难以领会。\n");
                
             weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用！\n");	

             if (me->query_skill_mapped("unarmed") != "taixuan-gong"
                 || me->query_skill_prepared("unarmed" != "taixuan-gong"))
                       return notify_fail("你没有准备太玄功，无法使用" XUAN "。\n");

        if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "\n霎时间$N" HIW "只觉思绪狂涌，当即闭上双眼，再不理睬$n"
              HIW "如何招架，只管施招攻出！\n此时侠客岛石壁上的千百种招"
              "式，转眼已从$N" HIW "心底传向手足，尽数向$n" HIW "袭去！\n" NOR;

	message_vision(msg, me, target);
	me->add("neili", -600);
        ap = me->query_skill("taixuan-gong, 1");
        dp = target->query_skill("dodge", 1);
       
        if (ap / 3 + random(ap) > dp)
                  count = ap / 8;
  
        else count = 0;
t=9;
if (me->query("double_attack"))
t=4;
        me->add_temp("apply/attack", 80);
me->add_temp("apply/damage", 800);
        for (i = 0; i < t; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(3);

        	COMBAT_D->do_attack(me, target, 0, i * 2);
        }
        me->add_temp("apply/damage", -800);
        me->add_temp("apply/attack", -80);
	me->start_busy(2);
	return 1;
}

