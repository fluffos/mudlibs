// cimu.c 
// 去掉刺目叫杀，改成群攻 by yhzzyahoo
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
	int pp,damage,mm,tt;
	object *enemy;
	int count,number,rate;
	object weapon;

	//pp=target->query_temp("pixie");
	if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「刺目」只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("id") != "xiuhua zhen")
/*    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("id") != "xiuhua zhen") */
        return notify_fail("你右手没拿绣花针,无法刺敌人眼睛！!\n");

	if(me->query("neili")<200)
		return notify_fail("你内力不够，不能使出「刺目」一式。\n");

	if(me->query_skill("pixie-jian",1)<120)
		return notify_fail("你辟邪剑法不太熟练，不能使出「刺目」一式。\n");
	

	if ( time() - me->query_temp("px_cimu_time") < 5 )
	{
		return notify_fail("你真气尚未平复，不能使出「刺目」一式。\n");
	}
	msg = HIG"$N使出辟邪剑法法「刺目」诀，捻出一根绣花针，身形猛起，从$n的头上掠过的同时手中绣花针刺向$n的双目。\n";
    enemy = me->query_enemy();
	if (me->query("gender") != "无性")
	{
		count = 1;
	}
	else
	{
		count = sizeof(enemy);
		if (count < 1)
		{
			return notify_fail("「刺目」只能对战斗中的对手使用。\n");
		}
		if (count > 6 )
		{
			count = 6;
		}
		number = (int)(me->query_skill("pixie-jian",1)/350) + 1;
		if (count > number)
		{
			count = number;
		}//350级涨1个目标，最多6个
	}
	me->set_temp("px_cimu_time",time());
	me->start_busy(random(3));
	me->add("neili", -200);	
	for (number = 0; number < count; number++ )
	{
		if(me->query("neili")<200)
			return notify_fail("你内力不够，不能使出「刺目」一式。\n");
//		enemy[number]->set_temp("pixie",(int)(enemy[number]->query_temp("pixie")+10));
	//	pp=(int)enemy[number]->query_temp("pixie")+10;
		//把dodge改为激发后的dodge，给feiying增加点用处,算上后天身法
		mm=random((int)me->query_skill("dodge"))+(int)me->query_dex();
		//改为激发后的parry，算上后天身法
		tt=random((int)enemy[number]->query_skill("parry"))+(int)target->query_dex();
		if( enemy[number]->is_busy() ) me->set_temp("cimu",1);
		if (enemy[number] == target)
		{
			rate = 4;
		}
		else
		{
			rate = 6;
		}
		if(!enemy[number]->is_busy() && F_KUNGFU->hit_rate(me->query("combat_exp"), (int)enemy[number]->query("combat_exp"), rate, me, enemy[number]) ) 
		{
			msg += "$p眼前出现千万支剑影，心神大乱，被$P攻了个措手不及。\n" NOR;
			//enemy[number]->start_busy(3+random(3));
			F_KUNGFU->hit_busy( "jiemai", 3+random(3), enemy[number] );
			me->set_temp("cimu",1);

		}
		else 	
			msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		message_vision(msg, me, enemy[number]);
		if (enemy[number] == target)
		{
			rate = 7;
		}
		else
		{
			rate = 9;
		}
    //命中率级别C+~C-（存在命中率修正系数，符合random(A)>random(B)*q+p公式，命中率级别不会特别准）
	//改成hit_rate_sk判定的,这个调整值几近于无，放弃
		if((int)me->query_temp("cimu")==1&&
			F_KUNGFU->hit_rate_sk( mm, tt, rate, me, enemy[number]) )	
			//	 F_KUNGFU->hit_rate2( mm, tt, pp+(int)enemy[number]->query("dex")-(int)me->query("dex"),rate, me, enemy[number]) )
		{
			msg = RED"$p被$P刺个正着，惨叫一声，双手掩目，身子一歪，退后丈许！！\n" NOR;
			message_vision(msg, me, enemy[number]);
			damage = 2*(int)me->query_skill("pixie-jian", 1);
			damage = damage + random(damage);
			F_KUNGFU->hit_wound("qi", damage+50, damage/2, me, enemy[number]);
			COMBAT_D->report_status(enemy[number]);
			me->add("neili", -150);
			me->start_busy(random(4));
			enemy[number]->delete_busy();
			enemy[number]->kill_ob(me);
	//		enemy[number]->set_temp("pixie",0);
		}
	}
	me->set_temp("cimu",0);
	return 1;
}
