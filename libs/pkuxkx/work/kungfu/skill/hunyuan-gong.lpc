// hunyuan-gong.c -混元功
inherit FORCE;

string check() { return "force"; }
mapping *action = ({
([      "action" : "$N合掌抱球，猛吸一口气，一式「湮雨缥渺」，双掌疾推向$n的肩头",
        "force" : 200,
        "dodge" : 15,
        "damage" : 5,
        "lvl" : 0,
        "skill_name" : "湮雨缥渺",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招「白云出岫」，双手划了个半圈，按向$n的$l",
        "force" : 220,
        "dodge" : 10,
        "damage" : 5,
        "lvl" : 9,
        "skill_name" : "白云出岫",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左掌划一半圆，一式「长虹贯日」，右掌斜穿而出，疾拍$n的胸前大穴",
        "force" : 240,
        "dodge" : 15,
        "damage" : 5,
        "lvl" : 19,
        "skill_name" : "白虹贯日",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
        "force" : 260,
        "dodge" : 10,
        "damage" : 10,
        "lvl" : 39,
        "skill_name" : "云断秦岭",
        "damage_type" : "瘀伤"
]),
([       "action" : "$N左手虚划，右手一记「青松翠翠」击向$n的$l",
        "force" : 300,
        "dodge" : 15,
        "damage" : 10,
        "lvl" : 49,
        "skill_name" : "青松翠翠",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出「天绅倒悬」，右手击向$n的$l，左手攻向$n的裆部",
        "force" : 320,
        "dodge" : 20,
        "damage" : 15,
        "lvl" : 69,
        "skill_name" : "天绅倒悬",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N全身越起，一招「无边落木」，向$n的$l击去",
        "force" : 340,
        "dodge" : 15,
        "damage" : 20,
        "lvl" : 79,
        "skill_name" : "无边落木",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手握拳，狂喉一声，一式「高山流水」奋力打向$n的$l",
        "force" : 350,
        "dodge" : 10,
        "damage" : 20,
        "lvl" : 89,
        "skill_name" : "高山流水",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左掌护胸，右拳凝劲后发，一式「金玉满堂」，缓缓推向$n的$l",
        "force" : 380,
        "dodge" : 15,
        "damage" : 20,
        "lvl" : 99,
        "skill_name" : "金玉满堂",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手狂舞，使出「风伴流云」，向$n的$l锤去",
        "force" : 400,
        "dodge" : 15,
        "damage" : 20,
        "lvl" : 109,
        "skill_name" : "风伴流云",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return  usage=="strike" || usage=="parry"||usage=="force"; }

int valid_combine(string combo) { return combo=="poyu-quan"; }



string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
		mapping *actions=({});
        int i, level;
        level   = (int) me->query_skill("hunyuan-gong",1);
        for(i=0; i <sizeof(action); i++)
                if(level > action[i]["lvl"])
					actions+=({action[i]});
		return actions[random(sizeof(actions))];
}
/*int valid_learn(object me)
{
	return notify_fail("混元功只能由外而内练习获得。\n");
}*/
int practice_skill(object me)
{
	return notify_fail("混元功只能修炼提高。\n");
}

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
	return __DIR__"hunyuan-gong/" + action;
}
string exert_function_file(string func)
{
        return __DIR__"hunyuan-gong/" + func;
}

string translate(string skill)
{
  return "huashan-xinfa";
}
