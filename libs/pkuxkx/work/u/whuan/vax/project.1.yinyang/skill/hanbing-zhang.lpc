// hanbing-zhang.c-寒冰绵掌
inherit SKILL;
mapping *action = ({
([      "action": "$N使出「阳关三尺雪」，左脚虚步前移，左掌后移
右掌轻轻拂向$n的$l,姿势妙曼无比",
        "dodge": -15,
        "parry": 10,
        "force": 150,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「乱云低薄雾」，双掌上下翻飞，全身一纵，
右掌前探，拍向$n的$l",
        "dodge": -10,
        "parry": 15,
        "force": 150,
        "damage_type": "瘀伤"
]),
([      "action": "$N侧身移步，使出「急雪舞回风」，腰身蓦地回旋
左掌护住胸口，右掌缓慢推出，无声无息地按向$n的$l",
        "dodge": -20,
        "parry": -10,
        "force": 250,
        "damage_type": "瘀伤"
]),
([      "action": "$N深吸一口气，使出「卷地白草折」，两脚交错前踏，
翻起地上尘土迷惑$n的双眼，双掌寂然印向$n的$l",
        "dodge": -5,
        "parry": 20,
        "force": 150,
        "damage_type": "瘀伤"
]),
([      "action": "$N不暇思索地使出「穿庭作飞花」，左掌上架，迈步
上前，右掌略划半弧，凌利无比地劈向$n的$l",
        "dodge": -15,
        "parry": 10,
        "force": 250,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「万树梨花开」，提身一纵，在空中斜扑向$n
双掌一前一后地拍向$n的$l",
        "dodge": -20,
        "parry": 5,
        "force": 350,
        "damage_type": "瘀伤"
]),
([      "action": "$N足不抬,身影微幌倏地后退，使出「寒重晚来风」，
双掌挟着雪崩之声，印向$n的$l",
        "dodge": -15,
        "parry": 10,
        "force": 250,
        "damage_type": "瘀伤"
]),
([      "action": "$N展开轻功，如一溜烟般绕到$n的背后，使出「寒冰现芳华」，
双掌呈火焰型交叉,带着割肤掌风，重重拍向$n的$l",
        "dodge": -30,
        "parry": -10,
        "force": 380,
        "damage_type": "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="myingzhua-gong"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练寒冰绵掌必须空手。\n");
        if ((int)me->query_skill("shenghuo-xinfa", 1) < 20)
           return notify_fail("你的圣火心法火候不够，无法练寒冰绵掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练寒冰绵掌。\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练寒冰绵掌。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"hanbing-zhang/" + action;
}
string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});
string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_yinyang()
{
	return "少阴";
}