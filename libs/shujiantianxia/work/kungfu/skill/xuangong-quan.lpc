// xuangong-quan.c 无极玄功拳

inherit SKILL;

mapping *action = ({
([      "action" : "$N大喝一声“看拳”，一招「猛鸡夺栗」劈头盖面的向$n的$l打到", 
        "force" : 200,
        "dodge" : 10,
        "lvl" : 0,
        "skill_name" : "猛鸡夺栗",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使出一招「暗渡陈仓」，双脚不动，上身一让，快如闪电，身手疾探，点向$n的「幽门穴」",
        "force" : 280,
        "dodge" : 15,
        "lvl" : 20,
        "skill_name" : "暗渡陈仓",
        "damage_type" : "内伤"
]),
([      "action" : "$N凝神敛气，左拳右掌，合抱一拱，突然发招「空击苍鹰」，自下而上的打向$n的$l",
        "force" : 330,
        "dodge" : 20,
        "lvl" : 40,
        "skill_name" : "空击苍鹰",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N倏的腾空跃起，借助下落之势，劈面一拳，随即变拳为手，抓向$n的$l,好一招「树梢擒猴」",
        "force" : 380,
        "dodge" : 15,
        "lvl" : 60,
        "skill_name" : "树梢擒猴",
        "damage_type" : "抓伤"
]),
([      "action" : "$N施出「仙剑斩龙」，右手翻腕，向$n手背上按落，左拳用尽生平之力自上而下猛击$n右臂手肘",
        "force" : 420,
        "dodge" : 10,
        "lvl" : 50,
        "skill_name" : "仙剑斩龙",
        "damage_type" : "内伤"
]),
([      "action" : "$N脚下「八卦赶蟾」，一个起落，跃身到$n身前，一个连枝交叉步，双拳「拗鞭」缠向$n的$l",
        "force" : 480,
        "dodge" : 20,
        "lvl" : 60,
        "skill_name" : "八卦赶蟾",
        "damage_type" : "内伤"
])

});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="zhenshan-mianzhang"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练无极玄功拳必须空手。\n");
        if ((int)me->query_skill("yinyun-ziqi", 1) < 80)
                return notify_fail("你的氤氲紫气火候不够，无法学习无极玄功拳。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练无极玄功拳。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("xuangong-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练无极玄功拳。\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuangong-quan/" + action;
}