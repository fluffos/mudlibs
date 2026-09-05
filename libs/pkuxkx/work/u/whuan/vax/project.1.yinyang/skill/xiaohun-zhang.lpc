inherit SKILL;

mapping *action = ({
([      "action": "$N双掌平平提到胸前，神色沉重的缓缓施出「拖泥带水」推向$n的$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双掌居高临下一招「心惊肉跳」拍向$n的$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "瘀伤"
]),
([      "action": "$N右掌一招「岂人忧天」，迅捷无比地劈向$n的$l",
        "dodge": -10,
        "parry": -10,
        "force": 120,
        "damage_type": "瘀伤"
]),([      "action": "$N双掌施出一招「无中生有」，隐隐带着风声拍向$n的$l",
        "dodge": -15,
        "parry": -10,
        "force": 160,
        "damage_type": "瘀伤"
]),
([      "action": "$N左掌聚成拳状，右掌一招「徘徊空谷」缓缓推向$n的$l",
        "dodge": -10,
        "parry": 10,
        "force": 200,
        "damage_type": "瘀伤"
]),
([      "action": "$N施出一招「行尸走肉」，右掌插腰，左掌劈向$n的$l",
        "dodge": -10,
        "parry": 20,
        "force": 250,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「力不从心」，右掌从不可能的角度向$n的$l推出",
        "dodge": 0,
        "parry": 10,
        "force": 100,
        "damage_type": "瘀伤"]),
([      "action": "$N大吼一声，双掌使出「饮恨吞声」，不顾一切般击向$n",
        "dodge": -25,
        "parry": -10,
        "force": 300,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「庸人自扰」，向$n的$l连拍数掌",
        "dodge": -20,
        "parry": -20,
        "force": 230,
        "damage_type": "瘀伤"
]),
([      "action": "$N身形滑动，双掌使一招「倒行逆施」一前一后按向$n的$l",
        "dodge": -10,
        "parry": 20,
        "force": 160,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「废寝忘食」，身形飞起，双掌并在一起向$n的$l劈下",
        "dodge": -20,
        "parry": 30,
        "force": 250,
        "damage_type": "瘀伤"
]),
([      "action": "$N双掌立起，使出「六神不安」向$n连砍六下",
        "dodge": -20,
        "parry": 20,
        "force": 270,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「孤魂只影」，左掌封住$n的退路，右掌斜斜地劈向$l",
        "dodge": -15,
        "parry": 20,
        "force": 220,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「穷途末路」，双掌软绵绵地拍向$n的$l",
        "dodge": -25,
        "parry": 10,
        "force": 350,
        "damage_type": "瘀伤"
]),
([      "action": "$N脚下一转，突然欺到$n身前，一招「面无人色」拍向$n的$l",
        "dodge": -20,
        "parry": 40,
        "force": 330,
        "damage_type": "瘀伤"
]),
([      "action": "$N门户大开，一招「想入非非」向$n的$l劈去",
        "dodge": -25,
        "parry": 1,
        "force": 320,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「呆若木鸡」，双掌由下往上击向$n的$l",
        "dodge": -15,
        "parry": 40,
        "force": 350,
        "damage_type": "瘀伤"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练黯然销魂掌必须空手。\n");
	if (me->query("gender")!="男性"&&(int)me->query_skill("xiaohun-zhang",1)>100)
		return notify_fail("你不是男性，无法领悟「黯然销魂掌」的阳刚之气。\n");
        if ((int)me->query_skill("jiuyin-shengong", 1) < 20)
                return notify_fail("你的九阴神功火候不够，无法练黯然销魂掌。\n");
       if ((int)me->query_skill("yunu-xinjing", 1) < 20)
                return notify_fail("你的玉女心经火候不够，无法练黯然销魂掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练黯然销魂掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练黯然销魂掌必须空手。\n");
	if (me->query("gender")!="男性"&&(int)me->query_skill("xiaohun-zhang",1)>100)
		return notify_fail("你不是男性，无法领悟「黯然销魂掌」的阳刚之气。\n");
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练黯然销魂掌。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;}
string perform_action_file(string action)
{
        return __DIR__"xiaohun-zhang/" + action;
}

string query_yinyang()
{
	return "纯阴";
}