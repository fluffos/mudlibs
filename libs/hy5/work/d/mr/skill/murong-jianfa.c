// murong-jiafa 慕容剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N剑尖下指，一式「洗耳恭听」，双脚后退三步，剑尖直点$n腿部",
        "force" : 120,
        "dodge" : 20,
        "damage" : 25,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N踏前数步，避虚就实，右手使一式「明察秋毫」直刺$n的右肋",
        "force" : 160,
        "dodge" : 15,
        "damage" : 30,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「甜言蜜语」，剑尖抖起五朵剑花，分别刺向$n的左脸和右耳",
        "force" : 220,
        "dodge" : 15,
        "damage" : 40,
        "lvl" : 45,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑身横摆，剑尖指向$n的脸部，一招「望尘莫及」，宛若万马千军一般，横扫$n的$l",
        "force" : 270,
        "dodge" : 10,
        "damage" : 50,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双脚离地，使出草上飞，身行直奔$n，一招「骑虎难下」，剑出中宫，平削$n的$l",
        "force" : 330,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 75,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长笑一声，横剑斜削，一招「抛砖引玉」，剑风逼向$n的$l",
        "force" : 380,
        "dodge" : 5,
        "damage" : 70,
        "lvl" : 90,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_combine(string combo) { return combo=="murong-daofa"; }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 20)
                return notify_fail("你的神元功火候太浅。\n");
        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("你的基本招架火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("murong-jianfa",1);
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
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的体力不够练慕容剑法。\n");
        me->receive_damage("jingli", 30);
        return 1;
}
