// feixian.c 天外飞仙

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <condition.h>
inherit F_SSERVER;
string query_name() { return "天外"ZJBR"飞仙"; }
int perform(object me, object target)
{
	int damage,damage1;
	string msg;
	object weapon;
	int extra;
	int ap,dp;

	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「天外飞仙」只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail(RED"开什么玩笑，没装备剑就想使「天外飞仙」？\n"NOR);
//	if (target && target->query_temp("apply/shade_vision")) 
//		return notify_fail("对方隐身了，你看不到"+target->query("name")+"。\n"); 	
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if ((int)me->query_skill("feixian-jian", 1) < 360 )
		return notify_fail(WHT"你的飞仙剑诀不够娴熟，使不出「天外飞仙」。\n"NOR);
	if ((int)me->query_skill("feixian-bu", 1) < 360 )
		return notify_fail(WHT"你的飞仙步不够娴熟，使不出「天外飞仙」。\n"NOR);
	if ((int)me->query_skill("jingyi-shengong", 1) < 360 )
		return notify_fail(WHT"你的净衣神功不够娴熟，使不出「天外飞仙」。\n"NOR);
	if( (int)me->query("int",1) < 30 )
		return notify_fail(HIC"你的悟性不足，无法领悟「天外飞仙」绝技。\n"NOR);
	 if ( me->query_skill_mapped("sword") != "feixian-jian")
         return notify_fail("你必须激发飞仙剑诀才能使用「天外飞仙」！\n");   
	 if ( me->query_skill_mapped("force") != "jingyi-shengong")
         return notify_fail("你必须激发净衣神功才能使用「天外飞仙」！\n");  
	 if ( me->query_skill_mapped("dodge") != "feixian-bu")
         return notify_fail("「天外飞仙」必须要有精妙的步法配合！\n");  	 
	//if (!(int)me->query("breakup"))
		//return notify_fail("你任督二脉未通,无法使用「天外飞仙」。\n"NOR);
	if ((int)me->query("max_neili")<1500)
		return notify_fail(RED"你内力修为不足，无法使用「天外飞仙」。\n"NOR);
	if ((int)me->query("max_jingli")<200)
		return notify_fail(RED"你精力修为不足，无法使用「天外飞仙」。\n"NOR);
	if ((int)me->query("neili")<1500)	
		return notify_fail(HIC"你现在内力不够，没能将「天外飞仙」使完！\n"NOR);
	if ((int)me->query("jingli")<200)	
		return notify_fail(HIC"你现在精力不够，没能将「天外飞仙」使完！\n"NOR);
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	msg = HBWHT "$N贯通飞仙剑诀，使出了白云城的绝学之精髓！\n" NOR;
	message_vision(msg, me, target);
	me->set_temp("cooldown", 3);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 6, me);	//CD写法1	
	ap = me->query("xyzx_sys/level") + me->query_skill("feixian-jian", 1) + me->query_skill("feixian-bu", 1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");	
	extra = me->query_skill("feixian-jian",1) + me->query_skill("sword",1);

	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	msg = HIW "$N剑气冲霄，使出叶孤城的「"HIG"天外飞仙"HIW"」绝技，漫天剑影不可阻挡！\n"NOR;
	message_vision(msg, me, target);

	msg = MAG"白云城主！"HIR"「"HIG"飞仙剑诀"HIY"之"U+HIG"月"HIW"圆"HIY"之"HIW+BLK"夜"NOR+HIR"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = MAG"白云城主！"HIR"「"HIG"飞仙剑诀"HIY"之"U+HIG"紫"HIW"禁"HIY"之"HIW+BLK"巅"NOR+HIR"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = MAG"白云城主！"HIR"「"HIG"飞仙剑诀"HIY"之"U+HIG"一"HIW"剑"HIY"西"HIW+BLK"来"NOR+HIR"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = MAG"白云城主！"HIR"「"HIG"飞仙剑诀"HIY"之"U+HIG"天"HIW"外"HIY"飞"HIW+BLK"仙"NOR+HIR"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);	
	me->add("neili", -1500);
	damage1 = me->query_skill("feixian-jian", 1);
	damage1 = damage1 + random(damage1);
	target->receive_damage("qi", damage1,me);
	target->receive_wound("qi", damage1/5,me);
	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage1 +"，内伤为"+ damage1/5 +"。\n" NOR);
