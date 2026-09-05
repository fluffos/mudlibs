// tanzhi-shengong.c 弹指神功

inherit SKILL;

mapping *action = ({
([      "action" : "$N右手在$n右肘上急拔，一式「夜叉探海」，抢身上步，左指已自$n右腋下穿入，右手
反钩上来，同时右指点向$n的咽喉",
        "force" : 60,
        "dodge" : -5,
        "parry" : -5,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "夜叉探海",
        "damage_type" : "刺伤"
]),
([      "action" : "$N忽地变招，一式「穿掌闪指」，右手陡松，快如闪电般的一指指向$n的掌心",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage": 30,
        "lvl" : 20,
        "skill_name" : "穿掌闪指",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左腿微曲，右臂内弯，右指一式「沿门托钵」，划了个圆圈，呼的一声，向$n点去",
        "force" : 240,
        "dodge" : 20,
        "parry" : 20,
        "damage": 45,
        "lvl" : 40,
        "skill_name" : "沿门托钵",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左拳回击，右拳直攻，左指忽起，一式「撩阴指」，如一柄长剑点向$n，指风虎虎，极为锋锐",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage": 60,
        "lvl" : 20,
        "skill_name" : "撩阴指",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子微侧，右指反挥，一式「孤雁出群」，点中了$n的后心，右拳直击$n横臂手肘，
左手二指疾伸取$n双目",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage": 70,
        "lvl" : 20,
        "skill_name" : "孤雁出群",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子忽然跃起，身在半空，左手招架，右手一式「雨急风狂」，快如闪电，一个肘锤，
正击在$n的肩上",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage": 80,
        "lvl" : 20,
        "skill_name" : "雨急风狂",
        "damage_type" : "刺伤"
]),
([      "action" : "$N在纵跃翻扑之际，一式「断山绞」，突然左掌竖立，指风虎虎，托地跃起，左指急点
$n的面门，风声四座",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage": 90,
        "lvl" : 20,
        "skill_name" : "断山绞",
        "damage_type" : "刺伤"
]),
([      "action" : "$N侧身避过$n凌厉的进攻，左拳右指，一式「断胫盘打」，从旁夹击，蹲下身来，呼的两指
齐出，直照$n的全身",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage": 100,
        "lvl" : 20,
        "skill_name" : "断胫盘打",
        "damage_type" : "刺伤"
]),

});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="fuxue-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练弹指神功必须空手。\n");
        if ((int)me->query_skill("bihai-shengong", 1) < 20)
                return notify_fail("你的碧海神功火候不够，无法学弹指神功。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练弹指神功。\n");
        return 1;
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
        level   = (int) me->query_skill("tanzhi-shengong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够弹指神功。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
         return __DIR__"tanzhi-shengong/" + action;
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