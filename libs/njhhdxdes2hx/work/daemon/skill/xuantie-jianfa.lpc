// xuantie-jianfa.c 玄铁剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N斜斜得向$n的$1刺出一剑，所刺之出令人出乎意料。",
        "force" : 60,
        "dodge" : 10,
        "damage" : 15,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，右手$w平淡无奇的伸向$n的$l，根本无招可言。",
        "force" : 70,
        "dodge" : 10,
        "damage" : 15,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w突然撞向自己的$l，就在此时，一转向$n的$l挥去。",
        "force" : 70,
        "dodge" : 15,
        "damage" : 20,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N将手中$w舞成一片，直砍$n的$l",
        "force" : 100,
        "dodge" : 20,
        "damage" : 20,
        "lvl" : 30,
        "damage_type" : "砍伤"
]),
([      "action" : "$N突然将$w抛向空中，剑锋直向$n的$l刺去。$N跟上一步，又接住了$w。",
        "force" : 120,
        "dodge" : 20,
        "damage" : 30,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身形急转，$w从一个不可思意的角度刺向$n的$l",
        "force" : 200,
        "dodge" : 30,
        "damage" : 30,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子一晃，抢步上前，出人意料的将$w交给左手，右食指点向$n的$l",
        "force" : 250,
        "dodge" : 40,
        "damage" : 60,
        "lvl" : 100,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N右腿半屈般蹲，剑尖虚指，转身撩向$n的$l",
        "force" : 300,
        "dodge" : 40,
        "damage" : 80,
        "lvl" : 120,
        "damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，$w中宫直进，刺向$n的$l",
        "force" : 350,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 150,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if(me->query("family/master_id")!="yang guo")
                return notify_fail("玄铁剑法只能向杨过请教。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的真气不够。\n");
        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("xuantie-jianfa", 1);
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
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力不够练玄铁剑法。\n");
        me->receive_damage("qi", 40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuantie-jianfa/" + action;
}

