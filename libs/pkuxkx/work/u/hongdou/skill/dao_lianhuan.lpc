//riyue-dao 连环三刀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
	int damage,dao;
	object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「连环三刀」只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "blade")
	        return notify_fail("你没拿刀,怎么能使出刀的绝招呢?\n");

	me->delete_temp("riyue/usingdao");
        if (objectp(weapon = me->query_temp("weapon"))
        && (string)weapon->query("id") == "riyue dao")
		me->add_temp("riyue/usingdao",1);
        
	if (objectp(weapon = me->query_temp("secondary_weapon"))
        && (string)weapon->query("id") == "riyue dao")
		me->add_temp("riyue/usingdao",1);
	dao = (int)me->query_temp("riyue/usingdao");
        
	if( (int)me->query_skill("riyue-dao", 1) < 100 )
                return notify_fail("你的日月刀法不够娴熟，不会使用「连环三刀」。\n");
	if((int)me->query("neili") < 50)
              return notify_fail("你的内力不够!\n");
	if( me->is_busy())
		return notify_fail("你正忙着呢！\n");
        msg = HIR "$N杀红了眼，长啸一声，对着$p使出日月刀法的「连环三刀」。\n第一刀！\n";
	
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/(3 + dao) ) 
	{
                msg += "结果在$p身上划出了一道血淋淋的口子。\n" NOR;
		
		damage = (int)me->query_skill("riyue-dao", 1);

                damage = damage/2;

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage/10);

        } else {
                msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);
	me->start_busy(3);
	target->start_busy(3);
	call_out("lianhuan2",2,me);
	return 1;
}

int lianhuan2(object me,object target)
{
        string msg;
	int damage,dao;
	object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「连环三刀」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("riyue-dao", 1) < 100 )
                return notify_fail("你的日月刀法不够娴熟，不会使用「连环三刀」。\n");
	if((int)me->query("neili") < 50)
              return notify_fail("你的内力不够!\n");
	dao = (int)me->query_temp("riyue/usingdao");

        msg = HIR "第二刀！\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2/(3 + dao) ) 
	{
                msg += "结果在$p身上砍出一道深可见骨的伤口。\n" NOR;
		
		damage = (int)me->query_skill("riyue-dao", 1);

                damage = damage*2/3;

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage/10);

        } else {
                msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);
	call_out("lianhuan3",1,me);
	return 1;
}		

int lianhuan3(object me,object target)
{
        string msg;
	int damage,dao;
	object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「连环三刀」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("riyue-dao", 1) < 100 )
                return notify_fail("你的日月刀法不够娴熟，不会使用「连环三刀」。\n");
       if((int)me->query("neili") < 50)
              return notify_fail("你的内力不够!\n");
	dao = (int)me->query_temp("riyue/usingdao");

        msg = HIR "第三刀！！\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") * 3/(3 + dao)) 
	{
                msg += "刀锋在$p身上狠狠划过，鲜血直喷出来。\n" NOR;
		
		damage = (int)me->query_skill("riyue-dao", 1);

                damage = damage*(3+dao)/2;

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage/10);

        } else {
                msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(10);
        }
        message_vision(msg, me, target);
	return 1;
}


