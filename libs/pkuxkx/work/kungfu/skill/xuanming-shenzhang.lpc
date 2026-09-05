#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : HIB"$N使一招「花随流水」，双手飘移不定击向$n$l"NOR,
        "force" : 160,
        "dodge" : 60,
        "skill_name" : "花随流水",
        "lvl" : 10,
        "damage_type" : "瘀伤"
]),
([      "action" : HIW"$N倏忽欺至$n身前，一招「流水飞花」直拍$n的$l"NOR,
        "force" : 240,
        "dodge" : 50,
        "skill_name" : "流水飞花",
        "lvl" : 50,
        "damage_type" : "瘀伤"
]),
([      "action" :HIY "$N身形绕$n一转，一招「花语有意」向$n$l接连出掌"NOR,
        "force" : 320,
        "dodge" : 20,
        "skill_name" : "花语有意",
        "lvl" : 90,
        "damage_type" : "瘀伤"
]),
([      "action" : HIR"$N身形拔起，在半空一招「寒水无心」右掌猛击$n的$l"NOR,
        "force" : 400,
        "dodge" : 40,
        "skill_name" : "寒水无心",
        "lvl" : 180,
        "damage_type" : "瘀伤"
]),
([      "action" : HIC"$N突露大悲神色，一招「花逝人别」，纵起丈余直击$n的$l"NOR,
        "force" : 500,
        "dodge" : 60,
        "skill_name" : "花逝人别",
        "lvl" : 400,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练玄冥神掌必须空手。\n");
        if ((int)me->query_skill("jiuyin-zhengong",1) < 50)
                return notify_fail("你的九阴真功不够火候，无法练九阴神掌。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练九阴神掌。\n");
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
        level = (int) me->query_skill("xuanming-shenzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练催心掌。\n");
        me->receive_damage("qi", 45);
        me->add("neili", -100);
        return 1;
}

int hit_ob(object me, object ob, int damage)
{
        message_vision(HIR"$N被玄冥寒气一震，方寸大乱！\n"NOR,ob);
        ob->add("jingli",-random(damage));
        ob->set("qi",-2000);
        return 0;
}

