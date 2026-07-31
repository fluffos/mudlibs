// qingdie-shenfa.c 轻蝶身法
// pal 1997.05.26

inherit SKILL;

string *dodge_msg = ({
	"只见$n一招「蝶舞泉边」，身形飘忽不定，躲过了$N这一招。\n",
	"$n一式「凭虚临风」，身形晃动，向一旁飘出，避开了$N这一招。。\n"
	"$n使出「蝶随风飞」，一个空心筋斗向后翻出，避开了$N的凌厉攻势。\n",
	"$n一招「双香凤蝶」，身随意转，$N只觉眼前一花，$n已绕至$N的身后。\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
	if(me->query_skill("dodge",1)<20)
		return notify_fail("你的基本轻功火候不够。\n");
	return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练青蝠身法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

