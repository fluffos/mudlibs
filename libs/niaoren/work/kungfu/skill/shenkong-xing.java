//
// shenkong-xing.c 身空行
// designed by secret(秘密)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$n使出一招「心空」，身體向側后飄去 \n",
        "dodge" : 15,
]),
([      "action" : "$n使出一招「誓言空」，雙足一點，躍至數丈之外 \n",
        "dodge" : 30,
]),
([      "action" : "$n使出一招「蓮空」，身形一變，滑至$N身后 \n",
        "dodge" : 45,
]),
([      "action" : "$n大吼一聲，使出一招「大安空」，從$N頭頂越過 \n",
        "dodge" : 60,
]),
([      "action" : "$n使出一招「佛空」，如輕鴻般飄去，瞬間又閃至$N面前 \n",
        "dodge" : 75,
]),
([      "action" : "$n使出一招「金剛空」，頓時$N周圍都是$n的身影 \n",
        "dodge" : 90,
]),
});


mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shenxingkong",1);

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	if (level < 30 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的體力太差了，不能練習身空行。\n");
	me->receive_damage("qi", 20);
	return 1;
}
