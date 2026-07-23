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

        msg = HIM"   轰(***→)隆  \n"NOR;
        msg += HIC"\n一道狂雷攻破天空打向$n"HIC"!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-ice", 1);
//对气属性目标无作用
       if ((int)target->query("magicgift")==3)
{
damagic=800+damage;
                target->receive_damage("qi", damagic);
damagic=800+damage;
                target->receive_wound("qi", damagic);
}
//对土属性目标强大
else  if ((int)target->query("magicgift")==4)
{
damagic=2800+damage*5;
                target->receive_damage("qi", damagic);
damagic=2800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=900+damage*3;
target->receive_damage("qi", 900+damage*3);
target->receive_wound("qi", 900+damage);
}

        msg += HIR"$n"HIR"的附近一片电闪雷鸣!!\n"NOR;
                target->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIG"$n"HIG"飞身跃起，逃过了一难。\n"NOR;
		message_combatd(msg, me, target);
        }

if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
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
                return notify_fail(HIC"「狂雷术」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-ice",1)< 400)
	return notify_fail("你的气系魔法太差了！\n");


	msg = HIC "$N"HIC"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += HIC"$N"HIC"念到 芝．艾夫．基斯，背负着神灵之血、盟约和祭坛，我以圣灵之名命令落雷吧!!\n"NOR;
       msg += HIC"$N"HIC"念到  吼叫吧，雷的精灵啊，穿透吧，上天的闪电啊!\n"NOR;
       msg += HIC"$N"HIC"念到  充满斗志的人，凭着手中之剑，把我所有的愤怒都发泄出来吧！！！！！!\n"NOR;
       msg += HIC"突然变得漆黑的天空，对着$n"HIC"所处的地方落下了大量的狂雷！\n"NOR;
       msg += HIR"  「狂雷术」 \n"NOR;
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


