//gumu yj+lw+xh,xh add app 1
//liu 2002

#include <ansi.h>

int gumu(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 0 )
	{
		object ob;
		string msg;
		int damage,jiali,jiajin;

		jiali = (int)me->query("jiali");
		jiajin= (int)me->query("jiajin");

		msg = HIB "\n$N悄退数步似要坐倒，右手支颐，左袖轻轻向$n挥出，长叹一声，脸现寂寥之意。\n\n"NOR;

		msg += HIY"这是“美女拳法”最后一招的收式，叫作“古墓幽居”，却是杨过所自创，林朝英固然\n";
		msg += HIY"不知，即便是小龙女也是不会。当年杨过掌年学全了美女拳法之后，心想祖师婆婆姿容\n";
		msg += HIY"德行不输于古代美女，武功之高更不必说，这路拳法中若无祖师婆婆在，算不得有美皆\n";
		msg += HIY"备，于是自行拟了这一招，虽说为抒写林朝英而作，举止神态却是模拟了师父小龙女。\n\n";

		if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/2 ) || !living(target) )
		{
			damage = random(  me->query_skill("force")*2+ me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			if(damage > 3000) damage = 3000;
			if(damage < 600) damage = 600;
			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(0);

			if ( damage < 800) {
				msg += HIR"只听噗的一声，$n被一拳击中小腹，内血翻涌喷口而出。\n"NOR;
			}else if ( damage < 1400) {
				msg += HIR"只听砰、砰两声，$n左眼发青、右眼发紫，狼狈不堪。\n"NOR;
			}else if ( damage < 2600) {
				msg += HIR"结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
			}else {
				msg += RED"只听砰、砰、砰、砰几声巨响，$n被打得骨骼碎裂飞了出去。\n"NOR;
			}
			msg += NOR;
			me->start_busy(2+random(2));
		} else {
			msg += HIG"$n灵光一现，纵身跃起，本能的反应辟开了$N的衣袖。\n\n"NOR;
			me->add("neili", -jiali*2 - 300);
			me->add("jingli", -me->query("jiajin") );
			me->start_busy(2 + random(3));
			message_vision(msg+"\n", me, target);
			me->delete_temp("tong");
			return 1;
		}

		message_vision(msg+"\n", me, target);
		COMBAT_D->report_status(target);

	} else if (random(2)==1){

	int skill = me->query_skill("douzhuan-xingyi",1);

		message_vision(HIM "\n但见$N双臂飞舞，出手挡击回臂反扑发掌奇快，但一招一式清清楚楚自成段落，两只手掌宛似化成了千手千掌！\n"NOR, me,target);

		if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 )
		{
			message_vision( CYN "\n$N心下大骇，飞滚翻扑，始终逃不出$n只掌所围作的圈子! \n" NOR,target,me);

			target->start_busy( skill / (20+random(10)) );
			me->add("neili", -150);
		}
		else
		{
			message_vision( HIY "\n$N气定神弦，看破了$n的诱惑，纵身一跃，跳了开去。\n" NOR,target,me);
			me->start_busy(1+random(3));
			me->add("neili", -100);
			me->delete_temp("tong");
			return 1;
		}

	} else {

        	string msg;
		int damage;
		object weapon,ob;
		int skill, jiali, my_rate, your_rate;

		skill = me->query_skill("xiaohun-zhang",1);
		jiali=(int)me->query("jiali");
		weapon = me->query_temp("weapon");

		me->apply_condition("tong",1);

		if(me->query("married_times"))
        	msg = CYN "\n$N深深思念自己的妻子，哀痛欲绝之际不禁潸然泪下。\n" NOR;
		if(!me->query("married_times"))
			msg = CYN "\n$N深深思念自己的爱人，渐渐心若止水。\n" NOR;
			msg += WHT "$N大喝一声：“黯然消魂掌”！\n"NOR;
			msg += WHT "这套掌法心使臂、臂使掌，全由心意主宰，顿时所有的悲愤与哀怨随掌劲倾泻而出，天地间一片苦涩！\n"NOR;

		damage = random( me->query_skill("force")*2 + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
		if( me->query("eff_qi",1) < me->query("max_qi",1)/2 ) damage = damage * 3;
		if( me->query("eff_qi",1) < me->query("max_qi",1)*2/3 ) damage = damage * 2 ;
		if( me->query("eff_qi",1) < me->query("max_qi",1)*4/5 ) damage = damage * 2 / 3;

		if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/2 ) || !living(target) )
		{
			// whether we need damage limit, not decide yet 
			if(damage > 8000) damage = 8000;
			if(damage < 4000) damage = 4000;

			if (wizardp(me)) printf("damage = %d .\n",damage);	// check damage

			me->add("neili", -jiali*2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", damage/2 + random(damage/2), me);

			msg += HIR"\n$n还在反应之即，猛听得砰然一声大响，正中胸口。\n"NOR;

			msg += NOR;
			me->start_busy(2+random(2));
		}
		else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
				&&  random(target->query_skill("dodge")) < random( me->query_skill("force") )  )

		{
			damage = damage / 2;
			// whether we need damage limit, not decide yet 
			if(damage > 4000) damage = 4000;
			if(damage < 2000) damage = 2000;

			if (wizardp(me)) printf("damage = %d .\n",damage);	// check damage

			me->add("neili", -jiali*2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", damage/2 + random(damage/2), me);

			msg += HIR"\n$n连忙发力抵抗，哪知此招蕴藏着无尽的悲怨，「砰」一声$n被震出数丈。\n"NOR;

			msg += NOR;
			target->add( "neili", -damage/4 );
			me->start_busy(2+random(2));
		}
		else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) 
			&& random( target->query_skill("dodge")*2 ) > random( me->query_skill("force") ) )
		{
			damage = random(  me->query_skill("force")*2 + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 3;
			// whether we need damage limit, not decide yet 
			if(damage < 2000) damage = 2000;
			if(damage < 800) damage = 800;

			if (wizardp(me)) printf("damage = %d .\n",damage);	// check damage

			me->add("neili", -jiali*2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", damage/2 + random(damage/2), me);

			msg += HIR"\n$p知道此掌不可招架，身行刚转，只觉得后心一震！\n"NOR;

			msg += NOR;
			target->add( "neili", -damage/4 );
			me->start_busy(2+random(2));
		} else {
	 		msg += HIG"\n$n知道此掌不可招架，身行一转，逃出了$N的攻击范围。\n\n"NOR;
	 		me->add("neili", -jiali*2 );
	 		me->add("jingli", -me->query("jiajin") );
	 		me->start_busy(2 + random(2));
	 		message_vision(msg+"\n", me, target);
	 		me->delete_temp("tong");
	 		return 1;
		}

		message_vision(msg+"\n", me, target);
		COMBAT_D->report_status(target);

	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}
