//wudang lh + kh 
//liu 2002

#include <ansi.h>
#include <armor.h>
#include <combat.h>

int wudang(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 1 )
	{
		string *circle, msg;

		circle = ({
			"$N「双风贯耳」，连消带打，双手成圆形击出，随即左圈右圈，一个圆圈跟着一个圆圈，大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出。",
			"$N「云手」使出时连绵不断，有如白云行空，一个圆圈未完，第二个圆圈已生。",
			"$N右肩斜闪，左手凭空划了几个圈子。"
		});
		msg = WHT"\n"+ circle[random(sizeof(circle))] +"\n";
		me->add("jing", -50);
		me->add("jingli", -50);

	        if( me->query("combat_exp") * me->query_int() / 100
			> (int)target->query("combat_exp") * target->query_int() / 200 )
		{
			msg += HIY"结果$N以环形之力，推得$n进了$P的无形圈内。\n"NOR;
			me->start_busy(1);
			call_out("zhen", 1, me, target);
		} else {
			msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
        	        me->start_busy(1+random(1));
			me->delete_temp("tong");
		}

		message_vision(msg, me, target);
		return 1;

	} else {

		int damage, ap, dp, pp;
		string msg, *limb, type, result, str;

		type = "内伤";

		ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
		if( ap < 1 ) ap = 1;

		dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
		if( dp < 1 ) dp = 1;
	
		pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
		if( pp < 1 ) pp = 1;

		msg = HIW "\n$N深深吸了一口气，一招「花开并蒂」左手挥掌猛击$n的右颊，右手出指疾点$n的“缺盆穴”。\n" NOR;
		message_vision(msg , me,target);
	
		me->add("neili", -me->query_skill("strike")/2);
		me->add("jingli", -me->query_skill("strike")/3);

		//let some skill can parry this pfm
		if ((int)target->query_skill("qiankun-danuoyi", 1) > (int)me->query_skill("mian-zhang", 1)/4){
			message_vision(HIY "\n$n右手五指犹如抚琴鼓瑟，忽挑忽捻，忽弹忽拨，上身半点不动，片刻间将$N掌力尽数卸了！\n" NOR, me, target);
			me->start_busy(2+random(2));
		}
		else if( living(target) && random(ap + dp) < dp ) {
			message_vision(HIY "\n可是$n已看破$N此招，不慌不忙的避开了。\n" NOR, me, target);
			me->start_busy(2+random(2));
		} else {
			damage = (me->query_skill("force") + dk/(1 + random(2))*2 );

			if( dk * me->query("neili")/100 > 
				(int)target->query_skill("force") * (int)target->query("neili") /200  ){
				me->set_temp("double_huakai", 1);
				//double_huakai cost more 
				me->add("neili", -me->query_skill("force")/4);
				me->add("jingli", -me->query_skill("force")/6);
				damage = (me->query_skill("force") + dk/(1 + random(1))*3 );
				message_vision(WHT"\n$N双手递招之后，跟着右掌击$n左颊，左手食指点$n右肩后“缺盆穴”。\n"
		               "这两招「花开并蒂」并成一招，连续四式，便如暴风骤雨般使出，势道之猛，手法之快，当真非同小可！\n"NOR, me, target);
			}
			if(wizardp(me)) tell_object(me, "huakai damage: "+damage+"\n");

			target->start_busy(2+random(3));
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/3, me);
			//target will damage neili when hit by
			target->add("neili", -(damage/4));
			if (target->query("neili") < 0) target->set("neili",0);

			limb = target->query("limbs");

			if(random(2) ) type = "瘀伤";
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );

			if( me->query_temp("double_huakai") ) 
			message_vision(HIR"\n$N左手一掌打上了$n的左颊，右手食指点中了$n的左肩“缺盆穴”。\n"
				"跟$N着右手一掌打上了$n的右颊，左手食指点中了$n的右肩“缺盆穴”。\n"
				"\n$N这招“花开并蒂”四式连环，四式齐中！\n"NOR, me, target );
			else message_vision(HIR"\n$N左手一掌打上了$n的左颊，右手食指点中了$n的左肩“缺盆穴”！\n"NOR, me, target );

			message_vision(result, me, target);

			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("( $N"+str+" )\n", target);
		}
		if(me->query_temp("double_huakai")) me->delete_temp("double_huakai");
		me->start_busy(1+random(2));

	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}


