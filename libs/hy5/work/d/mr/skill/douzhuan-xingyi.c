// douzhuan-xingyi 斗转星移
// 1997-2-14
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
YEL"蓦地里一股力道飞来，将$n一引一带，$n身子轻轻越起，身行落在一旁"NOR,
BLU"$n当下一股内力冲向$l，$N击向$n的$l的招数莫名奇妙的溜滑向一旁"NOR,
HIW"$n双手前探，左臂搭上$N右臂，右臂使出$N的招数将$N此招化去"NOR,
HIY"$n星移斗转，$N这招莫名其妙的在中途转了方向，直奔自己袭来"NOR,
YEL"$n作壁上观，双手与对方相交数掌，谈笑间竟使出$N成名技艺，使得$N不知如何是好"NOR,
BLU"$n凝神运气向$N猛攻快打，使出的招数好似$N的成名绝技，把$N的招数化于无行"NOR,
HIW"只见$n身如飘风，恰似漫天星移，诡异地一式，双掌动向无定不可捉摸地拍向$N的$l",NOR,
HIY"$n身行飘忽不定，在星移斗转之间反用$N的招数击向$N，却令人$N百思不得其解",
});

int valid_enable(string usage)
{
	return usage == "parry";
}

string query_parry_msg(object weapon)
{
	if (!weapon) return 0;
	if (weapon->query("skill_type") == "sword")
		return parry_msg[random(sizeof(parry_msg))] + "。\n";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("学习斗转星移必须空手。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 80)
                return notify_fail("你的神元功火候不够，无法学斗转星移。\n");
        return 1;
}

int practice_skill(object me)
{
	return notify_fail("斗转星移只能通过领悟来提高，无法通过练习来提高。\n");
}

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}
