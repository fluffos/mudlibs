// qiankun-danuoyi
// yuer

inherit SKILL;

string *parry_msg = ({
	"$N左手一晃，$n的$v不由偏到一边。内力斜引，将$n的攻势挪移推卸了开去。\n",
	"$N手指一拂，$n的一击之力毫无半点着力之处。\n",
	});

int valid_enable(string usage) { return (usage == "parry"); }
int valid_learn(object me) { return 1; }

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int practice_skill(object me)
{
                      return notify_fail("乾坤大挪移不能练。\n");
               return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qiankun-danuoyi/" + action;
}


