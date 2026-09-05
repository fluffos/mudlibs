
#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIR "龙葬八荒" NOR; }

int exclusive_special() { return 1; }

int max_level() { return 4; }

int perform(object me, string skill)
{
	int sklv, plv, damage, dmg, i, num, count, nl = 0;
	string ac, *msg = ({  "攻势不绝", "手腕一翻", "肘部一抬", "沉肩坠肘", "拧腰跨步", "拳随身转", });
	object *allenemy;
	
	if(me->query("age")<18)
		return notify_fail("你还未成年，不能使用特殊技能。\n");

	if (me->query("qi") < 300)
		return notify_fail("你的体力不支，无法使用龙葬八荒。\n");

	sklv = me->query("special_level/devastate");
	if (sklv<1) sklv=1;

	if (me->query("neili")< (sklv+1)*150)
		return notify_fail("你的内力不足，无法使用龙葬八荒。\n");

	if (me->query_temp("weapon") && me->query_temp("secondary_weapon"))
		return notify_fail("你双手都持着兵器，至少要腾出一只手来，才能使用龙葬八荒。\n");
	
	if (!me->is_fighting())
		return notify_fail("你没有在战斗中，不需要使用龙葬八荒。\n");

	plv = me->query("level") - 100;
	if (plv<0) plv = 0;
	
	damage = 5000 + 180 * plv ;
	damage += damage * sklv / 5;
	
	num = sklv + 1;
	allenemy = me->query_enemy();
	count = sizeof(allenemy);

	message_vision(HIR "\n$N" HIR "吐气发音，纵声长啸，犹如轰隆隆一声雷响，正如神龙探首，在半空中猛起个焦雷霹雳！\n"
		+ "啸声未毕，只见$N" HIR "挥出" + ((count>1)?"数":"一") + "拳，如雷声中夹着的狂风，以群龙奔腾、势不可挡之势攻向" 
		+ ((count>1)?"众人":allenemy[0]->query("name")) + HIR "！\n"NOR, me);
	
	for (i=0;i<count;i++)
	{
		if (count>1)
		{
			ac = msg[random(sizeof(msg))];
			msg -= ({ ac });
			message_vision(HIR"\n" + ((i>0)?("$N"+ac+"，又是"):"$N") +"一拳击向$n！\n"NOR, me, allenemy[i]);
		}
		if (F_KUNGFU->hit_rate(me->query("combat_exp"), allenemy[i]->query("combat_exp"), 10-sklv, me, allenemy[i]))
		{
			message_vision(HIM"砰的一声，$n如同被攻城槌锤中，身子向后直飞出一丈远，献血喷得满地。\n"NOR, me, allenemy[i]);
			dmg = damage*4/5 + random(damage*2/5);
			F_KUNGFU->hit_wound("qi", dmg, dmg / 2, me, allenemy[i]);
			COMBAT_D->report_status(allenemy[i]);				
			nl += 150;
		}
		else
		{
			message_vision(HIY"这一拳势如奔雷，$n决计招架不住，只能一个懒驴打滚，狼狈不堪地躲了过去。\n"NOR, me, allenemy[i]);
			nl += 100;
		}
		if ((i+1)>=num) break;
	}
	message_vision("\n", me);
	me->add("neili", - nl);
	me->start_busy(2);
    return 1;
}


