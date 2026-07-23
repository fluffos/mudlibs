// 闪电术

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

	spells = me->query_skill("spells");
	if((int)me->query("neili")< 500)
	return notify_fail("你的法力太差了！\n");

        msg = HIC"   $N身影在$n面前消失了!  \n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp"))
        {

        msg += HIC"$n"HIC"突然发现$N不见了，只好停下了攻势!!\n"NOR;
                target->remove_all_enemy();
                me->remove_all_enemy();
		message_combatd(msg, me, target);
//		COMBAT_D->report_status(target);
        } else
        {
        msg += HIC"$n"HIC"双目一闪，识破了你的隐身术!\n"NOR;
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
                return notify_fail(HIC"「隐身术」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 500)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-ice",1)< 100)
	return notify_fail("你的气系魔法太差了！\n");

       if ((int)me->query_condition("inv_busy"))  
       return notify_fail("你才用过隐身术！要过一会才能用！\n");



	msg = HIC "$N"HIC"身形一闪，口中喃喃地念著咒文，\n" NOR;
       msg += HIC"$N的动作突然变的慢了下来，在天蓝色的光芒下, $N的身体慢慢变透明起来！\n"NOR;
       msg += HIC"  「隐身术」 \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->apply_condition("inv_busy",8+random(8));
	me->start_busy(3);
	return 1;
}


