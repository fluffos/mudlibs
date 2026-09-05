//Cracked by Kafei
//zhemei-shou.c 天山折梅手
//Acep

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :
"$N大喝一声，使出一路迅猛的掌法，双掌上下翻飞、大开大阖，连续击向$n",
        "force" : 120,
        "dodge" : 30,
  	"damage" : 25,
  	"lvl"   : 0,
        "damage_type" : "内伤"
]),
([      "action" :
"$N足尖点地，御风而走，身形飘忽，掌力吞吐不定，突然间击向$n的$l，好一路潇洒自如的掌法",
        "force" : 160,
	"dodge" : 50,
  	"damage" : 35,
  	"lvl"   : 10,
        "damage_type" : "瘀伤"
]),
([      "action" :
"$N忽然变为一路沉稳掌法，双足踏实，右掌力刚阳，左掌力阴柔，刚柔并济，催动强大内力猛击$n的$l",
        "force" : 130,
        "dodge" : 5,
       	"damage" : 45,
       	"lvl"   : 20,
        "damage_type" : "内伤"
]),
([      "action" :
"$N双手忽而抓，忽而戳，忽而拳，忽而掌，连续变换数种小擒拿手法，向$n的$l抓去",
        "force" : 150,
        "dodge" : 45,
    	"damage" : 55,
    	"lvl"   : 30,
        "damage_type" : "抓伤"
]),
([      "action" :
"$N使出一路大力擒拿手法，双手时而龙爪，时而虎爪，虎虎生风向$n的$l擒去",
        "force" : 180,
        "dodge" : 5,
	"damage" : 65,
	"lvl"   : 35,
        "damage_type" : "抓伤"
]),
([      "action" :
"$N双手使鹰爪手，高扑低纵，上蹿下跳，向$n的手腕、脚腕、脖子，连出数爪擒拿",
        "force" : 200,
        "dodge" : 30,
        "damage" : 75,
        "lvl"   : 40,
 	"damage_type" : "刺伤"
]),
([      "action" :
"$N拳风一变，双臂竟似没了骨头一般柔软曲折，使出一路鞭法向$n左右猛烈抽击",
        "force" : 250,
   	"damage" : 85,
   	"dodge" : 30,
        "lvl"   : 50,
   	"damage_type" : "割伤"
]),
([      "action" :
"$N五指并拢，化掌为刀，强劲内力运至掌缘，一招直劈$n的$l，深得刀法精要",
        "force" : 300,
        "dodge" : 30,
        "damage" : 95,
        "lvl"   : 72,
     	"damage_type" : "割伤"
]),
([      "action" :
"$N轻舒猿臂，双指并拢，相隔数尺之遥，纵身向$n当胸直刺，使的竟然是长枪枪法",
        "force" : 320,
        "dodge" : 40,
        "lvl"   : 90,
    	"damage" : 105,
    	"damage_type" : "刺伤"
]),
([      "action" :
"$N吐气开声，气灌丹田，右掌高举，五指回扣，化作一柄大斧，向$n当头爆劈",
        "force" : 340,
        "dodge" : 0,
        "damage" : 115,
        "lvl"   : 90,
        "damage_type" : "割伤"
]),
([      "action" :
"$N发出一阵阴笑，双臂暴长，气运五指，使出一路兵器中的抓法，向$n连出数抓阴损招数",
        "force" : 360,
        "dodge" : 30,
     	"damage" : 125,
     	"lvl"   : 100,
        "damage_type" : "抓伤"
]),
([      "action" :
"$N一声长啸，化指为剑，使出一轮精妙的剑法绝招，向$n上下左右连刺带劈",
        "force" : 380,
        "dodge" : 30,
   	"damage" : 145,
   	"lvl"   : 140,
  	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="juehu-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练虎爪手必须空手。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法学习虎爪擒拿手。\n");
	if ((int)me->query_skill("hand", 1) < 40)
		return notify_fail("你的基本手法火候不够，无法学习虎爪擒拿手。\n");
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
        level   = (int) me->query_skill("huzhua-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练虎爪手必须空手。\n");
   if( (int)me->query("jing") < 30)
     return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
   if( (int)me->query("qi") < 30 )
     return notify_fail("你现在手足酸软，休息一下再练吧。\n");
   if( (int)me->query("neili") < 10 )
     return notify_fail("你的内力不够了。\n");

   me->receive_damage("qi", 30);
   me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
       return __DIR__"huzhua-shou/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
       j = me->query_skill("huzhua-shou", 1);
       k = me->query_skill("bixue-xinfa",1);
       if( random(10) >= 5
        && !victim->is_busy()
        && j > 120
        && k > 120
        && me->query_skill_mapped("parry") == "huzhua-shou"
        && random(j) > victim->query_skill("dodge",1)/2 )
        {
          switch(random(3))
          {
            case 0 :
               msg = HIB"$N目露凶光，使出「黑虎掏心」，招招抓向$n胸口！\n"NOR;
               msg+= HIB"$n被$N逼的连连後退，无力还招！\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
               break;
            case 1 :
               msg = MAG"$N施出「虎踞龙盘」，双手纷飞，幻出无数手影！\n"NOR;
               msg+= MAG"$n只觉眼花缭乱，不知所措。\n"NOR;
               victim->start_busy(1+random(2));
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
               break;
            case 2 :
               msg = BLU"$N一招「虎虎生威」，拿向$n，似乎$n的全身都被手影笼罩！\n"NOR;
               msg+= BLU"$n只觉得周围全被手影笼罩，毫无躲闪的余地。\n"NOR;
               victim->start_busy(random(3));
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
               break;
          }
       }
}
