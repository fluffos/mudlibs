// six-sun.c -天山六阳掌

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :HIW"$N轻轻一笑，未见动作，$n的攻势如泥牛沉海，$n顿觉全身脱力，大惊失色！" NOR,
        "force" : 200,
        "dodge" : 10,
        "damage": 50,
        "lvl": 0,
        "skill_name" : "阳春白雪",
        "damage_type" : "内伤"
]),
([      "action" :HIR "$N袍袖轻拂，$n只觉得身处惊涛骇浪，强劲的内力一波一波如排山倒海般涌来，$n喉头一甜，喷出一支血箭！" NOR,
        "force" : 300,
        "dodge" : 30,
        "damage":80,
        "lvl": 20,
        "skill_name" : "阳关三叠",
        "damage_type" : "内伤"
]),
([      "action" :"$N随风飘然而起，一式"+HIY"阳歌天钧"NOR+"，顿时漫天掌影，掌才发而掌力已至，$n全身骨骼格格作响，透不过气来。",
        "force" : 350,
        "dodge" : 40,
        "damage": 100,
        "lvl": 40,
   	"skill_name" : "阳歌天钧",
        "damage_type" : "内伤"
]),
([      "action" :"$N纵身越过$n的头顶，掌纳袖中，信手后挥，一式"+HIR"残阳沐血"NOR+"，掌力罩向$n全身！",
        "force" : 450,
        "dodge" : 50,
"damage": 200,
        "lvl": 60,
        "skill_name" : "残阳沐血",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
 if (me->query("family/master_id") != "li qiushui")
                return notify_fail("天山六阳掌只能向李秋水学. \n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练天山六阳掌必须空手。\n");
        if ((int)me->query_skill("beiming-shengong", 1) < 10)
                return notify_fail("你的北冥神功火候不够，无法学六阳掌。\n");
        if ((int)me->query("max_neili") < 80)
                return notify_fail("你的内力太弱，无法练六阳掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够了。\n");
        me->receive_damage("qi", 20);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"six-sun/" + action;
}

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
	"$n左拳虚晃，右掌猛击$N的面门，逼得$N撤回攻势！\n",
        "结果被$p挡开了。\n",
        "$n脚走阴阳，双掌带着呼啸的风声直击$N的两肋！\n",
        "$n左掌一个虚幌，右掌直插$N的小腹，SN不得不急退几步！\n"
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
