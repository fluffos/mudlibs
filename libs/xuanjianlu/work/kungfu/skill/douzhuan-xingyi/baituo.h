//baituo puji + cuff
//liu 2002

#include <ansi.h>
#include <armor.h>
#include <combat.h>

void tie_hit(object me, object target);
void pu_hit(object me, object target);
void lingshe(object me, object target);

int baituo(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);
/*
	if( sizeof( me->query_skill_prepare() ) ) {
		me->delete_temp("tong");
		return notify_fail("你发觉自己已经备有武功，于是停手不动。\n");
	}
*/
	if( random(2) == 1 )
	{
		me->delete_temp("puji_time");
		remove_call_out("pu_hit");
		pu_hit(me, target);
		return 1;

	} else {

		object weapon;
		string *limb;
		int skill, damage;

		weapon = target->query_temp("weapon");
		damage = me->query_skill("force")*2+random(me->query("jiali",1)+me->query("jiajin",1))*4;

		limb = target->query("limbs");
		skill = me->query_skill("douzhuan-xingyi",1);

		if(weapon) {

			message_vision( HIB"\n斗然间$N挥拳打出，$n举"NOR + weapon->name() + HIB"挡格，哪知$N的手臂犹似忽然没了骨头，顺势转弯！\n"NOR,me,target);

		} else {
			message_vision( HIB"\n斗然间$N挥拳打出，$n伸臂挡格，哪知$N的手臂犹似忽然没了骨头，顺势转弯！\n"NOR,me,target);
		}

		if( random( me->query("combat_exp", 1) + me->query_skill("force") )*3/2 > random( target->query("combat_exp", 1) + target->query_skill("dodge") ) )
		{
			if(weapon) {
				message_vision(HIR"\n结果$n"NOR + weapon->name() + HIR"脱手，只听「拍」的一声，$n"+limb[random(sizeof(limb))]+"竟是中了一拳。\n\n"NOR,me,target);

				weapon->unequip();
				weapon->move(environment(target));
				target->reset_action();
			} else {
				message_vision(HIR"\n结果只听「拍」的一声，$n"+limb[random(sizeof(limb))]+"竟是中了一拳。\n\n"NOR,me,target);

			}

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage/2)+damage/4, me);
			target->set_temp("lingshe_hit",1);
			if(wizardp(me)) tell_object(me, "quan damage: "+damage+"\n");
			COMBAT_D->report_status(target);
		} else {

			message_vision(HIG"\n$n一惊，低头窜出，回身反击，$N斜步让开，还了一拳。\n"NOR, me, target);

			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		}

		me->add("neili", -skill*3/2);
		me->add("jingli", -skill/2);
		me->start_busy(1+random(1));
		call_out("lingshe", random(2), me, target);

		return 1;
	}

	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}


