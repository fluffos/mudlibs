// kongming.c  空明拳

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N使一招「"+WHT+"空屋住人"+NOR+"」，双手轻飘飘地箍向$n$l",
	"force" : 250,
	"attack": 55,
	"dodge" : 70,
	"parry" : 60,
	"damage": 10,
	"lvl"   : 0,
	"skill_name" : WHT"空屋住人"NOR,
	"damage_type": "瘀伤"
]),
([      "action": "$N左掌一平，右掌一伸，一招「"+CYN+"空碗盛饭"+NOR+"」直拍$n的$l",
	"force" : 270,
	"attack": 60,
	"dodge" : 80,
	"parry" : 80,
	"damage": 15,
	"lvl"   : 30,
	"skill_name" : CYN"空碗盛饭"NOR,
	"damage_type": "瘀伤"
]),
([      "action": "$N身形绕$n一转，双手上撩,一招「"+MAG+"空钵装水"+NOR+"」击向$n$l",
	"force" : 300,
	"attack": 75,
	"dodge" : 100,
	"parry" : 100,
	"damage": 20,
	"lvl"   : 60,
	"skill_name" : MAG"空钵装水"NOR,
	"damage_type": "瘀伤"
]),
([      "action": "$N左掌一按，右掌一挥,一招「"+BLU+"虚怀若谷"+NOR+"」拍向$n的$l",
	"force" : 320,
	"attack": 75,
	"dodge" : 110,
	"parry" : 100,
	"damage": 25,
	"lvl"   : 90,
	"skill_name" : BLU"虚怀若谷"NOR,
	"damage_type": "瘀伤"
]),
([      "action": "$N使一招「"+YEL+"空山鸟语"+NOR+"」，$n的$l已围在$N的重重掌影之下",
	"force" : 340,
	"attack": 80,
	"dodge" : 130,
	"parry" : 120,
	"damage": 30,
	"lvl"   : 120,
	"skill_name" : YEL"空山鸟语"NOR,
	"damage_type": "瘀伤"
]),
([      "action": "$N神色一敛，使出「"+GRN+"我心空明"+NOR+"」，围绕$n的$l接连出掌",
	"force" : 370,
	"attack": 85,
	"dodge" : 140,
	"parry" : 130,
	"damage": 40,
	"lvl"   : 150,
	"skill_name" : GRN"我心空明"NOR,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage == "unarmed" ||  usage == "parry"; }

int valid_learn(object me)
{
	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练空明拳必须空手。\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力不到1000，无法练空明拳。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，无法练空明拳。\n");

	if ((int)me->query_skill("unarmed", 1) < 120)
		return notify_fail("你的基本拳脚火候不够，无法练空明拳。\n");

	if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("kongming-quan", 1))
		return notify_fail("你的基本拳脚水平有限，无法领会更高深的空明拳。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i - 1]["lvl"])
			return action[i - 1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("kongming-quan", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

string query_txt()
{
	return "要求：空手，内力1000，内功激发150，基本拳脚120，技能等级不能高于基本拳脚"ZJBR
	"特效：招架化解对手的空手攻击，对比自身(拳脚激发/2+技能等级)和攻击者内功激发，同等级1/4概率触发，不受特殊技能克制";
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	int ap, dp;

	if ((int)me->query_skill("kongming-quan", 1) < 100 ||
	    ! living(me) || me->query_temp("weapon") /*||
	    ob->query_temp("weapon")*/)
		return;
	
	if (me->query("family/family_name") != "全真教" && me->query("family/family_name") != "古墓派")
		return;
	
	ap = ob->query_skill("force");
	dp = me->query_skill("unarmed") / 2 +
	     me->query_skill("kongming-quan", 1);

	if (ap / 2 + random(ap) < dp && random(2))
	{
		result = ([ "damage": -damage ]);

		switch (random(3))
		{
		case 0:
			result += (["msg" : HIM "$n" HIM "双臂一格，$N" +
					    HIM "登时觉得自己的力道全然落空。"NOR"\n"]);
			break;
		case 1:
			result += (["msg" : HIM "$n" HIM "随意格挡，让$N" +
					    HIM "只觉得自己全然捕捉不到$n" HIM "的力道。"NOR"\n"]);
			break;
		default:
			result += (["msg" : HIM "$n" HIM "慢慢出拳"
					    "左挡右格，让$N"
					    HIM "只觉得力道无处可使，说不出的难受。"NOR"\n"]);
			break;
		}
		return result;
	}
}

int query_effect_parry(object attacker, object me)
{
	int lvl;

	if (me->query_temp("weapon"))
		return 0;
	
	if (me->query("family/family_name") != "全真教")
		return 0;
	
	lvl = me->query_skill("kongming-quan", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 60;
	if (lvl < 280) return 90;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
	
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("qi", 50);
	me->add("neili", -60);
	return 1;
}
//等级提升，是否学会新的招式
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}

string perform_action_file(string action)
{
	return __DIR__"kongming-quan/" + action;
}
