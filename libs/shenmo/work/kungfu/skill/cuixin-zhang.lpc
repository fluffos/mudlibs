// cuixin-zhang.c 催心掌 by XiaoYao 4/22/99
// npc skill

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「风起云涌」，双手飘移不定击向$n$l",
	"force" : 160,
	"dodge" : 2,
	"skill_name" : "风起云涌",
	"lvl" : 0,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N倏忽欺至$n身前，一招「扬波起浪」直拍$n的$l",
	"force" : 240,
	"dodge" : 0,
	"skill_name" : "扬波起浪",
	"lvl" : 30,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形绕$n一转，一招「风雷并起」向$n$l接连出掌",
	"force" : 320,
	"dodge" : -2,
	"skill_name" : "风雷并起",
	"lvl" : 50,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形拔起，在半空一招「急电惊雷」右掌猛击$n的$l",
	"force" : 400,
	"dodge" : -4,
	"skill_name" : "急电惊雷",
	"lvl" : 90,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「含沙射影」，纵起丈余直击$n的$l",
	"force" : 500,
	"dodge" : -6,
	"skill_name" : "含沙射影",
	"lvl" : 120,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一声大喝使出「夺魄催心」，幻出满天掌影，掌掌不离$n的$l",
	"force" : 620,
	"dodge" : -8,
	"skill_name" : "夺魄催心",
	"lvl" : 150,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jiuyin-baiguzhua"; }

int valid_learn(object me)
{
       if (!me->query("jiuyin/xia") && !me->query("jiuyin/emei"))
               return notify_fail("你现在不能学习催心掌。\n");
       if( (int)me->query_skill("jiuyin-shenzhang", 1 ) >= 1)
                return notify_fail("学了九阴神掌，还要催心掌？\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练催心掌必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练催心掌。\n");
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
        level = (int) me->query_skill("cuixin-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if( (int)me->query_skill("cuixin-zhang", 1 ) < 150 )
               return notify_fail("你现在不能练习催心掌。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练催心掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"cuixin-zhang/" + action;
}