void pu_hit(object me, object target)
{
	object armor;
	int damage, time, ap, dp, pp, fap, hmg, force;
	string msg, *limb, type, result, str;
	object weapon;

	int dk = me->query_skill("douzhuan-xingyi",1);

	if( !target || !me->is_fighting(target) || !living(me) || me->is_ghost() 
	|| !target || environment(me) != environment(target) || !me->is_fighting() )
	{
			if(me->query_temp("memory")) me->set_skill("hamagong",me->query_temp("memory",1));
			else me->delete_skill("hamagong");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");
			me->delete_temp("tong");
			return;
	}

	type = "内伤";


		if(me->query_skill("hamagong")) {
			me->set_temp("memory",me->query_skill("hamagong",1));
			me->set_skill("hamagong", dk/2+me->query_skill("hamagong",1)/2);
		} else me->set_skill("hamagong", dk);
		me->map_skill("strike", "hamagong");
		me->prepare_skill("strike", "hamagong");


	hmg = (int)me->query_skill("hamagong", 1);
	force = (int)me->query_skill("force", 1);

	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;
	ap = ap*(1+time);

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	
	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
	if( pp < 1 ) pp = 1;

	me->add_temp("puji_time", 1);
	time = (int)me->query_temp("puji_time");

	if( time == 1 ) msg = HIB "\n$N双腿一弯，蹲下身来，“阁”的一声大叫，运起蛤蟆功劲力，双掌齐发，向前推出。这一推实乃$P毕生功力之所聚，$n猛然感受到山洪海啸般的劲力袭来。\n" NOR;
	else if( time == 2 ) msg = HIM "\n$N第一推刚完，第二推又已迅速异常的赶到，前劲未衰，后劲继至，掌风越发猛烈。\n" NOR;
	else msg = HIR "\n$N眼看前招落空，却毫无慌乱，顺势又是一推，第"+chinese_number(time)+"推的掌风犹如沙漠风暴，一阵猛过一阵，呼啸着向$n扑来。\n"NOR;

	message_vision(msg , me,target);
	
	me->add("neili", -hmg);
	me->add("jingli", -hmg/2);

	fap = random(ap + dp);

	if( living(target) && fap < dp ) {

		if(time == 1) message_vision(HIY "$n眼见这一推来势凶猛，挡既不能，避又不可，当下双足一点，跃高四尺，躲开了这一推。\n只听身後腾的一声大响，$N这一推的劲力激起一股狂风巨浪，顿时尘土纷扬，令人惊骇不已。\n\n" NOR, me, target);
	
		else message_vision(HIY "$n眼见这一推气势汹汹，当下双足一点，侧跃三尺，又躲开了这一推。\n只听轰的一声巨响，蛤蟆功猛劲激得灰泥弥漫，又是一片尘土飞扬，声势惊人。\n" NOR, me, target);
		target->start_busy(2+random(2));
		me->start_busy(1);
		if( me->query_skill("strike") > time*150 && time < 5)
			call_out("pu_hit",2+random(2),me,target);
	}

	else if( random(ap + pp)< pp && random(5) == 0 && target->query("race") == "人类" )
	{
		weapon = target->query_temp("weapon");
		if(weapon)
		{
			weapon->unequip();
			weapon->move(environment(target));
			target->reset_action();
			message_vision(HIR"$N猛觉得劲风罩来，心知不妙，手中"NOR + weapon->name() + HIR"脱手飞出，赶紧也是双掌向前平推。这一下是以硬接硬，刹那之间，两下里竟然凝住不动。\n"NOR, target );
		}
		else message_vision(HIR"$N猛觉劲风罩来，心知不妙，也是双掌向前平推。这一下是以硬接硬，刹那之间，两下里竟然凝住不动。\n\n"NOR, target );

		message("vision", HIW BLK"两人本是忽纵忽窜、大起大落的搏击，突然间变得两具僵尸相似，连手指也不动一动，似乎气也不喘一口。\n\n"NOR, environment(me), ({ me, target }) );

		target->add("neili", -hmg);
		target->add("jingli", -hmg);
		target->start_busy(3+random(2));
		me->start_busy(2+random(2));
		remove_call_out("tie_hit");
		call_out("tie_hit",3+random(2),me,target);
	}

	else {
		if( target->query_temp("armor/cloth") )
			armor = target->query_temp("armor/cloth");

		if( (!living(target) || (!armor || (armor && armor->query("armor_prop/armor") < 150) )) && ( target->query_skill("dodge")+target->query_skill("parry") ) < random((me->query_skill("strike") + me->query_skill("force"))*2/3) && target->query("race") == "人类")
		{
			message_vision(HIR"只听$N一声惨叫，这一掌正中小腹。但见$n一个身躯突然平平飞出，腾的一响，尘土飞扬，跌在丈许之外，直挺挺的躺在地下，再也不动。\n\n"NOR, target,target );
			target->receive_wound("qi", (int)target->query("eff_qi"), me);
			target->receive_damage("qi", (int)target->query("qi")+1,  me);
			me->add("neili", -(me->query("jiali")+hmg/2));
			me->add("jingli", -me->query("jiajin"));
		}
		else
		{
			damage = (me->query("jiali") + me->query("jiajin")) * (int)me->query_skill("force")/60 + (random(hmg)+force)*time +me->query_temp("apply/damage");

			if(damage > me->query_skill("strike")*(8+time) ) damage = me->query_skill("strike")*(8+time);
			if(damage < me->query_skill("strike")*time ) damage = me->query_skill("strike")*time;
			me->add("neili", -(me->query("jiali")+hmg/2));
			me->add("jingli", -me->query("jiajin"));

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage/2)+damage/4, me);
			target->start_busy(1+random(3));

			limb = target->query("limbs");

			if(random(2) ) type = "瘀伤";
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );
			message_vision(result, me, target);

			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("( $N"+str+" )\n", target);
			if(wizardp(me)) tell_object(me, "puji damage: "+damage+"\n");
		}
	}

	me->start_busy(3+random(2));

			if(me->query_temp("memory")) me->set_skill("hamagong",me->query_temp("memory",1));
			else me->delete_skill("hamagong");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");
			me->delete_temp("tong");

}