//第二段	
if ((int)me->query_skill("feixian-jian", 1)>200 && (int)me->query_skill("feixian-bu", 1)>200)
{	
	msg = HIW "$N" HIW "使出飞仙剑诀之 "HIG"「剑神一笑」"HIW"，手中" + weapon->name() + HIW "幻化无数剑花，向$n" HIW "的眉心刺来。\n" NOR;
	message_vision(msg, me, target);
	if (random(ap) > dp/3 )
	{
		damage = me->query("xyzx_sys/level") + me->query_skill("sword",1) + me->query_skill("feixian-jian",1) + me->query_skill("jingyi-shengong",1) + me->query_skill("feixian-bu",1);
		damage = damage + random(damage);	
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/5,me);
		msg =HIR "$n" HIR "被$N" HIR "铺天盖地的剑气迷漫，$n根本看不清$N的剑招所在，顿时被剑气穿透！\n" NOR;
		message_vision(msg, me, target);		
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/5 +"。\n" NOR);
		me->add("neili", -1500);
		me->add("jingli", -100);
		me->add_temp("apply/attack", extra*2);
		me->add_temp("apply/damage", extra*2);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));	
		me->add_temp("apply/attack", -extra*2);
		me->add_temp("apply/damage", -extra*2);		
	}
	else
	{
		me->add("neili", -1100);
		msg = CYN "可$n" CYN "闭上双眼，感知到$N的剑招所在，身体一转，躲过了这一剑。\n" NOR;
		message_vision(msg, me, target);
	}
}
//第三段
if ((int)me->query_skill("feixian-jian", 1)>300 && (int)me->query_skill("feixian-bu", 1)>300)
{ 
	msg = HIW "$N" HIW "使出飞仙剑诀之"HIG"「人剑合一」"HIW"，手中" + weapon->name() + HIW "已与$N合二为一，神剑从天而降直刺头顶。\n" NOR;
	message_vision(msg, me, target);
	if (random(ap) > dp/3 )
	{
		if (me->query("jm/nanhai")) damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1)*me->query("int",1)/2 + me->query_skill("jingyi-shengong",1)*me->query("int",1)/3 + me->query_skill("feixian-bu",1);
		else damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1) + me->query_skill("jingyi-shengong",1)*me->query("int",1)/3 + me->query_skill("feixian-bu",1);
		damage = damage + random(damage);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/2,me);
		target->receive_damage("jing",damage,me);
		target->receive_wound("jing",damage/2,me);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"，精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		me->add("neili", -1500);
		me->add("jingli", -100);
		msg =HIR "$n" HIR "根本就无从发现$N" HIR "的剑，直接被剑气透体而过，鲜血狂喷！\n" NOR;
		message_vision(msg, me, target);
		me->add_temp("apply/attack", extra*3);
		me->add_temp("apply/damage", extra*3);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));	
		me->add_temp("apply/attack", -extra*3);
		me->add_temp("apply/damage", -extra*3);
	}
	else
	{
		if (me->query("jm/nanhai"))
		{
		damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1) + me->query_skill("jingyi-shengong",1)*me->query("int",1)/2 + me->query_skill("feixian-bu",1);
		damage = damage + random(damage);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
		msg = HIR "剑是剑，人是人！剑不是剑，人还是人！\n" NOR;
		message_vision(msg, me, target);		
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage +"。\n" NOR);
		}
		me->add("neili", -1500);
		msg = CYN "可$n" CYN "淡然处之，似心有灵犀"CYN "双指伸出，似微风拂过，似清风拂面，" + weapon->name() + HIW "就好像从未动过，出现在$n双指之间。\n" NOR;
		message_vision(msg, me, target);
	}

}
//第四段
if ((int)me->query_skill("feixian-jian", 1)>400 && (int)me->query_skill("feixian-bu", 1)>400 )
{
	msg = HIW "$N" HIW "使出飞仙剑诀之"HIG"「归真道经」"HIW"，$N手中已无剑，心中亦无剑。\n" NOR;	
	msg += HIW "$n" HIW "感觉漫天剑意，但又感觉不到任何杀意。"HIC"此剑仿佛不在人间，又仿佛无处不在。\n" NOR;	
	msg += HIB "月圆之夜，"HIC"紫禁之巅，"HIR"一剑西来，"HIM"天外飞仙！！！"HIC"\n" NOR;	
	msg +=HIC "这一剑根本就没有人能看见 "HIR"看到他的人都已经死了 "HIC" \n" NOR;
	message_vision(msg, me, target);
	if (random(ap) > dp/4 )
	{
		if (me->query("jm/nanhai")) damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1) * me->query("int",1)*2/3 + me->query_skill("jingyi-shengong",1) * me->query("int",1)*2/3 + me->query_skill("feixian-bu",1)*me->query("int",1)*2/3+me->query_skill("force",1);
		else damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1) * me->query("int",1) + me->query_skill("jingyi-shengong",1) * me->query("int",1) + me->query_skill("feixian-bu",1)*me->query("int",1)+me->query_skill("force",1);
		damage = damage + random(damage);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
		target->receive_damage("jing",damage,me);
		target->receive_wound("jing",damage,me);		
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage +"，精神的外伤为"+ damage +"，内伤为"+ damage +"。\n" NOR);
		me->add("neili", -1500);
		me->add("jingli", -100);
		target->apply_condition("no_enforce", 20);
		msg =HIC "这一剑 "HIR"「形」"HIC"成於招未出手之先！"HIR"「神」"HIC"留於招已出手之後！"HIW"以至刚为至柔，以不变为变！！ \n" NOR;		
		msg +=HIR "没有人能形容这一简单灿烂和辉煌！" YEL "没有人能形容这一剑的速度！"HIC"那已不是一柄剑！\n" NOR;
		msg +=HIC "人就是剑 "HIR"剑就是人 "HIC"人非剑"HIR"剑非人"HIC" \n" NOR;	
		message_vision(msg, me, target);
		me->add_temp("apply/attack", extra*4);
		me->add_temp("apply/damage", extra*4);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));	
		me->add_temp("apply/attack", -extra*4);
		me->add_temp("apply/damage", -extra*4);
		if (me->query("jm/nanhai")) 
		{
			msg =HIW "剑光消失之际！"HIM"良久再次从天外爆发一道更加璀璨的光芒，"HIR"这一剑如流星般灿烂，如同永恒！\n" NOR;
			message_vision(msg, me, target);
			target->receive_damage("qi",damage/3,me);
			target->receive_wound("qi",damage/3,me);		
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招追加对敌人气血的外伤为"+ damage/2 +"，内伤为"+ damage/2 +"。\n" NOR);	
		}
