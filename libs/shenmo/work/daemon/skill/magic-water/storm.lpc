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
	if((int)me->query("neili")< 1100)
	return notify_fail("你的法力太差了！\n");

        msg = HIW"   呼*****呼  \n"NOR;
        msg += HIW"\n一个冰雪风暴突破天空打向$n"HIW"!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-water", 1);
//对水属性目标无作用
       if ((int)target->query("magicgift")==2)
{
damagic=700+damage;
                target->receive_damage("qi", damagic);
damagic=700+damage;
                target->receive_wound("qi", damagic);
}
//对火属性目标强大
else  if ((int)target->query("magicgift")==1)
{
damagic=2800+damage*5;
                target->receive_damage("qi", damagic);
damagic=2800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=800+damage*3;
target->receive_damage("qi", 800+damage*3);
target->receive_wound("qi", 800+damage);
}

        msg += HIW"$n"HIW"的附近成为了一片冻土!!\n"NOR;
                target->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIW"$n"HIW"飞身跃起，逃过了一难。\n"NOR;
		message_combatd(msg, me, target);
        }
if (target->query("qi") < 3)target->set("qi",1);
if (target->query("eff_qi") < 3)target->set("eff_qi",1);
if (target->query("max_qi") < 3)target->set("max_qi",1);                
if (target->query("jing") < 3)target->set("jing",1);
if (target->query("eff_jing") < 3)target->set("eff_jing",1);
if (target->query("max_jing") < 3)target->set("max_jing",1);                
if (target->query("neili") < 3)target->set("neili",1);
if (target->query("max_neili") < 3)target->set("max_neili",1);
me->add("neili",-450);
if (wizardp(me))
tell_object(me, "基本杀伤为"+damagic+"点。\n" NOR);

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
                return notify_fail(HIW"「冰雪风暴」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-water",1)< 400)
	return notify_fail("你的水系魔法太差了！\n");


	msg = HIW "$N"HIW"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += HIW"$N"HIW"念到 冥王啊，令所有至高无上的力量集于我身！！\n"NOR;
       msg += HIW"$N"HIW"念到 翻起死亡的冷冻风暴！如今籍着新的契约收集冰雪之力到来吧!!\n"NOR;
       msg += HIW"突然变得雪白的天空，对着$n"HIW"所处的地方卷起了冰雪风暴！\n"NOR;
       msg += HIW"  「冰雪风暴」 \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(3);
	return 1;
}


