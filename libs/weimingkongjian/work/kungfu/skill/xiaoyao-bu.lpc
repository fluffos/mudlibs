// xiaoyao-bu.c 逍遥步
// pal 1997.05.26

inherit SKILL;

string *dodge_msg = ({
	"只见$n一招「风满天」，身形陡然纵起，躲过了$N这一招。\n",
	"$n一式「樱花落」，身形晃动，向一旁飘出，避开了$N这一招。。\n",
	"$n使出「柳随风」，一个空心筋斗向后翻出，避开了$N的凌厉攻势。\n",
	"$n一招「过云龙」，身随意转，$N只觉眼前一花，$n已绕至$N的身后。\n",
	
});

int valid_enable(string usage)
{
	return (usage == "dodge");
}


int valid_learn(object me)
{
	return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练逍遥步。\n");
        me->receive_damage("qi", 30);
        return 1;
}

