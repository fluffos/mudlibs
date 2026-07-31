// qingmang-jian.c 青蟒剑(刀)法

inherit SKILL;

string *dodge_msg = ({
"似乎$N每一招都能制$n的死命，可是$n总是或反打、或闪避，一一拆解开去。\n",
"却见$n一低头，从$N底下扑了上去，左臂随势格向$n的右臂。\n",
"那知$n身形一幌，轻轻巧巧地避过了$N的攻击。\n",
"$n飞起右足，踢向$N手腕，一招「叶底飞燕」反攻为守。\n"
});

string  *msg = ({
"$N刷刷刷连出三招，使出「青蟒吐信」，但见$w闪动，犹如蟒蛇吐信一般，不知要劈向何处",
"$N得理不让人，又是一招，$w直挥$n面门，逼得$n急忙侧头避让",
"$N左脚又在$n小腿上一扫，想将$n拌倒，跟着$w一抖，已指住$n咽喉",
"$N一声冷笑，手中$w迎面砍下，直劈$n$l",
"$N一下冲到$n身前，突然之间拔出$w，便往$n头上砍了下去",
"$N突然一下拔$w挥击，既是突如其来，行动又是快极，$n全无闪避的馀裕",
"$N$w挺出，一招「毒蛇出洞」，向$n当胸劈去，势道甚是劲急",
"$N叫声：「好！」$w圈转，削向$n$l",
"$N一招「灵舌吐信」，$w尖快绝无比点向$n的$l"
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry" 
	|| usage == "dodge" || usage == "blade" 
	|| usage == "axe" || usage == "dagger"
	|| usage == "hook";
}

mapping query_action(object me, object weapon)
{
	return ([
		"action":	msg[random(sizeof(msg))],
                "damage":	60 + random(100),
		"damage_type":	random(2)?"刺伤":"割伤",
		"dodge":	random(30),
		"force":	150+random(300),
		"parry":	random(30),
        ]);
}

string query_dodge_msg(object weapon)
{        
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	return notify_fail("NPC武功，不对玩家开放。\n");
}
