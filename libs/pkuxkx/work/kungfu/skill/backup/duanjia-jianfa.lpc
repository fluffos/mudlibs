//段家剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N左手捏了个剑诀，右手$w平平递出，一式「其利断金」直刺$n的前胸",
        "force" : 150,
        "dodge" : -5,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N纵身向前，$w从一个想不到的角度突然弹出，一式「碧鸡报晓」直刺$n的左肋",
        "force" : 180,
        "dodge" : -5,
        "damage" : 45,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「金马腾空」，身形跃在半空，$w横削而出?，直向$n的头部",
        "force" : 220,
        "dodge" : 20,
        "damage" : 55,
        "lvl" : 45,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑身斜挥，剑尖指向$n的腹部，一招「碧渊腾蛟」，自下而上，剖向$n",
        "force" : 270,
        "dodge" : -15,
        "damage" : 70,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双脚离地，斜飞而出，$w射向$n的$l,好一招「笑指天南」",
        "force" : 330,
        "dodge" : -15,
        "damage" : 90,
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长啸一声，横剑轻挥隐隐透出王道之意，正是段家不传之秘「逐鹿中原」，剑风罩住$n的全身",
        "force" : 280,
        "dodge" : 15,
        "damage" : 100,
        "lvl" : 90,
        "damage_type" : "刺伤"

]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
//int valid_combine(string combo) { return combo=="murong-daofa"; }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("qiantian-yiyang", 1) < 20)
                return notify_fail("你的乾天一阳火候太浅。\n");
 //       if ((int)me->query_skill("parry", 1) < 10)
   //             return notify_fail("你的基本招架火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("duanjia-jianfa",1);
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
        if ((int)me->query("jingli") < 40)
                return notify_fail("你的体力不够练段家剑法。\n");
        me->receive_damage("jingli", 20);
        return 1;
}
/*
string perform_action_file(string action)
{
	return __DIR__"duanjia-jianfa/" + action;
}

*/
