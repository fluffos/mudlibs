// houquan.c 猴拳
inherit SKILL;
mapping *action = ({
([  "action" : "$N单腿微曲，忽的向前扑出，一式「"+YEL+"仙猴摘桃"+NOR+"」，二爪直出，抓向$n的$l",
    "force" : 180,
    "damage_type" : "抓伤",
    "lvl" : 0,
    "skill_name" : YEL "横空出世" NOR,
]),
([  "action" : "$N左手虚晃，一式「"+MAG+"灵猴攀枝"+NOR+"」，右手直击，反扣$n的肩井大穴",
    "force" : 200,
    "lvl" : 8,
    "skill_name" : MAG "灵猴攀枝" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一臂前伸，一臂后指，一式「"+RED+"猿臂轻舒"+NOR+"」，攻向$n的$l",
    "force" : 230,
    "lvl" : 15,
    "skill_name" : RED "猿臂轻舒" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "\n$N忽然缩成一团，使一式「"+YEL+"八方幻影"+NOR+"」，双爪无形无定，一爪抓向$n的$l",
    "force" : 230,
    "lvl" : 15,
    "skill_name" : YEL "八方幻影" NOR,
    "damage_type" : "内伤"
]),
([  "action" : "$N猛吸一口气，一弯腰，使一式「"+BLU+"水中揽月"+NOR+"」，双爪疾扣向$n的$l",
    "force" : 220,
    "damage_type" : "瘀伤",
    "lvl" : 20,
    "skill_name" : BLU "水中揽月" NOR,
]),
([  "action" : "$N猛的向上高高跃起，一式「"+YEL+"落地摘星"+NOR+"」，居高临下，一爪罩向$n的头骨",
    "force" : 240,
    "damage_type" : "抓伤",
    "lvl" : 30,
    "skill_name" : YEL "落地摘星" NOR,
]),
});
int practice_level(){   return 30;  }
int valid_enable(string usage) { return usage=="parry"|| usage=="unarmed"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练猴拳必须空手。\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("你的基本内功火候不够，无法学猴拳。\n");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("你的内力太弱，无法练猴拳。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("houquan", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
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
    mapping a_action;
    level   = (int) me->query_skill("houquan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-random(level/3);
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练猴拳必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("你的内力不够练猴拳。\n");
    me->receive_damage("qi", 15);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"houquan/" + action;
}