int zhen(object me, object target)
{
	int damage, tjsg, tjq;
	string *zhen, msg, result, str, type;

	if( !me->is_fighting(target) || !living(target) ) {me->delete_temp("tong");return 0;}

	tjsg = (int)me->query_skill("force");
	tjq = (int)me->query_skill("force");

	zhen = ({
		"但见$N双臂一圈一转，使出「六合劲」中的“钻翻”“螺旋”二劲，已将$n圈住。",
		"$N接着使出一招「云手」，左手高，右手低，一个圆圈已将$n套住。"
	});

	if( random(3)==1 )
	{
		type = "瘀伤";
		msg = HIY"\n只见$N左掌阳、右掌阴，目光凝视左手手臂，双掌慢慢合拢，竟是凝重如山，却又轻灵似羽。右捺左收，使得犹如行云流水，潇洒无比！\n"NOR
		"$n只觉上盘各路已全处在$P双掌的笼罩之下，无可闪避，无可抵御！\n";
	}
	else if( random(3)==2 )
	{
		type = "瘀伤";
		msg = HIR"\n紧跟着$N双臂一合，一招「双耳贯风」，双拳击向$n的左右两耳。这一招绵劲中蓄，其软如绵，其坚胜铁！\n"NOR
		"$n只觉上盘各路已全处在$P双掌的笼罩之下，无可闪避，无可抵御！\n";
	}
	else
	{
		type = "内伤";
		msg = "\n"+ zhen[random(sizeof(zhen))] +"随即潜运神功，企图以内力震伤$p！\n";
	}

	if( target->query("neili") <= target->query("max_neili")/10 )
	{
		msg += "$p只得强行运劲与$P相抗，不料猛然发觉自己真气已然枯竭耗尽。\n";
		if( type == "内伤" )
			msg += RED"结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		else 
			msg += RED"结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n"NOR;

		target->receive_damage("qi", (int)target->query("qi")+1, me);
	}
        else if( random((tjq + tjsg) * me->query_int() / 100) >
		(target->query_skill("parry") + target->query_skill("dodge")) * target->query_int() / 200 )
	{
		me->start_busy(1+random(2));
		target->start_busy(3);
                
		damage = tjsg + tjq/2;                
		//damage = damage/2 + random(damage);
		damage = damage + random(damage);

		if( type == "瘀伤" )
			damage = damage + tjq/2;
		if( me->query("neili") > target->query("neili")*2 )
			damage = damage + tjsg/2; 

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		target->add("neili", -(damage/4));

		me->add("neili", -damage/10);

		result = COMBAT_D->damage_msg(damage, type);
		result = replace_string( result, "$p", target->name() );
		msg += result;

		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "( $n"+str+" )\n";
	}
	else if( random(tjsg) > target->query_skill("force")/2 )
        {
                me->start_busy(1+random(2));
                target->start_busy(2+random(1));
                
                damage = (int)me->query_skill("douzhuan-xingyi", 1);
                //damage = damage/2 + random(damage);
                damage = damage + random(damage);

                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                me->add("neili", -damage/10);

		msg+= HIR"$p只得强行运劲与$N相抗，";
		if( damage < 100 ) 
			msg += "结果受到$P的内力反震，闷哼一声。\n"NOR;
		else if( damage < 200 ) 
			msg += "结果被$P以内力反震，「嘿」地一声退了两步。\n"NOR;
		else if( damage < 400 ) 
			msg += "结果被$P以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
		else 
			msg += "结果被$P的内力一震，眼前一黑，身子向后飞出丈许！！\n"NOR;
        }
	else if( me->query("neili")*2 < target->query("neili") ) 
	{
		me->start_busy(3);
		target->start_busy(1+random(2));
                
		damage = (int)target->query_skill("force")/2;
		damage = damage/2 + random(damage);
                
		me->receive_damage("qi", damage, me);
		me->receive_wound("qi", damage/3, me);
		target->add("neili", -damage/10);
                
                if( damage < 100 ) 
			msg += HIY"不料$P受到$p的内力反震，闷哼一声。\n"NOR;
                else if( damage < 200 ) 
			msg += HIY"不料$P被$p以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 400 ) 
			msg += RED"不料$P被$p以内力反震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else 
			msg += HIR"不料$P被$p的内力反震，眼前一黑，身子向后飞出丈许！！\n"NOR;
	}
	else
	{
		me->start_busy(3);
		target->start_busy(3); 
		me->add("jingli", -50);
		me->add("neili", -300);
		target->add("jingli", -50);
		target->add("neili", -300);
		msg += HIY"$p只得强行运劲与$P相抗，两人身子都是一晃，各自退开几步！\n"NOR;
	} 

	message_vision(msg, me, target);
	me->delete_temp("tong");
	return 1;
}

