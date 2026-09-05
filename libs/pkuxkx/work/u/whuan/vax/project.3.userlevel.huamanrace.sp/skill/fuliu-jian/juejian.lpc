//juejian.c 来自 sanjue.c 达摩三绝剑

#include <ansi.h>

inherit NPC;

int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) 
		return notify_fail("你要攻击谁。\n");

       if( me->query("id") != DADIZI_D->query_name("emei") ) 
		return notify_fail("你不是峨嵋派大弟子，没有得到真传，无法使用「绝剑」。\n");
		
      if( (!objectp(weapon = me->query_temp("weapon"))
      || (string)weapon->query("skill_type") != "sword") )
                return notify_fail("你必须使剑才能使「绝剑」。\n");

	if( me->query_skill_mapped("sword")!="damo-jian")
		return notify_fail("你必须使达摩剑才能施展「绝剑」。\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「绝剑」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("fuliu-jian", 1) < 300 )
                return notify_fail("你的回风拂柳剑不够娴熟，不会使用「绝剑」。\n");

        if( (int)me->query_skill("linji-zhuang", 1) < 300 )
                return notify_fail("你的临济十二庄等级不够，不能使用「绝剑」。\n");

        if( (int)me->query("neili") < 3000 )
                return notify_fail("你的内力不足，无法使用「绝剑」。\n");

        if( (int)me->query("eff_qi")*2 > (int)me->query("max_qi") )
                return notify_fail("对方并没有置你于死地的意思，身为出家人，「绝剑」这种惨酷的招数还是不要用为好。\n");
				
        me->start_busy(5+random(5) );
		me->set("jiali",900) // 也许会比较过分，待观察…… dewolf 2005.12

        msg = CYN "$N捂住伤口，想起灭绝师太的教导以及峨嵋的灭门危险，娇咤一声：「我与你不共戴天！」\n说将运气全身功力，使出不传秘技「绝剑」，闪电般功向$n。\n" NOR;
        message_vision(msg, me, target);
		
        COMBAT_D->do_attack(me, target, weapon);
        if( (int)target->query("qi") < 0 ) 
		{
			me->set("jiali",0);
			me->set("neili",0);
            return 1;
		}
        COMBAT_D->do_attack(me, target, weapon);
        if( (int)target->query("qi") < 0 ) 
		{
			me->set("jiali",0);
			me->set("neili",0);
            return 1;
		}

        COMBAT_D->do_attack(me, target, weapon);
		
		me->set("jiali",0);
		me->set("neili",0);
        return 1;

}
