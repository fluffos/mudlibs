// bingcan-duzhang.c

inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action": HIW"$N"+HIW+"右掌用力挥出，推向$n的$l，这一掌来势劲力大得异乎寻常，掌风带得$n"+HIW+"几乎向后跌坐下去",
         "dodge": 30,
         "parry": 30,
         "force": 300,
         "skill_name" : "冰蚕毒掌",
         "damage_type": "瘀伤"
         ]),
        ([      "action": HIW"$N"+HIW+"一掌拍出，$n"+HIW+"顿觉一股寒气袭来，全身一颤，牙关相击格格直响，便似身入冰窖一般",
         "dodge": 30,
         "parry": 30,
         "force": 300,
         "skill_name" : "冰蚕毒掌",
         "damage_type": "冻伤"
         ]),
        ([  "action": HIW"$N"+HIW+"踏上一步，呼呼呼呼，连出四掌，每出一掌，便跨上一步，这五步踏出，已与$n"+HIW+"面面相对",
         "dodge": 30,
         "parry": 30,
         "force": 300,
         "skill_name" : "冰蚕毒掌",
         "damage_type": "瘀伤"
         ]),
        ([  "action": HIW"$N"+HIW+"双掌隐隐带着风声劈向$n的$l，掌风所至，$n"+HIW+"不禁机伶伶的打个冷战，感到寒气袭体，说不出的难受",
         "dodge": 30,
         "parry": 30,
         "force": 300,
         "skill_name" : "冰蚕毒掌",
         "damage_type": "冻伤"
         ]),
        ([  "action": HIW"$N"+HIW+"大喝一声，右掌立即拍出，一股阴寒之气随伴着掌力直逼向$n"+HIW+"的$l",
         "dodge": 30,
         "parry": 30,
         "force": 300,
         "skill_name" : "冰蚕毒掌",
         "damage_type": "瘀伤"
         ]),
        ([  "action": HIW"$N"+HIW+"左手凌空劈出，右掌跟着迅捷之极的劈出，左手掌力先发后到，右手掌力后发先到，两股力道交错而前，诡异之极",
         "dodge": 30,
         "parry": 30,
         "force": 300,
         "skill_name" : "冰蚕毒掌",
         "damage_type": "瘀伤"
         ]),
        ([  "action": HIW"$N"+HIW+"身形一晃，倏忽之间已欺近了丈余，伴随着一阵冰冷的白雾向$n"+HIW+"的$l拍出一掌",
         "dodge": 30,
         "parry": 30,
         "force": 300,
         "skill_name" : "冰蚕毒掌",
         "damage_type": "冻伤"
         ]),
});

int skill_speed(object me) 
{ 
	int atp = (int)me->query_temp("bingcan-duzhang/att_speed");
	if (atp>50) atp=50;
	return atp;
}

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练冰蚕毒掌必须空手。\n");
    if ((int)me->query_skill("force", 1) < 300)
        return notify_fail("你的基本内功火候不够，强练冰蚕毒掌怕有性命之忧。\n");
    if ((int)me->query("max_neili") < 3000)
        return notify_fail("你的内力太弱，无法练习冰蚕毒掌。\n");
	if ((int)me->query("shen") > -10000)
		return notify_fail("你不够阴狠毒辣，无法练习冰蚕毒掌这样的阴毒功夫。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
	mapping newaction=([]);
	newaction += action[random(sizeof(action))];
	// 这个临时属性表示用冰蚕毒掌出了一招，供冰蚕毒掌的pfm调用
	me->set_temp("bingcan-duzhang/do_attack", 1); 
	if ((int)me->query("shen") > -5000)
	{
		newaction["action"] += "！" HIY "\n也许是因为不够阴狠毒辣，$N这一掌劈出时犹豫了片刻，变得威力大减，无甚威胁"NOR;
		newaction["force"] = 50;
		newaction["dodge"] = 0;
		newaction["parry"] = 0;
	}
	return newaction;
}

int practice_skill(object me)
{
    return notify_fail("冰蚕毒掌只能通过伺养冰蚕来领悟和提高，自己瞎练是没有用的。\n");
}

string perform_action_file(string action)
{
    return __DIR__"bingcan-duzhang/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
        });

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
        });

string query_parry_msg(object weapon)
{
    if( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int hit_ob(object me, object ob, int damage)
{
	int dmg, ps, obps, dps, dur, rate_lv;

	if ((int)me->query("shen") > -5000) return 0;
    if (me->query("neili")<=50) return 0;
	if (me->query_skill("poison", 1)<150) return 0;
	
	ps = me->query_skill("poison", 1);
	obps = ob->query_skill("poison", 1);
	
	rate_lv=8;
	dps = ps-obps;
	if (dps>0)
	{
		dps = dps/2 + random(dps)/2;
		if (dps>500) rate_lv=5;
		else if (dps>200) rate_lv=6;
		else if (dps>10) rate_lv=7;
	}
	//使用筋斗的，命中降低4个等级
	if (me->query_temp("active_buffer/shenghuo-lingfa.jindou"))
	{
		rate_lv += 4;
	}

	if ( F_KUNGFU->hit_rate( me->query_skill("strike","bingcan-duzhang")+ps, ob->query_skill("force")+obps, rate_lv, me, ob) )
	{
        dmg = me->query_skill("bingcan-duzhang",1);
        dmg = dmg/2 + random(dmg)/2;
		dmg += ps/2 + random(ps)/2;
		dmg -= obps/2 + random(obps)/2;
		if (dmg<10) dmg=10;
        F_KUNGFU->hit_wound("qi", dmg, dmg/3, me, ob);
        message_vision(HIC"$N"+HIC+"被冰蚕毒掌上的彻骨奇寒倾入体内，顿时如坠冰窖，浑身都凝出了一层薄薄的白霜！\n"NOR,ob);
        COMBAT_D->report_status(ob);
		dur = (int)ob->query_condition("xxx_poison");
		if (dur<10)
			F_POISON->poison_attack(me, ob, "xxx_poison", dur+10);
		if ( ob->query_condition() && F_KUNGFU->hit_rate( ps, obps, rate_lv, me, ob) )
		{
			message_vision(HIM"$N"+HIM+"体内的毒素也被这彻骨奇寒激发了！\n"NOR,ob);
			ob->update_condition();
            COMBAT_D->report_status(ob);
		}
	}
	else
	{
		dur = me->query_skill("poison", 1)/50;
		if (dur>10) dur=10;
		dur += ob->query_condition("xxx_poison");
		F_POISON->poison_attack(me,ob,"xxx_poison", dur);
		message_vision(HIM"$N身形一滞，剧毒已顺着奇寒侵入体内！\n"NOR, ob);
	}
	return 0;
}
