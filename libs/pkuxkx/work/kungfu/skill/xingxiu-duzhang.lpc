// xingxiu-duzhang.c, based on xianglong-zhang.c
// by yucao
// reedit by binlang
// edit by jpei for xx_poison set
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([      "action": "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
        "dodge": 30,
        "force": 180,
//      "poison": 80,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
        "dodge": 20,
        "force": 190,
//      "poison": 60,
        "damage_type": "瘀伤"
]),
([      "action": "$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l",
        "dodge": 10,
        "force": 200,
//      "poison": 100,
        "damage_type": "瘀伤"
]),
([      "action": "$N双掌挟着一股腥臭之气拍向$n的$l",
        "dodge": 20,
        "force": 220,
//      "poison": 80
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="zhaixing-shou"; }

mapping query_action(object me)
{
         if (me->query("env/xx_poison") == "散毒"
            && random(5)==0
            && me->query_skill("force") > 50
            && me->query("neili") > 100 ) {

                me->add("neili", -30-random(30));
                return ([
                "action": HIB "$N咬破舌尖，口中喷血，聚集全身的力量击向$n" NOR,
                "force": 410,
                "damage_type": "瘀伤"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练星宿毒掌必须空手。\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("你的化功大法火候不够，无法练星宿毒掌。\n");
        if ((int)me->query("max_neili") < 60)
                return notify_fail("你的内力太弱，无法练星宿毒掌");
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练星宿毒掌。\n");
        if (me->query_skill("xingxiu-duzhang", 1) < 50)
                me->receive_damage("qi", 20);
        else
                me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(random(me->query_skill("huagong-dafa", 1)) > 30 
          && me->query_skill("poison", 1) > 50 
          && me->query("env/xx_poison") != "内敛"
          && me->query_skill("poison", 1) > victim->query_condition("xx_poison")
          && me->query_skill("poison", 1) + 20 > victim->query_skill("poison", 1)){
              int poison;
              poison = me->query_skill("poison", 1)/50 + victim->query_condition("xx_poison");
              //victim->set_temp("death_cond_origin/xx_poison", me);
			  F_POISON->poison_attack(me,victim,"xx_poison", poison);
              message_vision(BLU"$N一中掌，身子一晃，看来已经中了毒！\n"NOR, victim);
              if (victim->query_condition("xx_poison") > 200)
                  message_vision(HIR"$N体内积毒已深，恐怕有生命危险！\n"NOR, victim);
        }
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

string perform_action_file(string action)
{
         return __DIR__"xingxiu-duzhang/" + action;
}

int after_parry(object me, object target, string attack_skill)
{
	int ap, dp, nl, suck, pflv;
	string msg;
	if (!objectp(me) || !objectp(target)) 
		return 0;
	nl = (int)target->query("neili");
	if (nl<100) return 0;
	pflv = (int)me->query("purefamily/level");
	if (pflv>=3 && me->query("purefamily/family_name") == "星宿派" && me->query_skill_mapped("force") == "huagong-dafa")// 入室弟子 特效
	{
		ap = (int)me->query_skill("force", "huagong-dafa");
		dp = (int)target->query_skill("force");
		if (F_KUNGFU->hit_rate(ap, dp, 9, me, target)) // 概率与化功大法 exert neilisuck 一样
		{
			msg = HIR "接招之际，只见$N手肘一侧，顺势贴住了$n的手臂。$n顿觉手臂「曲池穴」上一痛，\n";
			msg += "如同被尖针刺了个小孔，体内鼓荡的内力循孔飞泄而出，源源不绝地流入$N的经脉！\n" NOR;
			suck = (int)me->query_skill("huagong-dafa", 1);
			if (pflv>3)
				suck += suck*(pflv-3)/10;
			if (suck>nl) suck=nl;
			target->add("neili", -suck);
			me->add("neili", suck);
			if (me->query("neili")>(2*me->query("max_neili")))
				me->set("neili", 2*me->query("max_neili"));
			if (target->query("neili")<10)
				msg += HIY"$n的身子晃了两晃，脸色惨白，流露出一副油尽灯枯的模样。\n"NOR;
			message_vision(msg, me, target);
		}
	}
	return 1;
}
