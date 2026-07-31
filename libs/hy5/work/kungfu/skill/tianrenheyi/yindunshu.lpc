// holyword影遁术

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

        msg = HIC"   $N身影在$n面前消失了!  \n"NOR;

        if ( userp(target) || random(me->query("combat_exp"))>(int)target->query("combat_exp"))
        {

        msg += HIC"$n"HIC"突然发现$N不见了，只好停下了攻势!!\n"NOR;
                target->remove_all_enemy();
                me->remove_all_enemy();
		message_combatd(msg, me, target);
        } else
        {
        msg += HIC"$n"HIC"双目一闪，识破了你的影遁术!\n"NOR;
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
                return notify_fail(HIY"「影遁术」只能对战斗中的对手使用。\n"NOR);

//      if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query_condition("tianrenheyi"))
        return notify_fail("你的念力不足！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

      if( me->query("zhuanfinal/2") !=1 )
        return notify_fail("你没有资格使用这项技能！\n");

	msg = HIY "$N"HIY"足下暗和八卦，步法变幻莫测! \n" NOR;
       msg += HIY"$N"HIY"身形化作数道烟雾！溶和在了四周的环境中!\n"NOR;
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


