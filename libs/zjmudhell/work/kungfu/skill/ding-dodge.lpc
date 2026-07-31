// ding-dodge.c 丁字步 

inherit SKILL;

string *dodge_msg = ({
	"$n漫不经心的向左迈出一步，刚好避过$N的凌厉攻势。\n",
	"可是$n恰巧往右走了一步，躲过了$N这一招。\n",
	"$n手舞足蹈，毫无章法，偏偏躲过了$N这一招。\n",
	"$n一仰一合，将$N的招法化解于无形之中。\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 )
		return notify_fail("你的体力太差了，迈不开丁字步。\n");

	me->receive_damage("qi", 40);
	return 1;
}

