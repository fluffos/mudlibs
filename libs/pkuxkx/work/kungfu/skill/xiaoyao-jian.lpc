// xiaoyao-jian.c 逍遥剑法
// yuer


inherit SKILL;

mapping *action = ({
([      "action" : "$N虚步提腰，一招「清风徐来」手中$w轻轻颤动，一剑剑点向$n的$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 25,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，一招「梅花万点」左手剑诀，点出几点剑花，右手$w直刺$n的
$l",
        "force" : 140,
        "dodge" : 15,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N$w自上而下划出一个大弧，一招「平沙落雁」，平平地向$n的$l挥去",
        "force" : 170,
 	"dodge" : 15,
        "damage" : 40,
        "lvl" : 9,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑锋平指，一招「秋风落叶」，一气呵成横扫$n的$l",
        "force" : 190,
        "dodge" : 10,
        "damage" : 50,
        "lvl" : 19,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「川流不息」剑锋直出，绵绵不断划向$n的$l",
        "force" : 250,
        "dodge" : 10,
        "damage" : 65,
        "lvl" : 29,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招左脚跃步落地，「随风摆柳」，$w回抽，反手勾向$n的$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 80,
        "lvl" : 59,
        "damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，一招「回头望月」，右手虚抱，$w中宫直进，刺向$n的$l",
        "force" : 350,
        "dodge" : -5,
        "damage" : 110,
        "lvl" : 89,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("你的九阳神功火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("xiaoyao-jian",1);
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
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练逍遥剑法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});


string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
         "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});


string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

