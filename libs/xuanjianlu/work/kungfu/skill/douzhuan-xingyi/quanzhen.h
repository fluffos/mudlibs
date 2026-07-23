//quanzhen fs + jd + sh,jd cut 1 hit
//liu 2002

#include <ansi.h>

void hit(object me, object target);

int quanzhen(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(3) == 1 )
	{
		int skill, jiali, jiajin, damage, mn, tn, ap, dp, ad;

		if(me->query_skill("sanhua-juding")) {
			me->set_temp("memory",me->query_skill("sanhua-juding",1));
			me->set_skill("sanhua-juding", dk/2+me->query_skill("sanhua-juding",1)/2);
		} else me->set_skill("sanhua-juding", dk);
		me->map_skill("strike", "sanhua-juding");
		me->prepare_skill("strike", "sanhua-juding");

		if(me->query_skill("chunyang-quan")) {
			me->set_temp("memory2",me->query_skill("chunyang-quan",1));
			me->set_skill("chunyang-quan", dk/2+me->query_skill("chunyang-quan",1)/2);
		} else me->set_skill("chunyang-quan", dk);
		me->map_skill("cuff", "chunyang-quan");
		me->prepare_skill("cuff", "chunyang-quan");

	skill = me->query_skill("sanhua-juding",1)/2+me->query_skill("chunyang-quan",1)/2;
	jiali = me->query("jiali",1);
	jiajin = me->query("jiajin",1);
	ad = me->query("shen",1)/5000;
	if (ad>500) ad=500;

	ap = me->query("combat_exp",1)/1000 + me->query_skill("cuff") + me->query_skill("strike");
	dp = target->query("combat_exp",1)/1000 + target->query_skill("dodge") + target->query_skill("parry");

	mn = me->query("neili",1)/20 + me->query("max_neili",1)/20 + me->query_skill("force");
	tn = target->query("neili",1)/20 + target->query("max_neili",1)/20 + target->query_skill("force");

	damage = me->query_skill("force")+me->query_skill("cuff")+random(jiali+jiajin)*4;

        if (me->query("neili")<=skill) return notify_fail("你的内力不够！\n");

        if (me->query("jingli")<=skill/2) return notify_fail("你的精力不够！\n");

        message_vision(HIY "\n$N运起斗转星移，突然间双手拳掌并用，变化无方，连下杀手！\n" NOR, me,target);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	if (random(2)==1)
	{
        	message_vision(HIB "\n酣斗中蓦地飞出一拳，猛向$n肩头轰去，这一招“天外飞山”去势奇特，迅捷异常，眼见$n无法避开。\n\n" NOR, me,target);
	        message_vision(CYN "$n运起本门心法，双拳齐出，看来是要与$N拼个玉石俱焚！\n\n" NOR, me,target);
	} else {
        	message_vision(HIM "\n酣斗中蓦地飞出一掌，猛向$n肩头劈去，这一招“天外飞山”去势奇特，迅捷异常，眼见$n无法避开。\n\n" NOR, me,target);
		message_vision(CYN "$n暗运内气，聚力与掌，看来是要以数十年修为比拼真力！\n\n" NOR, me,target);
	}

	if(me->query("shen",1)>me->query("combat_exp",1)*4/5)
	{
		message_vision(HIW"$N玄功大乘，内劲浑厚刚猛，并有一股浩然正气贯串始终！\n"NOR, me, target);
		damage = damage+ad;
	} else {
		message_vision(HIC"$N内劲浑厚刚猛，似汹涌海啸，一浪跟一浪、一浪盛一浪！\n"NOR, me, target);
	}

	if (ap<dp*2/3)
	{
		message_vision(HIG "\n$n诡异的一笑，微微恻身，虽然躲过这致命的一击，却也暗暗心惊。\n\n" NOR, me,target);
		damage = 0;
	}
	else if (mn>tn*5/4)
	{
		message_vision(HIR"只听得喀喇一声，$n上臂竟被$N蕴蓄全真派上乘内功的这一招生生震断。\n"NOR, me, target);
		damage = damage+random(damage);
	}
	else if (mn>tn)
	{
		message_vision("结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR, me, target);
		damage =damage+random(damage/2);
	}
	else if (mn>tn*4/5)
	{
		message_vision("结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR, me, target);
	} else {
		message_vision(HIM"\n只见$N斗转星移神功自然而然发动，将$n的力道引到一边。\n\n"NOR, me, target);
		damage = 0;
	}

	if (damage > 0)
	{
		target->start_busy(1);
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2+random(damage/2), me);

		COMBAT_D->report_status(target);
		if( wizardp(me) ) tell_object(me,"damage "+damage+" ap:"+ap+" dp:"+dp+" mn:"+mn+" tn:"+tn+"\n");
	}

	me->start_busy(2+random(2));
        me->add("neili", -skill);
        me->add("jingli", -skill/2);

		if(me->query_temp("memory")) me->set_skill("sanhua-juding",me->query_temp("memory",1));
		else me->delete_skill("sanhua-juding");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

		if(me->query_temp("memory2")) me->set_skill("chunyang-quan",me->query_temp("memory2",1));
		else me->delete_skill("chunyang-quan");
		me->delete_temp("memory2");
		me->prepare_skill("cuff");
		me->map_skill("cuff");

	} else if ( random(3) == 2 ) {

		object weapon;
		int damage,skill,wap,wdp;
		string *limb, type, result, str,msg;

		type = "内伤";

		if(me->query_skill("sanhua-juding")) {
			me->set_temp("memory",me->query_skill("sanhua-juding",1));
			me->set_skill("sanhua-juding", dk/2+me->query_skill("sanhua-juding",1)/2);
		} else me->set_skill("sanhua-juding", dk);
		me->map_skill("strike", "sanhua-juding");
		me->prepare_skill("strike", "sanhua-juding");

		msg = HIM"$N运起斗转星移，内力遍布全身，头顶冒出丝丝热气，竟然呈现三朵莲花，紧跟劈出一掌，一股气劲似浪潮一般向$n袭来！\n\n"NOR;
		message_vision(msg, me, target);

		skill =  ( me->query_skill("sanhua-juding") + me->query_skill("force") ) / 2;

		me->add_temp("apply/attack", skill/2);
		me->add_temp("apply/damage",  skill/6);
		me->add_temp("apply/dodge",  skill/2);
		me->add_temp("apply/parry",  skill/2);
		me->add_temp("apply/defense",  skill/2);

		weapon = target->query_temp("weapon");

		if( objectp(weapon) )
		{
			wap =   me->query("force")/5
			+ (int)me->query("sanhua-juding")/5
			+ (int)me->query_str()
			+ (int)me->query("jiali");

			wdp = (int)weapon->weight() / 500
			+ (int)weapon->query("rigidity")
			+ (int)target->query_str()
			+ (int)target->query("jiali")
			+ (int)target->query_skill("parry")/3;

			wap = wap/2 + random(wap/2);

			if( wap > 3 * wdp ) {
				message_vision(HIY"只见$N身上的$n"+HIY+"已被一掌震断。\n"NOR, target, weapon);
				weapon->unequip();
				weapon->move(environment(target));
				weapon->set("name", "断掉的" + weapon->query("name"));
				weapon->set("value", 0);
				weapon->set("weapon_prop", 0);
				target->reset_action();
				me->add("neili", -150); // to break weapon takes more neili

			} else if( wap > 2 * wdp ) {
				message_vision(HIW"$N只觉得手中" + weapon->name() + "被一掌震得把持不定，脱手飞出！\n" NOR, target);
				weapon->unequip();
				weapon->move(environment(target));
				target->reset_action();
				me->add("neili", -120); // to break weapon takes more neili

			} else if( wap > wdp ) {
				message_vision("$N只觉得手中" + weapon->name() + "一震，险些脱手！\n", target);
				me->add("neili", -100); // to break weapon takes more neili
			}
		}
		else{
			me->add_temp("apply/attack", skill/2);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->add_temp("apply/attack", -skill/2);
		}

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -skill/2);
	me->add("jingli", -100);
	me->add("jing", -100);
	me->start_busy(random(2));

		me->add_temp("apply/attack", -skill/2);
		me->add_temp("apply/damage",  -skill/6);
		me->add_temp("apply/dodge",  -skill/2);
		me->add_temp("apply/parry",  -skill/2);
		me->add_temp("apply/defense",  -skill/2);

		if(me->query_temp("memory")) me->set_skill("sanhua-juding",me->query_temp("memory",1));
		else me->delete_skill("sanhua-juding");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

	message_vision(HIY "\n$N吸了一口气，将内力收回丹田！\n\n" NOR, me);

	} else {

	me->delete_temp("quanzhen/juding");
	message_vision(HIM"\n$N运起斗转星移，内力遍布全身，头顶冒出丝丝热气，竟然呈现三朵莲花。\n\n"NOR,me,target);
	me->start_busy(2);
	call_out("hit", random(1), me, target);
	return 1;
	}

	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}

