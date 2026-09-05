
// qianzhu-wandushou.c  千蛛万毒手
// by star

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N身形一晃而至，一招「小鬼勾魂」，双掌带着一缕腥风拍向$n的前心",
        "dodge": 10,
        "force": 200,
        "lvl" : 0,
        "damage_type": "瘀伤"
]),
([      "action": "$N身形化做一缕轻烟绕着$n急转，一招「天网恢恢」，双掌幻出无数掌影罩向$n",
        "dodge": 40,
        "force": 250,
        "lvl" : 20,
        "damage_type": "瘀伤"
]),
([	"action": "$N大喝一声，一招「恶鬼推门」，单掌如巨斧开山带着一股腥风猛劈向$n的面门",
	"dodge": -20,
	"force": 300,
	"lvl" : 50,
	"damage_type": "瘀伤"
]),
([	"action": "$N一声冷笑，一招「灵蛇九转」，身形一闪而至，一掌轻轻拍出，手臂宛若\n无骨，掌到中途竟连变九变，如鬼魅般印向$n的$l",
	"dodge": 60,
	"lvl" : 80,
	"force": 350,
	"damage_type": "瘀伤"
]),
([	"action": "$N侧身向前，一招「地府阴风」，双掌连环拍出，一缕缕彻骨的寒气从掌心\n透出，将$n周围的空气都凝结了",
	"dodge": 10,
	"force": 400,
	"lvl" : 120,
	"damage_type": "瘀伤"
]),
([	"action": "$N厉叫一声，身形忽的蜷缩如球，飞身撞向$n，一招「黄蜂吐刺」单掌如剑，\n直刺$n的心窝",
	"dodge": 80,
	"lvl" : 150,
	"force": 450,
	"damage_type": "内伤"
]),
([	"action": "$N一个急旋，飞身纵起，半空中一式「毒龙摆尾」，反手击向$n的$l",
	"dodge": 40,
	"lvl" : 200,
	"force": 500,
	"damage_type": "瘀伤"
]),
([	"action": "$N大喝一声，运起五毒神功，一招「毒火焚身」，刹那间全身毛发尽绿，一\n对碧绿的双爪闪电般的朝$n的$l抓去",
	"dodge": 20,
	"lvl" : 250,
	"force": 600,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }


mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("qianzhu-wandushou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 5, level/5)];
                        break;
                }
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level/2;
    return a_action;

}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练千蛛万毒手必须空手。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练千蛛万毒手");
	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("qi") < 80)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("jing") < 80)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练千蛛万毒手。\n");
	me->receive_damage("qi", 60);
	me->add("jing", -60);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
      if( random(me->query_skill("qianzhu-wandushou",1)) > 50 ) 
	  victim->receive_wound("qi", damage_bonus/3, me);
      if (random(me->query_skill("qianzhu-wandushou",1)) > 150 ) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$n只觉得伤处一阵发麻，似乎中毒了。\n" NOR;
   }
}
void skill_improved(object me)
{
  if(random(15) < 1 && me->query("per") > 5){
       tell_object(me, HIR "你忽然觉得体内毒气狂窜，面上顿时罩着一层黑气！\n" NOR );
       me->add("per", -1);
  }
}

string perform_action_file(string action)
{
	return __DIR__"qianzhu-wandushou/" + action;
}
