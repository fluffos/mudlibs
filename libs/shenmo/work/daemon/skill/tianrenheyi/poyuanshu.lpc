// holyword破元术

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

        msg = HIC"$N哼然冷笑，一股旋风将$n的招数全部化解! \n"NOR;

        if ( userp(target) || random(me->query("combat_exp"))>(int)target->query("combat_exp"))
        {

       msg += HIC"$n的内力有如石沉大海!完全消失了! \n"NOR;
                if (!target->is_busy())
                target->start_busy(2);
                target->set("neili",10);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIC"$n"HIC"双目一闪，识破了你的破元术!\n"NOR;
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
                return notify_fail(HIY"「破元术」只能对战斗中的对手使用。\n"NOR);

//      if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query_condition("tianrenheyi"))
        return notify_fail("你的念力不足！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query("zhuanfinal/5") !=1 )
        return notify_fail("你没有资格使用这项技能！\n");

	msg = HIR "$N"HIR"全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n" NOR;
       msg += HIR"$N"HIR"身法陡然加快，右掌直出，猛地对准$n的膻中大穴按了上去\n"NOR;
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


