#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("qishang-quan",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「幽幽魂断」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「幽幽魂断」只能空手使用。\n");		
       
	 if( (int)me->query("neili") < 700 )
                return notify_fail("你的真气不够！\n");

        if( extra < 200 )
                return notify_fail("你的七伤拳火候不够，无法使用「幽幽魂断」！\n");

        if( (int)me->query_skill("shenghuo-shengong",1) < 150 )
                return notify_fail("你的圣火神功修为不够，无法使用「幽幽魂断」！\n");
	
	weapon = me->query_temp("weapon");
// not tiezhang-zhangfa, should be qishang-quan (by xbd)
	extra = me->query_skill("qishang-quan",1) / 20;
	extra += me->query_skill("force",1) /20;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", (extra*10));

        msg = HIW "$N身形回转，怒吼一声，同时使出七伤拳中的精髓，一招[幽幽魂断]连续攻向$n！" NOR;
        	         message_vision(msg, me, target);                
	 msg =  HIW  "藏离诀！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "摧肠诀！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "精失诀！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "三焦诀！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "伤肺诀！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "损心诀！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "意恍惚诀！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -(extra*10));
        me->add("neili", -400);
        me->start_busy(2);

        return 1;
}

