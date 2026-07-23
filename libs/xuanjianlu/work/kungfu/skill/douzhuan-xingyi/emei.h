//emei
//liu 2002
//pz:sz=3:1,sz add 1 condition

#include <ansi.h>
#include <combat.h>

int emei(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 1 )
	{

		int damage,lvl,k,l;
		string str;

		lvl = me->query_skill("douzhuan-xingyi",1);

		message_vision(HIW "\n$N突然凌空虚劈一掌，右手疾伸。五根手指后发先至，竟已悄无声息地扣住了$n的咽喉。\n\n" NOR, me,target);

		me->add("neili", -lvl);
		me->add("jingli", -lvl);

		if (!target->is_killing(me->query("id"))) target->kill_ob(me);

		k=me->query("combat_exp")/10*(9+random(21))-target->query("combat_exp")-random(me->query("combat_exp")/10);
		l=random(me->query_dex())-random(target->query_dex()*2/3);

		if (k<=0 && l<0)
		{
			message_vision(HIC "$n早有提防，从容地向后退了半步，便已避开了$N的致命一击！\n\n" NOR, me,target);
			tell_object(me, HIR"你奋力一击，只道就此得手。不想却被对手轻易闪过，背后登时露出了极大的空门。\n\n"NOR);
			me->start_busy(3+random(3));

		} else if (k<=0 && l>=0) {

			message_vision(CYN "$n自知无幸，不料$N功力尚浅，虽然一击命中，却已是强弩之末，再也无力按下去了。\n\n" NOR, me,target);
		} else if (k>0 && l<0) {

			damage=me->query_str()*me->query("jiali")/target->query_con();
			if (damage<=100) message_vision(BLU "$n心知此招厉害，竭力向后闪躲。虽是堪堪避过，早已惊出了一身冷汗。\n\n" NOR, me,target);
			else {
				message_vision(MAG "$n心知此招厉害，竭力向后闪躲。虽然避过了咽喉要害，胸前却已被重重地印上了一掌。\n\n" NOR, me,target);
				target->receive_damage("qi",damage,me);
				str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
				message_vision("($N"+str+")\n", target);
				me->apply_condition("tong",1);
			}
			target->start_busy(3+random(3));
			me->add("neili", -lvl);
			me->add("jingli", -lvl);


		} else if (k>0 && l>=0) {

			me->apply_condition("tong",1);

			damage=(me->query_str()+me->query("jiali")/10)*lvl/100*(9+random(21));
			me->add("neili", -lvl*3);
			me->add("jingli", -lvl);
			if ((int)damage/target->query("eff_qi")*100>=100) {
				message_vision(HIR "只听噗的一声响，$N的五根手指已抓断了$n的喉管。\n\n" NOR, me,target);
				target->die();
				me->delete_temp("tong");
				return 1;
                	}

                	if ((int)damage/target->query("eff_qi")*100>=50&&(int)damage/target->query("eff_qi")*100<100)
				message_vision(HIR "只听唰的一声，$n的喉头已被扯下一大块皮肉，顿时血流如注。\n\n" NOR, me,target);
                	if ((int)damage/target->query("eff_qi")*100<50)
                        	message_vision(HIR "只听哧的一声，$n的喉部已被抓出了五条鲜血淋漓的爪痕。\n\n" NOR, me,target);
                	target->receive_damage("qi",damage,me);
                	target->receive_wound("qi", damage, me);
                	str = COMBAT_D->status_msg((int)target->query("eff_qi") * 100 /(int)target->query("max_qi"));
                	message_vision("($N"+str+")\n", target);
        	}
	} else {
		object ob;
		string msg;
		int damage, finger, skill, jiali, my_rate, your_rate;

		jiali=(int)me->query("jiali");


		if(me->query_skill("jinding-zhang")) {
			me->set_temp("memory",me->query_skill("jinding-zhang",1));
			me->set_skill("jinding-zhang", dk/2+me->query_skill("jinding-zhang",1)/2);
		} else me->set_skill("jinding-zhang", dk);
		me->map_skill("strike", "jinding-zhang");
		me->prepare_skill("strike", "jinding-zhang");


		msg = HIY "\n$N突然间全身骨骼中发出劈劈拍拍的轻微爆裂之声，炒豆般的响声未绝，右掌已向$n胸口击去。\n\n"NOR;
		msg += HIG"这一掌是峨嵋派的绝学，叫做“佛光普照”。这“佛光普照”的掌法便只一招，而且这\n";
		msg += HIG"一招也无其他变化，招式平平淡淡，一成不变，可是其威力之生，就在于以峨嵋派绝顶\n";
		msg += HIG"内功作为根基。一掌既出，内力如排山倒海一般袭来，敌人挡无可挡，避无可避。\n\n";

		if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
		{
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			if(damage > 3000) damage = 3000;
			if(damage < 500) damage = 500;
			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIR"猛听得砰然一声大响，$N已打中在$p胸口.\n"NOR;

			if ( damage < 400) {
				msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
			}else if ( damage < 600) {
				msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
			}else if ( damage < 1000) {
				msg += YEL"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。\n"NOR;
			}else if ( damage < 2000) {
				msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;
			}else if ( damage < 3000) {
				msg += RED"只听一声巨响，$n口中鲜血狂喷，全身骨骼碎裂。\n"NOR;
			}else {
				msg += RED"只听一声巨响，$n全身骨骼碎裂，竟被这排山倒海般的一击将身子打成了两截。\n"NOR;
			}
			msg += NOR;
			me->start_busy(2+random(2));
		}
		else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
				&&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
		{
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 2;
			if(damage > 2000) damage = 2000;
			if(damage < 350) damage = 350;

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIY"$p眼看这一招来势汹汹，知道难于对付，连忙发力抵抗，猛听得砰然一声大响，$N已打中在$p胸口.\n"NOR;
			if ( damage < 400) {
				msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
			}else if ( damage < 600) {
				msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
			}else if ( damage < 1000) {
				msg += RED"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。\n"NOR;
			}
			else msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;

			msg += NOR;
			target->add( "neili", -damage/4 );
			me->start_busy(2+random(2));
		}
		else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
			random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
		{
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 3;
			if(damage > 1000) damage = 1000;
			if(damage < 250) damage = 250;

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIM"$p眼看这一招来势汹汹，慌忙使出本门身法，向侧跃出数丈，可是这佛光普照蕴藏峨眉内家上乘内功，\n";
			msg += "方圆数丈都被神功所震撼，$p只觉得后心一震，已被劈空掌力所伤.\n"NOR;

			if ( damage < 400) {
				msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
			}else if ( damage < 600) {
				msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
			}else if ( damage < 1000) {
				msg += RED"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。，\n"NOR;
			}
			else msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;

			msg += NOR;
			target->add( "neili", -damage/4 );
			me->start_busy(2+random(2));
		} else {
			msg += HIC"$n眼看这一招来势汹汹，使出本门身法，向後跃出数丈，\n\n"NOR;
			msg += HIW"$N这一招乃是使上了全力，丝毫不留余地。没想到全无用处，不觉脸如死灰，手掌微微发抖。\n" NOR;
			me->add("neili", -jiali*2 );
			me->add("jingli", -me->query("jiajin") );
			me->start_busy(2 + random(2));
			message_vision(msg+"\n", me, target);


			if(me->query_temp("memory")) me->set_skill("jinding-zhang",me->query_temp("memory",1));
			else me->delete_skill("jinding-zhang");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");
			me->delete_temp("tong");
			return 1;
		}

		message_vision(msg+"\n", me, target);
		COMBAT_D->report_status(target);

			if(me->query_temp("memory")) me->set_skill("jinding-zhang",me->query_temp("memory",1));
			else me->delete_skill("jinding-zhang");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");
	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}