void tie_hit(object me, object target)
{
	int sum, n1, n2;
	string msg;

	int dk = me->query_skill("douzhuan-xingyi",1);

	if( !target || !me->is_fighting(target) || !living(me) || me->is_ghost() 
	|| !target || environment(me) != environment(target) || !me->is_fighting() )
	{
			if(me->query_temp("memory")) me->set_skill("hamagong",me->query_temp("memory",1));
			else me->delete_skill("hamagong");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");
			me->delete_temp("tong");
			return;
	}


		if(me->query_skill("hamagong")) {
			me->set_temp("memory",me->query_skill("hamagong",1));
			me->set_skill("hamagong", dk/2+me->query_skill("hamagong",1)/2);
		} else me->set_skill("hamagong", dk);
		me->map_skill("strike", "hamagong");
		me->prepare_skill("strike", "hamagong");


	sum = me->query_skill("force") + me->query_skill("strike") + target->query_skill("force") + target->query_skill("parry");
	n1 = me->query("neili");
	n2 = target->query("neili");

	me->add("neili", -100 * sum / ( me->query_skill("force") + me->query_skill("strike") ) ); 
	if(me->query("neili")<0)me->set("neili",0);

	target->add("neili", -150 * sum / ( target->query_skill("force") + target->query_skill("strike") ) );
	if(target->query("neili")<0)target->set("neili",0);

	if( n1 > 3000 && n2 > 3000) {
		msg = WHT"此时双方掌力均极强劲，欲分胜负，非使对方重创不可。\n"NOR;

		if( n1 > n2 )
		msg += HIW"二人又僵持一会，$n头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR;
		else msg += HIW"二人又僵持一会，$N头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR;
	}

	else {

		if( n1 > n2 ) msg = WHT"$N不断催动蛤蟆功猛劲，毫无衰颓迹象。稍过片刻，$n已是全身大汗淋漓。\n"NOR;
		else msg = WHT"$N脸上黑气大盛，将蛤蟆功发挥到了极致。稍过片刻，$N已是全身大汗淋漓。$n似乎依然中气十足，头顶热气蒸蒸而上。\n"NOR;
		}

	message_vision(msg , me,target );


	if( me->query("neili") > 0 && target->query("neili") > 0 && me->is_busy() && target->is_busy() && living(me) && living(target) )
	{
		target->start_busy(3+random(2));
		me->start_busy(3+random(2));
		remove_call_out("tie_hit");
		call_out("tie_hit",2+random(2), me,target);

			if(me->query_temp("memory")) me->set_skill("hamagong",me->query_temp("memory",1));
			else me->delete_skill("hamagong");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");

		return;
	}

	if( target->query("neili") <= 0 )
	{
		message_vision(HIR "\n$N突然喘不过气来，全身发抖，原来内力已全部耗尽。突闻前胸一片骨裂之声，已被蛤蟆功一掌击中，哼也哼不出一声，仰身向后跌倒，双眼紧闭，脸如白纸，端的是生死难料。\n\n" NOR, target);
		target->receive_wound("qi", (int)target->query("eff_qi"), me);
		target->receive_damage("qi", (int)target->query("eff_qi")+1,  me);

			if(me->query_temp("memory")) me->set_skill("hamagong",me->query_temp("memory",1));
			else me->delete_skill("hamagong");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");
			me->delete_temp("tong");

		return;
	}

	if( me->query("neili") <= 0 )
	{
		message_vision(HIR "\n$N脸上黑气大作，突然喘不过气来，全身发抖，原来内力已全部耗尽。蛤蟆功立时全部反弹回来，但闻前胸一片骨裂之声，哼也哼不出一声，俯身跌倒，双眼紧闭，脸如黑墨，端的是生死难料。\n\n" NOR, me);
		me->receive_wound("qi", (int)me->query("eff_qi"), target);
		me->receive_damage("qi", (int)me->query("eff_qi")+1,  target);
	}


			if(me->query_temp("memory")) me->set_skill("hamagong",me->query_temp("memory",1));
			else me->delete_skill("hamagong");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");
			me->delete_temp("tong");

}