/*		if (random(6)==1)
		{
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人造成了昏迷。\n" NOR);
			target->unconcious();			
		}	*/
	}
	else
	{	
		msg = CYN "$n凝神聚气，身形渐渐的消失在虚空之中！但是一剑西来，紫气浩荡！$n仅仅在虚空停留了一息片刻，就被逼的露出了身形，只不过已是避开了大部分剑气。\n" NOR;
		message_vision(msg, me, target);
		if (me->query("jm/nanhai")) damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1)*me->query("int",1) + me->query_skill("jingyi-shengong",1) + me->query_skill("feixian-bu",1);
		else damage = me->query_skill("sword",1) + me->query_skill("feixian-jian",1)*me->query("int",1)/2 + me->query_skill("jingyi-shengong",1) + me->query_skill("feixian-bu",1);
		damage =damage + random(damage);
		target->receive_damage("jing",damage,me);
		target->receive_wound("jing",damage,me);
		me->add("neili", -1500);
		me->add("jingli", -100);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人精神的外伤为"+ damage +"，内伤为"+ damage +"。\n" NOR);
	}

}
	me->start_busy(1);
	return 1;
}

void del_cooldown(object me)	//CD写法1
{ 
	if ( !objectp(me) ) return;
	if ( me->query_temp("cooldown") )	
	{
		me->delete_temp("cooldown");
		tell_object(me, HIM"你呼出一口气，缓缓的将内力收回丹田。\n"NOR);
	}	
}