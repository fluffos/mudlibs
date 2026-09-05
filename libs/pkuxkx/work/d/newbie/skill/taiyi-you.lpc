//taiyi-you   太乙神游
//by zoom
//2003.4.6

inherit SKILL;

string *dodge_msg = ({
	"只见$n一式「神游太虚」，借力转力身子腾空而起，躲过了$N这一招。\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me)
{
	if ((int)me->query_skill("taiyi-you", 1) > 20)
		return notify_fail("你的太乙神游已经无法再提高了。\n");
	return 1; 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if ((int)me->query_skill("taiyi-you", 1) > 20)
		return notify_fail("你的太乙神游已经无法再提高了。\n");
        if( (int)me->query("jingli") < 10 )
                return notify_fail("你的精力太差了，不能练太乙神游。\n");
        me->receive_damage("jingli", 5);
        return 1;
}
