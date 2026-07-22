
inherit SKILL;

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry";}

mapping query_action(object me, object weapon)
{
	return ([
		"action" : "$N一拳打向$n，竟然无声无息，看样子是躲不过了。",
		//"force" : me->query("gender")=="男性"?600:450,
		"force": 100,
		"dodge": 300,
		"parry": 300,
		"attack": 999,
		"damage_type" : "瘀伤",
	]);
}

string perform_action_file(string action)
{
	return __DIR__"ciwei-quan/" + action;
}