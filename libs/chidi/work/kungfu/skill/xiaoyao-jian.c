//
//xiaoyao-jian  逍遥剑法
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N身形微动，一招「赤练长虹」手中$w化做一道白虹，直刺向$n的胸前",
        "skill_name" : "赤练长虹",
        "force" : 120,
        "dodge" : 5,
        "parry" : 20,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使一招「峰回路转」，看似漫不经心，忽然一剑直出，$w飞刺$n",
        "skill_name" : "峰回路转",
        "force" : 160,
        "dodge" : 0,
        "parry" : 8,
        "lvl" : 15,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
([      "action" : "$N轻提$w，舞起朵朵剑花，一招「纷纷扬扬」，刺向$n全身",
        "skill_name" : "大风起兮",
        "force" : 220,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 30,
        "damage" : 50,
        "damage_type" : "刺伤",
]),
([      "action" : "$N脚步轻移，身形飘忽，一招「风吹落花」，$w同是刺向$n的各处要害",
        "skill_name" : "北燕南飞",
        "force" : 240,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 50,
        "damage" : 50,
        "damage_type" : "刺伤",
]),
([      "action" : "$N身形变幻，反手一剑，一招「回看风云」，急刺$n胸前",
        "skill_name" : "回看风云",
        "force" : 270,
        "dodge" : 20,
        "parry" : 15,
        "lvl" : 80,
        "damage" : 60,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「笑看春风」，看似轻描淡写，却处处击向$n全身要穴",
        "skill_name" : "笑看春风",
        "force" : 300,
        "dodge" : 35,
        "parry" : 50,
        "lvl" : 100,
        "damage" : 60,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使一式「月光满地」，$w舞成一道剑光，处处迷茫着剑气，攻向$n",
        "skill_name" : "月光满地",
        "force" : 300,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 130,
        "damage" : 80,
        "damage_type" : "刺伤",
]),
([      "action" : "$N劲运于$w,一招「无声无息」，$w却以极慢的速度直直向$n刺去   ",
        "skill_name" : "无声无息",
        "force" : 500,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 150,
        "damage" : 100,
        "damage_type" : "刺伤",
]),


});


int valid_enable(string usage) { return usage == "sword" ; }


int valid_learn(object me)
{
	if ((int)me->query_skill("blade", 1) >= 30)
		return 1;
	else if ((int)me->query_skill("sword", 1) < 30)
		return notify_fail("你的基本剑法太差了，练不了逍遥剑法。\n");
	}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("xiaoyao-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 20)
		return notify_fail("你的体力不够，练不了逍遥剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

