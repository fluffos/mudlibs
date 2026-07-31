// holyword定身术

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

	if((int)me->query("neili")< 1100)
	return notify_fail("你的内力太差了！\n");

        msg = HIW "$N左牵右引，$n" HIW "如身处漩流，连续转了好几个圈。\n" NOR;

        if ( userp(target) || random(me->query("combat_exp"))>(int)target->query("combat_exp"))
        {

       msg += HIC"结果$n在$N的攻击下,不知所措！ \n"NOR;
                if (!target->is_busy())
                target->start_busy(6);
                target->set("neili",10);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIC"$n"HIC"双目一闪，识破了你的定身术!\n"NOR;
		message_combatd(msg, me, target);
        }
me->add("neili",-150);

	return 1;
	
}
int perform(object me, object target)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIY"「定身术」只能对战斗中的对手使用。\n"NOR);

//      if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query_condition("tianrenheyi"))
        return notify_fail("你的念力不足！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query("zhuanfinal/4") !=1 )
        return notify_fail("你没有资格使用这项技能！\n");

    if( me->query("gender") == "男性")
               {msg = YEL
"$N提起真气，意态飘逸,一招落神凌波,如入无人之境！\n" NOR;}
        else   {msg = YEL 
"$N提起真气，施展凌波微步，仿如洛神再生，仙女下凡！\n" NOR;}

       msg += HIG"$N"HIG"面含微笑，轻轻一格，已将天下所有进攻招数全部封死。\n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
        me->apply_condition("tianrenheyi",3);
	me->start_busy(3);
	return 1;
}


