// tuci.c 
// 加入一个常规输出手段 by yhzzyahoo
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	string msg;
	int damage,mm,tt;
	int number,rate,cd_time,cal_temp1,cal_temp2;
	object weapon;

	//pp=target->query_temp("pixie");
	if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「突刺」只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("id") != "xiuhua zhen")
/*    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("id") != "xiuhua zhen") */
        return notify_fail("你右手没拿绣花针,无法施展「突刺」！!\n");
	number=(int)me->query_skill("pixie-jian", 1);
	number=(int)number>>2;
	number+=50;
	if(me->query("neili")<number)
		return notify_fail("你内力不够，不能使出「突刺」一式。\n");

	if(me->query_skill("pixie-jian",1)<100)
		return notify_fail("你辟邪剑法不太熟练，不能使出「突刺」一式。\n");
	
	if (me->query("gender") == "无性")
	{
		rate = 6;
		cd_time = 2+random(2);
	}
	else
	{
		rate = 12;
		cd_time = 4+random(2);
	}

	if ( time() - me->query_temp("px_tuci_time") < cd_time )
	{
		return notify_fail("你真气尚未平复，不能使出「突刺」一式。\n");
	}
	msg = HIG"$N左手轻挥衣袖，似要遮住$n的视线，却突然右手捻出一根针，身形猛起，猛的扎向$n的面门。\n";
	me->set_temp("px_tuci_time",time());
	me->start_busy(random(3));
	me->add("neili", -number);	
	mm=random((int)me->query_skill("dodge"))+(int)me->query_dex();
		//改为激发后的parry，算上后天身法
	tt=random((int)target->query_skill("parry"))+(int)target->query_dex();
//	write("rate数值为:"+rate+","+mm+","+tt+"\n");
	if (me->query("safari_skill/riyue_tuci") && me->query("family/family_name")=="日月神教")
	{
		cal_temp1 = me->query_skill("dodge")>>1;
		cal_temp1 += me->query_skill("kuihua-shengong",1);
		cal_temp2 = cal_temp1/700 + 1;
		if (cal_temp2 > 9)
		{
			cal_temp2 = 9;
		}
		if (me->query("chushi/done") || me->query("betrayer"))
		{
			cal_temp2 /= 2;
			cal_temp2 += 1;
			rate += 1;
		}
		else
		{
			rate -= 1;
		}

		msg += RED"$P轻身飘起，身形突进，尤如闪电，一针刺出！\n" NOR;
	    message_vision(msg, me, target);                

		for (cal_temp1 = 0; cal_temp1 < cal_temp2; cal_temp1++ )
		{
			if (cal_temp1==0)
			{
				if(F_KUNGFU->hit_rate_sk( mm, tt, rate, me, target))
				{
					msg += RED"$p猝不及防，被刺个正着！\n" NOR;
					//target->start_busy(7+random(4));
	                F_KUNGFU->hit_busy( "jiemai", 7+random(4), target );


				}
			    message_vision(msg, me, target);                
			}

			if(F_KUNGFU->hit_rate_sk( mm, tt, rate, me, target))
			{

				if (cal_temp1>0 && cal_temp1 < 5)
				{
					msg = RED"$P身形闪动，反手又是一针，$p视线被挡，被刺个正着！\n" NOR;
				}
				else
				{
					if (cal_temp1 >= 5)
					{
						msg = RED"$P身形忽变，正手又是一针，$p被刺个正着！\n" NOR;
					}
				}
				 message_vision(msg, me, target);                

				damage = me->query_skill("pixie-jian",1) + me->query_skill("kuihua-shengong",1) + 3*me->query_dex();
				damage += random(damage);
				F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
				COMBAT_D->report_status(target);
			}
			else
			{
				 msg = HIY"$p明察秋毫，一低头，躲了过去。\n"NOR; 
				 message_vision(msg, me, target);                

			}
		}
		me->add("neili", -3*number);	
		me->start_busy(1);
	}
	else
	{
		if(F_KUNGFU->hit_rate_sk( mm, tt, rate, me, target))
		{
			msg += RED"$p视线被挡，被$P在面门上刺个正着，惨叫一声，身子急退！！\n" NOR;
			message_vision(msg, me, target);
			damage = 2*me->query_skill("pixie-jian",1)+me->query_skill("kuihua-shengong",1)+3*me->query_dex();
			damage = damage/2 + random(damage);
			F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
			COMBAT_D->report_status(target);
		}
		else
		{
			 msg += HIY"$p明察秋毫，一低头，躲了过去。\n"NOR; 
			 message_vision(msg, me, target);                
		}
	}

	return 1;
}
