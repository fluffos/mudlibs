// douzhuan-xingyi 斗转星移

#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
	"只听见「锵」一声，$n用兵刃轻轻一架，改变了$N这一击的方向。\n",
	"但是被$n用手中兵刃引开。\n",
	"但是$n身子一侧，随手转动手中的兵刃，让$N感觉到有力难施。\n",
});

string *unarmed_parry_msg = ({
	"但是被$p双掌一推，$N的攻势顿时变了方向。\n",
	"$n身形一转，$N只觉得的所有的力道全部都击向自己。\n",
	"但是$N感觉像打到棉花上一样，说不出的怪异。\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_enable(string usage) { return usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("parry", 1) < 100)
		return notify_fail("你的基本招架技巧掌握的还不够熟练，无法学习斗转星移。\n");

	if ((int)me->query_skill("parry", 1) < (int)me->query_skill("douzhuan-xingyi", 1)) 
		return notify_fail("你的基本招架水平有限，无法学习更高深的斗转星移。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("斗转星移只能用学(learn)的来增加熟练度。\n");
}

string query_txt()
{
	return "要求：基本招架100"ZJBR
	"特效：化解伤害并对攻击者造成1/2反击伤害，对比自身(招架激发/2+技能等级)和攻击者内功激发，同激发等级1/2概率触发，受阴阳八卦克制";
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp;

	if ((int) me->query_skill("douzhuan-xingyi", 1) < 100 ||
	    ! living(me))
		return;

	mp = ob->query_skill("count");
	ap = ob->query_skill("force") + mp;
	dp = me->query_skill("parry")/2 + me->query_skill("douzhuan-xingyi", 1);

	if (ap / 2 + random(ap) < dp)
	{
		result = ([ "damage" : -damage ]);

		switch (random(3))
		{
		case 0:
			result += ([ "msg" : HIC "$n" HIC "使出姑苏慕容的独门绝技“斗转星移”，把$N"
						HIC "的劲道尽数反击回去。"NOR"\n"+
						COMBAT_D->do_respond(me, ob, damage, 50, HIR "$P只觉一股暗劲翻涌而来，身不由己的击向自己！"NOR"\n")]);
			break;
		case 1:
			result += ([ "msg" : HIC "$n" HIC "使出姑苏慕容的独门绝技“斗转星移”，把$N"
						HIC "的劲道尽数反击回去。"NOR"\n"+
						COMBAT_D->do_respond(me, ob, damage, 50, HIR "$P只觉一股暗劲翻涌而来，身不由己的击向自己！"NOR"\n")]);
			break;

		default:
			result += ([ "msg" : HIC "$N" HIC "一招眼看击中了$n" HIC "，然而$n" HIC "轻轻一接，"
					     "将$N" HIC "的攻击悉数反击回去。"NOR"\n"+
						COMBAT_D->do_respond(me, ob, damage, 50, HIR "$P只觉一股暗劲反击而来，顿时一阵气血翻涌！"NOR"\n")]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(3))
		{
		case 0:
			result = HIY "$n" HIY "身形忽然转个不停，然而$N"
				 HIY "早已看穿其中奥妙，丝毫不受影响，挥招直入。"NOR"\n";
			break;

		case 1:
			result = HIY "$n" HIY "单掌一托，$N"
				 HIY "忽感拿捏不准力道，蓦然警醒，登时变化招式。"NOR"\n";
			break;

		default:
			result = HIY "$n" HIY "轻轻一卸力，但是$N"
				 HIY "已然看出其中四两拨千斤的变化，左右腾挪，让$n"
				 HIY "如意算盘就此落空。"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}

int diffcult_level() { return 200; }

