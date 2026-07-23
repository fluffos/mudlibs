// dian.c 银索金铃 点穴
// By Kayin @ CuteRabbit Studio 1999/3/21 new
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	object ob;		
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("点穴只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("yinsuo-jinling", 1) < 120 )
		return notify_fail("你的银索金铃不够纯熟，还不能认穴\n");

	if( (int)me->query_skill("yunv-xinfa",1)< 135)
		return notify_fail("你的内功修为太差，劲力无法封闭穴道\n");
	
	if( (int)me->query("max_neili")<1000)
		return notify_fail("你的内力不足以施展点穴功夫.\n");
			
	if ( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不够点穴。\n");
	me->add("neili", - 300);

	msg = CYN " $N"CYN"手上金铃"CYN"飞出,使出银索金铃的上乘点穴功夫,直取$p"CYN"的大椎穴。\n";

	ob = target->query_temp("weapon");
	if( random( me->query("combat_exp") ) > random( target->query("combat_exp") )*2 )
	{
		me->start_busy(2);
		if (! objectp(ob))
		{
			int damage = 0;

			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += HIR " $p连续变了几种上乘身法，终于没能躲过，"
						"$N的金铃正点在$p的檀中穴上，$p只觉得一口"
						"凉气，自丹田而上，心里有种说不出的难受。\n";
					damage = 3;
					break;
				case 1:
					msg += HIR " $p轻身飘开，身法灵动之极，众人正要喝彩，"
              					"听「噗」的一声，如击败革，$p脸色煞白，摇摇欲坠。\n";
					damage = 5;
					break;
				}
			} else
			if (target->query_skill("force") > 200 && random(2) == 0)
			{
				switch(random(2))
				{
				case 0:
					msg += HIR " $p冷哼一声，自持内力高强，反手出招，「啵」"
						"的一声轻响，掌铃相交，$p身行微晃，脸如金纸。\n";
					damage = 3;
					break;
				case 1:
					msg += HIR " $p一声长啸，双手幻化出无数掌影，护住身前。"
						"只听「嗤」的一声，掌影顿消，$p已经变得脸色惨白。\n";
					damage = 4;
					break;
				}
			} else
			{
				switch(random(2))
				{
				case 0:
					msg += HIR " $p看到这招，竟然不知躲避，「嗤」的一声，$N"
						"的金铃正点在$p的大椎穴上,$p全身酸软,跌倒在地。\n";
if ((int)target->query("qi")< 100000)
				{
				target->receive_damage("qi", target->query("qi")/3);
                                target->receive_wound("qi", target->query("qi")/3);
}
//					target->unconcious();
					damage = 0;
					break;
				case 1:
					msg += HIR " $p一转念，已经想出了九十九种化解的办法，"
						"尚未来得及施展，只听「嗤」的一声，已被$N点中大椎穴,$p全身酸软,跌倒在地。\n";
if ((int)target->query("qi")< 100000)
				{

				target->receive_damage("qi", target->query("qi")/3);
                                target->receive_wound("qi", target->query("qi")/3);
}
//					target->unconcious();
					damage = 0;
					break;
				}
			}
			if (damage > 0)
				target->receive_damage("qi", target->query("qi")/4);
                                target->receive_wound("qi", target->query("qi")/5);
			message_vision(msg + NOR, me, target);
			return 1;
		}

                if (!ob)
		return notify_fail("你还想用招，但对方没有兵器，你的招工用不了\n");

		if (ob->query("item_make"))
		{
			msg += HIR " $p忙用" + ob->query("name") + "招架，只觉得虎口剧震，所幸兵器完好无损。\n" NOR;
		} else
		{
if (ob)
{
			msg += HIW " $p连忙招架，只听见「啪」地一声，$p手中的" + ob->name()
				+ "寸寸断裂，散落一地！\n";
			ob->unequip();
			ob->move(environment(target));
			ob->set("name", "断掉的" + ob->query("name"));
			ob->set("value", 0);
			ob->set("weapon_prop", 0);
}
		}
		target->start_busy(2);
	} else
	{
		int busy = 0;
		if (target->query_skill("dodge") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $p一声轻笑，连续变化了几次身法，扰人耳目，一时让$N无法进攻。\n";
				busy = 2;
				break;
			case 1:
				msg += " $p突然向后飘去，疾若闪电，令$N所有的后继变化无从施展。\n";
				busy = 1;
				break;
			}
		} else
		if (target->query_skill("force") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $p脸色凝重，加快格架，以巧对巧，让$N无从下手，只能收回金铃。\n";
				busy = 3;
				break;
			case 1:
				msg += " $p满脸不屑，冷笑一声，双掌齐出，其快无比，令$N只能回招自救。\n";
				busy = 1;
				break;
			}
		} else
		{
			switch (random(3))
			{
			case 0:
				msg += " $p左摇右晃，看上去毫无章法，偏偏躲过了$N这一击。\n";
				busy = 2;
				break;
			case 1:
				msg += " $p金铃点出，看上去灵动精妙，$N一呆，攻势顿缓。\n";
				busy = 2;
				break;
			case 2:
                if (ob)
{
				msg += "$p摄住心神，真气贯注" + ob->query("name")
					 + "，堪堪封住了$N的进攻。\n";
}
				busy = 2;
				break;
			}
		}
		target->start_busy(busy);
		me->start_busy(4);
	}
	message_vision(msg + NOR, me, target);

	return 1;
}