void lingshe(object me, object target)
{
	string *limb;
	int skill,damage;

	if( !target || !me->is_fighting(target) || !living(me) || me->is_ghost() 
	|| !target || environment(me) != environment(target) || !me->is_fighting() )
	{
			me->delete_temp("tong");
			return;
	}

	damage = me->query_skill("force")*2+random(me->query("jiali",1)+me->query("jiajin",1))*5;
	limb = target->query("limbs");
	skill = me->query_skill("douzhuan-xingyi",1);

	if( target->query("double_attack"))
	{
		message_vision(
		HIB"\n$n眼见$N第二拳跟着打到，仍是举左臂挡架。\n"
		"$N依样葫芦，手臂又弯击过来，$n头向后仰，右臂猛地向前推出，正是周伯通的左右互搏术！左架右推，同时施为。\n"NOR
		+HIR"\n$N的右臂恰好夹在双臂之中，被$n左臂回收，右臂外推，这般急绞之下，只听喀的一声。\n\n"NOR,me,target);

		me->receive_damage("qi", skill*2, me);
		me->receive_wound("qi", skill, me);
        	COMBAT_D->report_status(me);
		target->delete_temp("lingshe_hit");
	}
	else 
	{
		message_vision(HIB
		"\n转眼间$N又一招“灵蛇拳”横臂扫出，正如蛇身虽有骨而似无骨，竟能四面八方，任意所之！"
		"\n$n不敢再格，侧身闪避，哪知$N手臂忽然间就如变了一根软鞭，打出后能在空中拐弯，明明见$N拳头打向左方，蓦地里转弯向右！\n"NOR, me, target);

		if( target->query_skill_mapped("hand") == "shexing-diaoshou" && target->query_skill_mapped("parry") == "shexing-diaoshou" && target->query_skill("hand") > random(skill) )
		{
			message_vision(HIG"\n$n心头暗喜，勾腕伸爪，疾以蛇形刁手拿$N拳头。这一下恰到好处，又快又准，正是克制“灵蛇拳法”的巧妙法门。\n"NOR,me,target);
			target->delete_temp("lingshe_hit");
			me->start_busy(2+random(2));
		}

		else if( random( me->query("combat_exp", 1) + me->query_skill("strike") ) > random( target->query("combat_exp", 1) + target->query_skill("dodge") ) )
		{
			if( target->query_skill_mapped("hand") == "shexing-diaoshou" && target->query_skill_mapped("parry") == "shexing-diaoshou" )
			{
				message_vision(HIG"\n$n心头暗喜，勾腕伸爪，疾以蛇形刁手拿$N拳头。哪知$n一时大意，被$N迂开就是一拳。\n"NOR,me,target);

			}
			message_vision(HIR"\n结果只听「蓬」的一声，又在$n"+limb[random(sizeof(limb))]+"击了一拳。\n\n"NOR,me,target);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage/2)+damage/4, me);
			if(wizardp(me)) tell_object(me, "quan damage: "+damage+"\n");
			COMBAT_D->report_status(target);

			if( target->query_temp("lingshe_hit") ) {
				message_vision(HIR"\n$n防不胜防，接连吃了两拳，这两下都是十分沉重，登时心下慌乱，不知如何应付。\n"NOR,me,target);
			target->delete_temp("lingshe_hit");
			target->start_busy(1+random(1));
			}
		}

		else {

		message_vision(HIG"\n$n眉心一紧连忙纵身，躲开了$N的拳势。\n"NOR, me, target);

		}
	}
		me->add("neili", -skill*3/2);
		me->add("jingli", -skill);
		me->start_busy(1+random(2));
		me->delete_temp("tong");

	return;

}
