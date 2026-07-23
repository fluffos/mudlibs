// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
int extra;
	object weapon;
	string msg;
	extra = me->query_skill("shedao-qigong",1);
	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("万蛇决只能对战斗中的对手使用。\n");

	if( !target || !target->is_character() )
		return notify_fail("万蛇决只能对对手使用。\n");

        if ((int)me->query_skill("shedao-qigong", 1) < 200 )
		return notify_fail("你的蛇岛奇功等级不够, 不能用此绝招！\n");

        if ((int)me->query_skill("shenlong-xinfa", 1) < 200 )
        return notify_fail(RED"你神龙心法火候不够，使不出「龙形八打」。\n"NOR);

        if (me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("你没有激发神龙心法为内功，无法施展。\n");
                
	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("你的内力不够，不能喷毒。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff"
	)
            return notify_fail("你使用的武器不对。\n");

        me->add("neili", -200);
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",2*extra);
        msg = HIY "$N使出神龙岛的绝技万蛇决!\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG "$N仰天长啸，高声狂叫：不死神龙，唯我不败！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIW "$N仰天长啸，高声狂叫：不死神龙，唯我不败！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

	me->add_temp("apply/attack",-extra);
	 me->add_temp("apply/damage",-2*extra);

	msg = HIR "$N口中念念有词，顷刻之间武功大进，高高跃起，$P手中巨毒的蛇血，向$n全身喷去!\n";

        if( (random(me->query("combat_exp"))) >(int)target->query("combat_exp")/3 )
        {
		msg += MAG "结果$p被巨毒的蛇血喷中、n" NOR;
	msg += HIR "$p只闻到一阵头昏，口中吐出一大口鲜血。\n" NOR;
	msg += HIC "$p金星乱冒，犹如有万条金龙在眼前舞动。。\n" NOR;
	message_combatd(msg, me, target);

         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3)
        {                
        msg = HIW "第一道毒气"+HIR+"击中$n右身，！\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",10);
        }
        if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
        {                
        msg = HIC "第二道毒气"+HIM+"扫中$n的左身！\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",10);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 3)
        {                
        msg = MAG "最后一道毒气"+HIB+"扫中$n的上身!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",10);
        }
	target->apply_condition("ill_fashao",20);
	target->apply_condition("ill_kesou",20);
	target->apply_condition("ill_shanghan",20);
	target->apply_condition("ill_zhongshu",20);
	target->apply_condition("ill_dongshang",20);

if ((random(me->query("combat_exp"))+extra*800) >(int)target->query("combat_exp")/2 )
{
        target->add("jing",-(target->query("jing")/4));
        target->add("eff_jing",-(target->query("eff_jing")/4));
        target->add("qi",-(target->query("qi")/4));
        target->add("eff_qi",-(target->query("eff_qi")/4));
        msg = RED "$n全身身中数道毒气"+HIR+"口中吐出几口鲜血!\n"NOR;   
}
else {

	target->receive_damage("qi",(int)me->query_skill("shedao-qigong",1)*2);
	target->receive_wound("qi",(int)me->query_skill("shedao-qigong",1));
	target->receive_wound("jing", 50);
}
	message_combatd(msg, me, target);
        me->add("neili", -300);
	me->start_busy(3);
	} else {
		msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(3);
		message_combatd(msg, me, target);
	}
if (random(5)==0 && (int)me->query_skill("shedao-qigong",1) > 300
&& (int)me->query_skill("zhaosheshu",1) > 200
&& (int)me->query_skill("yangsheshu",1) > 200)
{
	message_combatd(
        HIW "$N大喊 洪教主神通广大，战无不胜，攻无不克，无坚不摧，无敌不破！
$n被一团蛇雾笼罩，$n心口一阵巨痛！\n" NOR, me, target);
target->apply_condition("shenlong_poison",50);
}
//	if( !target->is_killing(me) ) me->kill_ob(target);
	return 1;
}
