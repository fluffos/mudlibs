// 钢拳铁臂
// by lordstar
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N抬起铁臂，一记钢拳攻向$n的$l",
        "dodge": 0,
        "parry": 0,
        "force": 50,
        "damage_type": "瘀伤"
]),
([      "action": "$N对准$n的$l用力挥出一记钢拳",
        "dodge": 0,
        "parry": 0,
        "force": 50,
        "damage_type": "瘀伤"
]),
([      "action": "$N提起钢拳往$n的$l捶去",
		"dodge": 0,
		"parry": 0,
		"force": 50,
		"damage_type": "瘀伤"
]),
([      "action": "$N抬起钢拳往$n的$l用力一戳",
        "dodge": 0,
		"parry": 0,
		"force": 50,
		"damage_type": "瘀伤"
]),
([      "action": "$N挥起钢拳往$n的$l狠狠一砸",
        "dodge": 0,
		"parry": 0,
		"force": 50,
		"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="cuff" ; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	return notify_fail("钢拳铁臂无法学习。\n");
}

string perform_action_file(string action)
{
        return __DIR__"gangquan-tiebi/" + action;
}

string *parry_msg = ({
        "但是被$p侥幸格开了。\n",
        "结果被$p侥幸挡开了。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p侥幸格开了。\n",
        "结果被$p侥幸挡开了。\n",
});

int practice_skill(object me)
{
	return notify_fail("钢拳铁臂无法练习。\n");
}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int hit_ob(object me, object ob, int damage)
{
	int dmg, mark;
	string msg;
	if (!ob->query("lvliu_npc")) return 0;
    dmg = me->query_skill("gangquan-tiebi",1) + me->query_str()*10;
	mark = 0;
	if (me->query_temp("active_buffer/shenghuo-lingfa.jindou")) 
	{
		dmg /= 5;
		mark = 1;
	}
	if (me->query("zyhb")||me->query_temp("can_zyhb"))
	{
		dmg -= dmg/3;
		mark = 1;
	}
	dmg = dmg/2 + random(dmg)/2;
	if (!mark)
		msg = HIR"$N的铁臂钢拳轰在$n"HIR"身上，发出砰然一声巨响";
	else
		msg = HIY"$N的铁臂钢拳挥得飞快，砸在$n"HIY"身上一声响";
	if (ob->query("race")=="机关人")
		msg += "，顿时火星四溅！\n"NOR;
	else
		msg += "，顿时血肉横飞！\n"NOR;
	message_vision(msg,me,ob);
    F_KUNGFU->hit_wound("qi", dmg, dmg/2, me, ob);
	COMBAT_D->report_status(ob);
	return 0;
}
