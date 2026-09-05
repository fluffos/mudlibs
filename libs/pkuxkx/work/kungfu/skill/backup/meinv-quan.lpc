// meinv-quan.c 美女拳
// By Lgg,1998.9

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「红玉击鼓」 ，双臂交互快击",
        "force" : 180,
        "dodge" : 5,
        "damage":25,
        "lvl" : 0,
        "skill_name" : "红玉击鼓",
        "damage_type" : "内伤"
]),
([      "action" : "$N突然变为「红拂夜奔」，出其不意的叩关直入，令$n大吃一惊",
        "force" : 200,
        "dodge" : 5,
        "damage": 40,
        "lvl" : 10,
        "skill_name" : "红拂夜奔",
        "damage_type" : "内伤"
]),
([      "action" : "$N招式一变成「绿珠坠楼」，扑地攻敌下盘，委实难测",
        "force" : 230,
        "dodge" : 15,
        "damage": 55,
        "lvl" : 22,
        "skill_name" : "绿珠坠楼",
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌连拍数下，接著连绵不断拍出，原来是「文姬归汉」，共胡笳
十八拍",
        "force" : 270,
        "dodge" : 5,
        "damage": 60,
        "lvl" : 34,
        "skill_name" : "文姬归汉",
        "damage_type" : "内伤"
]),
([      "action" : "$N使出「红线盗盒」，以空手入白刃之技向$n手中兵刃夺去",
        "force" : 320,
        "dodge" : 10,
        "damage": 70,
        "lvl" : 48,
        "skill_name" : "红线盗盒",
        "damage_type" : "内伤"
]),
([      "action" : "$N一式「木兰弯弓」，左手如抱满月，右手疾挥而过，令$n目瞪口呆
",
        "force" : 380,
        "dodge" : 25,
        "damage": 82,
        "lvl" : 60,
        "skill_name" : "木兰弯弓",
        "damage_type" : "内伤"
]),
([      "action" : "$N忽然昂首如吟明月，双掌从不可思议的角度攻了过来，原来是一招
「班姬赋诗」",
        "force" : 450,
        "dodge" : 15,
        "damage": 94,
        "lvl" : 71,
        "skill_name" : "班姬赋诗",
        "damage_type" : "内伤"
]),
([      "action" : "$N使招「蛮腰纤纤」，腰肢轻摆避开，紧跟着挥掌攻击$n的前胸",
        "force" : 530,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 82,
        "skill_name" : "蛮腰纤纤",
        "damage_type" : "内伤"
]),
([      "action" : "$N五指在自己头发上一梳，跟著软软的挥了出去，脸上微微一笑，却
是一招「丽华梳装」。",
        "force" : 530,
        "dodge" : 20,
        "damage": 110,
        "lvl" : 95,
        "skill_name" : "丽华梳装",
        "damage_type" : "内伤"
]),
([      "action" : "$N见$n呆住，伸指戳出，却是一招「萍姬针神」。",
        "force" : 530,
        "dodge" : 20,
        "damage": 111,
        "lvl" : 109,
        "skill_name" : "萍姬针神",
        "damage_type" : "内伤"
]),
([      "action" : "$N突然间蹙起眉头，宛如「西子捧心」，双掌自自己胸口攻出",
        "force" : 530,
        "dodge" : 20,
        "damage": 124,
        "lvl" : 129,
        "skill_name" : "西子捧心",
        "damage_type" : "内伤"
]),
([      "action" : "$N脚下翩若惊鸦、矫若游龙，犹如在水上漂行一般，却是一招「洛神
微步」",
        "force" : 530,
        "dodge" : 20,
        "damage": 150,
        "lvl" : 149,
        "skill_name" : "洛神微步",
        "damage_type" : "内伤"
]),
([      "action" : "$N使招「曹令割鼻」，挥手在自己脸上斜削一掌，左掌削过，右掌又
削，连绵不断",
        "force" : 530,
        "dodge" : 20,
        "damage": 200,
        "lvl" : 179,
        "skill_name" : "曹令割鼻",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry" || usage=="cuff"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练美女拳必须空手。\n");
        if ((int)me->query_skill("yunv-xinfa", 1) < 10)
                return notify_fail("你的玉女心法火候不够，无法学美女拳。\n");
        if ((int)me->query("max_neili") < 30)
                return notify_fail("你的内力太弱，无法学习美女拳。\n");
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
        level   = (int) me->query_skill("meinv-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太差了，不能练习美女拳。\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"meinv-quan/" + action;
}