void hit(object me, object target)
{
	int skill, jiali, exp1, exp2, damage, neili1, neili2, max_neili1, max_neili2, mm, tt, ap, dp, num;

	skill = me->query_skill("douzhuan-xingyi",1);
	jiali = me->query("jiali",1);

	exp1 = me->query("combat_exp",1)/1000;
	exp2 = target->query("combat_exp",1)/1000;
	neili1 = me->query("neili",1)/20;
	neili2 = target->query("neili",1)/20;
	max_neili1 = me->query("max_neili",1)/20;
	max_neili2 = target->query("max_neili",1)/20;
	mm = me->query_skill("force");
	tt = (target->query_skill("force")+target->query_skill("parry"))/2;

	ap = exp1+mm+max_neili1+neili1;
	dp = exp2+tt+max_neili2+neili2;

	damage = me->query_skill("force")*2+random(jiali)*2;
	num = me->query_temp("quanzhen/juding",1);

	if( !target 
	|| !me->is_fighting() || !target->is_fighting()
	|| !living(me) || !living(target)
	|| me->is_ghost() || target->is_ghost()
	|| environment(me) != environment(target) 
	|| me->query("neili",1) < skill || me->query("jingli",1) < skill/2 || me->query_temp("quanzhen/juding",1) > 3 )
	{
		me->delete_temp("quanzhen/juding");
		if(me->query("neili",1)<0) me->set("neili",0);
		me->delete_temp("tong");
		return;
	}
/*
	if(num>3)
	{
		message_vision(HIM"\n$N掌上使足了劲力，“嘿”的一声，向$n推了过去，这一掌中含着$N修为数十年的全真派上乘玄功内劲！\n"NOR,me,target);
		damage = damage+random(damage);
	}
*/
	if(num>2)
	{
		message_vision(HIM"\n到第四掌上，$n已是退无可退，只见$N右掌击出，朗声说道：“$n，认输吧！”\n"NOR,me,target);
	}
	else if(num>1)
	{
		message_vision(HIM"\n$N越战越勇，竟踏上半步，第三掌紧跟着击出，这三掌一掌快似一掌，逼得$n连连退却！\n"NOR,me,target);
	}
	else if(num>0)
	{
		message_vision(HIM"\n$N也是微微一退，但只退了尺许，跟着第二掌毫不停留的拍出，直取$n胸口！\n"NOR,me,target);
	}
	else
	{
		message_vision(HIM"\n$N足底尘土泛起，全身真气冲关欲出，紧接着一掌当面击出，直取$n面门！\n"NOR,me,target);
	}

	message_vision(CYN"$n只觉劲风扑来，急忙提掌还击，与$N手心相抵，比拼内劲！\n"NOR,me,target);

	if (ap>dp*5/4)
	{
		message_vision("双掌相交，只听轰的一响，$n喷出一大口鲜血，缓缓坐倒，委顿在地！\n"NOR,me,target);
	}
	else if (ap>dp)
	{
		message_vision("双掌相交，只听砰的一响，$n被震得内息翻涌，连退两步！\n"NOR,me,target);
		damage = damage*2/3;
	}
	else
	{
		message_vision("双掌相交，只听拍的一响，$n退后一步，虽无大碍却也被震得手臂发麻！\n"NOR,me,target);
		damage = 10;
	}

	target->add("neili",-skill);
	target->start_busy(1);
	me->start_busy(2+random(1));
	me->add("neili",-skill-jiali);
	me->add("jingli",-skill/2);
	me->add_temp("quanzhen/juding",1);

	call_out("hit", random(1), me, target);

	target->receive_damage("qi", damage+random(damage), target);
	target->receive_wound("qi", damage/2+random(damage/2), target);

	COMBAT_D->report_status(target);

	if( wizardp(me) ) tell_object(me,"damage "+damage+" ap:"+ap+" dp:"+dp+"\n");

		if(me->query("neili",1)<0) me->set("neili",0);
		me->delete_temp("tong");
	return;
}
