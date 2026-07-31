// liuli-jinshen.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 600)
		return notify_fail("你的内功火候不够，无法领悟太元帝经。\n"); 



	if ((int)me->query_skill("parry", 1) < (int)me->query_skill("wanmo-futi", 1))
		return notify_fail("你的基本招架水平有限，无法领会更高深的琉璃金身。\n");

	return 1;
}

string query_txt()
{
	return "要求：内功600，内力3500，等级不能高于基本招架"ZJBR
	"特效：以内力化解攻击者伤害，内力消耗=伤害1.5倍，对比自身(内功激发*15+最大内力/2)和攻击者(内功激发*15+内力/2)，同数值1/1概率触发"
	"，内力低于最大内力的一半则不触发";
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	int ap, dp;
	int cost;

	cost = damage * 3 / 2 ;

	if (! living(me) ||
	    (int)me->query_skill("wanmo-futi", 1) < 100 ||
	    (int)me->query("neili") < cost ||
	    (int)me->query("neili") < me->query("max_neili")/2)
		return;

	ap = ob->query_skill("force") * 15 + ob->query("max_neili")/2;
	dp = me->query_skill("force") * 15 + me->query("neili")/2;

	if (ap / 80 + random(ap) < dp)
	{
		me->add("neili", -cost);
        tell_object(me,HBRED HIC"你默念太元帝经唤出万千神魔护住全身上下，双眼猩红，犹如修罗下凡一般，纹丝不动，人间自有真情在，唯有我被情深伤。用"+cost+"内力抵挡了"+damage+"伤害。"NOR"\n");
		result = ([ "damage": -damage ]);

		switch (random(5))
		{
		case 0:
			result += (["msg" : HBYEL HIR"$n" HBYEL HIR"唤出千千万万神魔笼罩全身猩红万丈，犹如诸天修罗附身，好似全身被万般神魔附体，念道:谁人不是历轮回，喂我不尝孟婆汤，只为地狱再觅他。吾有一式，号令世间群魔。为我所用！！！$N"
					    HBYEL HIR"无从下手。"NOR"\n"]);
					break;
		case 1:
			result += (["msg" : HBWHT HIR"只见$N" HBWHT HIR"这一招打了个正中！然而$n"
					    HBCYN HIR"毫不在意并诵道：归命满月界，净妙神魔尊。慈悲弘誓广，愿度诸含生，多情自古空余恨～。"NOR"\n"]);
			break;
		case 2:
			result += (["msg" : HBYEL HIR"$N" HBYEL HIR"一招正好打在$n" HBYEL HIR"身上，可"
					    "力量犹如石沉大海，丝毫不起作用.....以三十二大神魔相，八十随形庄严其身。令一切有情如我无异，多情自古伤离别！"NOR"\n"]);
			break;
		case 3:
			result += (["msg" : HBRED HIR"$N" HBWHT HIR"一招击在$n" HBWHT HIR"身上，只听$n"
					    HBWHT HIR"一声大喝：身如万魔，内外清，心如鬼魅，净无瑕秽！
$N" HBWHT HIR"反被护体罡气震退了"
					    "数步。"NOR"\n"]);
			break;
		default:
			result += (["msg" : HBCYN HIR"$n" HBWHT HIR"浑若无事的接下了$N"
					    HBWHT HIR"这一招，却没有受到半点伤害....好似修罗刹在世，一身气血浑然天成，眼角眉心腾出一股股黑气，念道:多情总被无情伤，从此堕落修万魔！！！他日再见已陌路，唯有噬其魂，吞其血，方可一解恨。说罢浑身上下似已重铸太元帝经！"NOR"\n"]);
			break;
		}
		return result;
	}
}

int query_effect_parry(object attacker, object me)
{
	int lvl;

	lvl = me->query_skill("wanmo-futi", 1);
	if (lvl < 100) return 0;
	if (lvl < 150) return 50;
	if (lvl < 200) return 80;
	if (lvl < 250) return 10;
	if (lvl < 300) return 80;
	if (lvl < 350) return 120;
	if (lvl < 400) return 100;
	return 150;
}

int practice_skill(object me)
{
	int cost;
	int lvl;

	if ((lvl = me->query_skill("wanmo-futi", 1)) < 300)
				return notify_fail("你对太元帝经的了解甚浅，还不足以自行锻炼。\n");

	cost = 1000 + (lvl - 100) / 3;
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("你的内力不够练太元帝经。\n");

	me->receive_damage("qi", 50);
	me->add("neili", -cost);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wanmo-futi/" + action;
}

