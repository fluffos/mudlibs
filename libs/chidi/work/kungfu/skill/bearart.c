// bearart.c 东瀛忍术
// 青云(diabio)编于2001年版权所有

inherit SKILL;

int valid_enable(string usage)
{
        return (usage=="taoism") || (usage=="parry");
}

string perform_action_file(string action)
{
	return __DIR__"bearart/" + action;
}

