// 狂蛇舞

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
                return notify_fail("只能对战斗中的对手使用。\n");

	if (objectp(weapon = me->query_temp("weapon"))
	&& (string)weapon->query("skill_type") != "staff"
	)
            return notify_fail("必须空手使用或用杖。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("shenlong-bashi", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("shedao-qigong", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("shenlong-xinfa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通神龙岛武学，使出了神龙岛的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(3);
	me->add_temp("apply/attack",extra/3);
	me->add_temp("apply/damage",2*extra);
        msg = HIY "$N使出神龙岛的绝技魔蛇舞!\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIR "$N仰天长啸，高声狂叫：不死神龙，唯我不败！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG "$N洪教主神通广大，我教战无不胜，攻无不克，无坚不摧，无敌不破！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
        msg = HIW "$N叫道：洪教主神通护佑，众弟子勇气百倍，以一当百，以百当万。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
        msg = HIC "$N叫道：我弟子杀敌护教，洪教主亲加提拔，升任圣职。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
        msg = HIB "$N叫道：我教弟子护教而死，同升天堂！。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
        msg = YEL "$N叫道：洪教主神目如电，烛照四方。。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
	me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-2*extra);
	msg = MAG "$N掌出如风轻轻落在$n肩头上。\n"NOR;

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) 
{
		msg += MAG "结果只听扑的一声，$p被$P一掌拍中！\n" NOR;
		msg += MAG "$p只觉得全身暖洋洋的，感到有点轻飘无力轻。\n" NOR;
        target->apply_condition("snake_poison",60);
        target->apply_condition("cold_poison",60);
	target->receive_damage("qi",(int)me->query_skill("shenlong-xinfa",1)*6);
	target->receive_wound("qi",(int)me->query_skill("shenlong-xinfa",1));

		msg += HIB "忽然一股寒气优似冰箭，循着手臂，迅速无伦的射入$p胸膛\n" NOR;
}
	 else {
		msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
	}

	message_combatd(msg, me, target);
	msg = HIR "$N口中念念有词，顷刻之间武功大进，高高跃起，$P手中巨毒的蛇血，向$n全身喷去!\n";

        if( (random(me->query("combat_exp"))) >(int)target->query("combat_exp")/3 )
        {
		msg += MAG "结果$p被巨毒的蛇血喷中、n" NOR;
	msg += HIR "$p只闻到一阵头昏，口中吐出一大口鲜血。\n" NOR;
	msg += HIC "$p金星乱冒，犹如有万条金龙在眼前舞动。。\n" NOR;
	message_combatd(msg, me, target);

        if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
        {                
        msg = HIW "第一道毒气"+HIR+"击中$n右身，！\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",60);
        }
        if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
        {                
        msg = HIC "第二道毒气"+HIM+"扫中$n的左身！\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",60);
        }
        if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
        {                
        msg = MAG "最后一道毒气"+HIB+"扫中$n的上身!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",60);
        }
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);
 target->apply_condition("xuanming_poison",60);
if ((random(me->query("combat_exp"))+extra*800) >(int)target->query("combat_exp")/3 )
{
if (target->query("qi") < 100000)
{
        target->add("jing",-(target->query("jing")/4));
        target->add("eff_jing",-(target->query("eff_jing")/4));
        target->add("qi",-(target->query("qi")/4));
        target->add("eff_qi",-(target->query("eff_qi")/4));
}
else {
	target->receive_damage("qi",(int)me->query_skill("shedao-qigong",1)*6);
	target->receive_wound("qi",(int)me->query_skill("shedao-qigong",1)*2);
}
        msg = RED "$n全身身中数道毒气"+HIR+"口中吐出几口鲜血!\n"NOR;   
}
else {

	target->receive_damage("qi",(int)me->query_skill("shedao-qigong",1)*6);
	target->receive_wound("qi",(int)me->query_skill("shedao-qigong",1)*2);
	target->receive_wound("jing", 50);
}
	message_combatd(msg, me, target);
	} else {
		msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
		message_combatd(msg, me, target);
	}

	me->start_busy(4);
	return 1;
}
