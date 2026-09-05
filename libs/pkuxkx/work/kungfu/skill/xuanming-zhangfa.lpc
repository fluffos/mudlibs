
// xuanming-zhang.c -玄冥掌法
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N左手插在背后，右手连着衣袖向$n的$l拂去。",
	"force" : 200,
        "dodge" : 50,
	"damage_type" : "劈伤",
	"lvl" : 0,
	"skill_name" : "玄冥掌法"
]),
([	"action" : "$N趁$n分心之际，双掌交互连续拍出，将$n全身都罩于掌影之下。",
	"force" : 250,
        "dodge" : 30,
        "damage_type" : "瘀伤",
	"lvl" : 9,
	"skill_name" : "玄冥掌法"
]),
([	"action" : "$N左手骈指在$n左肩一侧带过，作势欲攻，紧接着右手翻掌向$n的$l击去。",
	"force" : 280,
        "dodge" : 35,
        "damage_type" : "瘀伤",
	"lvl" : 19,
	"skill_name" : "玄冥掌法"
]),
([	"action" : "$N转身佯作败逃，突然间身形一转，力贯右掌，迅雷一般向$n的胁下划去。",
	"force" : 320,
        "dodge" : 30,
        "damage_type" : "劈伤",
	"lvl" : 29,
	"skill_name" : "玄冥掌法"
]),
([	"action" : "$N运起玄冥内力，掌上绿气大盛，一掌掌向着$n拍去，寒气弥散，直逼的$n透不过气。",
	"force" : 330,
        "dodge" : 25,
        "damage_type" : "瘀伤",
	"lvl" : 39,
	"skill_name" : "玄冥掌法"
]),
([	"action" : "$N狞笑一声，右手劲力不减，直取$n的$l,\n"
			"左手骈指，悄无声息的向$n的胸前要穴点去。",
	"force" : 290,
        "dodge" : 25,
        "damage_type" : "刺伤",
	"lvl" : 49,
	"skill_name" : "玄冥掌法"
]),
([	"action" : "$N向上高高跃起，双掌无声无息的向$n的天灵盖按去。",
	"force" : 300,
        "dodge" : 40,
        "damage_type" : "瘀伤",
	"lvl" : 59,
	"skill_name" : "玄冥掌法"
]),
([	"action" : "$N身形一转，四下飘走，两掌如幽灵般难以捉摸，不断拍向$n全身各处要害。",
	"force" : 300,
        "dodge" : 40,
        "damage_type" : "瘀伤",
	"lvl" : 69,
	"skill_name" : "玄冥掌法"
]),
([	"action" : "$N目露凶光，双掌泛碧，寒意陡然大盛，运尽全身之力向$n一掌拍去。",
	"force" : 450,
        "dodge" : -10,
        "damage_type" : "瘀伤",
	"lvl" : 79,
	"skill_name" : "玄冥掌法"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

//int valid_combine(string combo) { return combo=="yizhi-chan"; }

int valid_learn(object me)
{
	return notify_fail("这功夫太过阴毒，一般人是受不住的。\n");
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
	level = (int)me->query_skill("xuanming-zhangfa", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
/*	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练般若掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;*/
	return notify_fail("这功夫太过阴毒，一般人是受不住的。\n");
}

string *parry_msg = ({
        "只听见「波」一声轻响，被$n挥掌拍开了。\n",
        "$n身形一移，无声无息的躲开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "只听见「波」一声轻响，被$n挥掌拍开了。\n",
        "$n身形一移，无声无息的躲开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
        return __DIR__"xuanming-zhangfa/" + action;
}

int hit_ob(object me, object ob, int damage)
{
        message_vision(HIR"$N被玄冥寒气一震，方寸大乱！\n"NOR,ob);
        ob->add("jingli",-random(damage));
        ob->set("qi",-1000);
        return 0;
}
