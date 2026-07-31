// yangjia-qiang.c 杨家枪

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w向天，气势辉煌，一枪刺向$n的$l",
        "force" : 120,
        "dodge" : -10,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N将$w一抖，抖出若大一个枪花,刺向$n的$l",
        "force" : 130,
        "dodge" : -10,
        "damage" : 5,
        "lvl" : 8,
        "damage_type" : "刺伤"
]),
([      "action" : "$N大喝一声！将$w使得如同一条活蛇刺向$n的$l",
        "force" : 140,
        "dodge" : -5,
  	"damage" : 15,
        "lvl" : 16,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w自左而右划出一个圆弧，刺向$n的$l",
        "force" : 160,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 24,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w一沉，持$w刺向$n的$l",
        "force" : 180,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 33,
        "damage_type" : "刺伤"
]),
([      "action" : "$N挥舞$w，枪身如龙刺向$n",
        "force" : 210,
    	"dodge" : 15,
        "damage" : 35,
        "lvl" : 42,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双目圆睁，$w只如一条飞凤撩向$n的$l",
        "force" : 240,
        "dodge" : 5,
        "damage" : 50,
        "lvl" : 51,
        "damage_type" : "刺伤"
]),
([      "action" : "$N飞身越起，枪如游龙，人如飞凤向$n的$l刺去",
        "force" : 280,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage == "spear" || usage == "parry"; }

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
        level = (int) me->query_skill("yangjia-qiang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练杨家枪。\n");
        me->receive_damage("qi", 25);
        return 1;
}
string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕刺去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手刺出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，手中$v猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
     	if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
