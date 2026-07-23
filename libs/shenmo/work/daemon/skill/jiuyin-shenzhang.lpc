// jiuyin-shenzhang.c 九阴神掌
// npc skill
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : HIB"$N使一招「风起云涌」，双手飘移不定击向$n$l"NOR,
	"force" : 300,
	"dodge" : random(100),
	"skill_name" : "风起云涌",
	"lvl" : 0,
	"damage" : random(200),
        "damage_type" : "瘀伤"
]),
([      "action" : HIW"$N倏忽欺至$n身前，一招「扬波起浪」直拍$n的$l"NOR,
	"force" : 360,
	"dodge" : random(100),
	"skill_name" : "扬波起浪",
	"lvl" : 30,
	"damage" : random(200),
        "damage_type" : "瘀伤"
]),
([      "action" :HIY "$N身形绕$n一转，一招「风雷并起」向$n$l接连出掌"NOR,
	"force" : 400,
	"dodge" : random(100),
	"skill_name" : "风雷并起",
	"lvl" : 50,
	"damage" : random(200),
        "damage_type" : "瘀伤"
]),
([      "action" : HIR"$N身形拔起，在半空一招「急电惊雷」右掌猛击$n的$l"NOR,
	"force" : 450,
	"dodge" : random(100),
	"skill_name" : "急电惊雷",
	"lvl" : 90,
	"damage" : random(200),
        "damage_type" : "瘀伤"
]),
([      "action" : HIC"$N使一招「含沙射影」，纵起丈余直击$n的$l"NOR,
	"force" : 500,
	"dodge" : random(100),
	"skill_name" : "含沙射影",
	"lvl" : 120,
	"damage" : random(200),
        "damage_type" : "瘀伤"
]),
([      "action" : HIG"$N一声大喝使出「夺魄催心」，幻出满天掌影，掌掌不离$n的$l"NOR,
	"force" : 620,
	"dodge" : random(100),
	"skill_name" : "夺魄催心",
	"lvl" : 150,
	"damage" : random(200),
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="dafumo-quan"; }

int valid_learn(object me)
{
	if (!me->query("jiuyin/full"))
               return notify_fail("你现在不能学习九阴神掌。\n");
        if ((int)me->query_skill("cuixin-zhang",1) > 1)
                return notify_fail("你学了催心掌，无法练九阴神掌。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练九阴神掌必须空手。\n");
       if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
               return notify_fail("你的九阴真功火候不够，无法练九阴神掌。\n");
       if ((int)me->query_skill("daode-jing", 1) < 100)
               return notify_fail("你的道德经火候不够，无法练九阴神掌。\n");
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
        level = (int) me->query_skill("jiuyin-shenzhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if( (int)me->query_skill("jiuyin-shenzhang", 1 ) < 150 )
               return notify_fail("你现在不能练习九阴神掌。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练九阴神掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jiuyin-shenzhang/" + action;
}

int hit_ob(object me, object ob, int damage)
{
	int i;
        message_vision(HIR"$N被九阴真气一震，方寸大乱！\n"NOR,ob);
	i = random(me->query_skill("jiuyin-zhengong", 1));
        ob->receive_damage("jing",i);
        ob->receive_wound("jing",i/3);
        return 0;
}
