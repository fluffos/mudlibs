// dian.c 一指禅 - 点
// Written by Doing Lu 1999/2/27

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	object ob;		// 对手的武器
	string msg;
int neili_wound, qi_wound ;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("绝技「点」字决指法只能对战斗中的对手使用。\n");

	if (objectp(weapon = me->query_temp("weapon")))
			return notify_fail("你不能使用武器！\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("你混元一气功的功力不够!\n");

	if( (int)me->query_skill("yizhi-chan", 1) < 150 )
		return notify_fail("你的一指禅太生疏，不会使用「点」字决。\n");

	if ( me->query("neili") < 500)
		return notify_fail("你的内力不够，现在无法使用「点」字决。\n");
	me->add("neili", -100);

	msg = HIY " $N深深吸了一口气，伸出中指，使出佛门伏魔无上绝技指法，慢慢得向$p点了过了。\n";

	ob = target->query_temp("weapon");
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 ) 
	{
                qi_wound = target->query("qi") - 200;
if (qi_wound < 10)qi_wound=10;
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
						"$N的这一指正点在$p的丹田上，\n$p只觉得一口"
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
						"的一声二指相交，$p身行微晃，脸如金纸。\n";
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
						"这一指正点在$p的檀中大穴。\n";
		target->receive_damage("qi", qi_wound/2);
		target->receive_wound("qi", qi_wound/3);
//					target->unconcious();
					damage = 0;
					break;
				case 1:
					msg += HIR " $p一转念，已经想出了九十九种化解的办法，"
						"尚未来得及施展，只听「嗤」的一声，已被$N点中檀"
						"中大穴。\n";
		target->receive_damage("qi", qi_wound/2);
		target->receive_wound("qi", qi_wound/3);

//					target->unconcious();
					damage = 0;
					break;
				}
			}
			if (damage > 0)
				target->receive_damage("qi", target->query("max_qi") * damage / 12);
			message_vision(msg + NOR, me, target);
			return 1;
		}
		if (random(3) >=1 )
		{
			msg += HIR " $p忙用" + ob->query("name") + "招架，只觉得虎口剧震，所幸兵器完好无损。\n" NOR;
		} else
		{
			msg += HIW " $p连忙招架，只听见「啪」地一声，$p手中的" + ob->name()
				+ "寸寸断裂，散落一地！\n";
			ob->unequip();
			ob->move(environment(target));
			ob->set("name", "断掉的" + ob->query("name"));
			ob->set("value", 0);
			ob->set("weapon_prop", 0);
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
				msg += " $p突然向后飘去，疾若闪电，令$N这一指所有的后继变化无从施展。\n";
				busy = 1;
				break;
			}
		} else
		if (target->query_skill("force") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $p脸色凝重，缓缓出掌，以拙对拙，竟然让$N无从下手，只得收指。\n";
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
				msg += " $p一指点出，看上去恍若也是佛门精妙指法，$N一呆，攻势顿缓。\n";
				busy = 2;
				break;
			case 2:
				msg += "$p摄住心神，真气贯注，堪堪封住了$N的进攻。\n";
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
