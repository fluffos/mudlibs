#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
        extra = me->query_skill("shexing-diaoshou",1);
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「刁手蛇形」只能对战斗中的对手使用。\n");

               if( objectp(me->query_temp("weapon")) )
              return notify_fail("你必须空手使用「刁手蛇形」！\n");
     
        if( (int)me->query_skill("shexing-diaoshou", 1) < 200 )
                return notify_fail("你的功夫不够娴熟，无法施展出「刁手蛇形」。\n");
       
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功火候不够。\n");

        if ( (int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够，无法施展出「刁手蛇形」。\n");
        if ( (int)me->query("neili") < 100)
                return notify_fail("你的真气不够，无法施展出「刁手蛇形」。\n");
	          me->add_temp("apply/strength", extra/4);
                 me->add_temp("apply/attack", extra);
me->set_temp("noauto",1);
	me->add("neili", -100);
		 msg = YEL "$N拳招若隐若现，若有若无，神色怪异的缓缓但又什么奇怪的打向$n！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "$N向$n左边打来，但突然打向$n右边！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "$N向$n右边打来，但突然打向$n左边！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N向$n上边打来，但突然打向$n下边！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->delete_temp("noauto");
        me->add_temp("apply/strength", -extra/4);
        me->add_temp("apply/attack", -extra);
        me->start_busy(2);
        return 1;
}
