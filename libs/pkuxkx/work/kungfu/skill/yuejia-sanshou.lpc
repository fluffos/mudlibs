//Zine 岳家散手

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :
"$N大喝一声『仁贵担山』，一招，双掌上下翻飞、大开大阖，连续击向$n",
        "force" : 120,
        "dodge" : 30,
  	"damage" : 25,
  	"lvl"   : 0,
        "damage_type" : "内伤"
]),
([      "action" :
"$N忽然变为一路沉稳掌法，双足踏实，右掌力刚阳，左掌力阴柔，刚柔并济，催动强大内力猛击$n的$l，好一路『佛手阴阳』",
        "force" : 130,
        "dodge" : 5,
       	"damage" : 45,
       	"lvl"   : 20,
        "damage_type" : "内伤"
]),
([      "action" :
"$N默念心法，『生铁铸身』，速度虽慢，但力蕴千钧地$n的$l压去",
        "force" : 150,
        "dodge" : 25,
    	"damage" : 75,
    	"lvl"   : 30,
        "damage_type" : "淤伤"
]),
([      "action" :
"$N使出一招『童子拜佛』，双手合十$n的$l劈去",
        "force" : 180,
        "dodge" : 5,
	"damage" : 65,
	"lvl"   : 35,
        "damage_type" : "劈伤"
]),
([      "action" :
"$N双手使鹰爪手，高扑低纵，一招『铁禀锁喉』，向$n的脖子抓去",
        "force" : 200,
        "dodge" : 30,
        "damage" : 75,
        "lvl"   : 40,
 	"damage_type" : "刺伤"
]),
([      "action" :
"$N拳风一变，双臂竟似没了骨头一般柔软曲折，使出一路『天门封顶』向$n顶心抽击",
        "force" : 250,
   	"damage" : 85,
   	"dodge" : 30,
        "lvl"   : 50,
   	"damage_type" : "割伤"
]),
([      "action" :
"$N五指并拢，化掌为刀，强劲内力运至掌缘，一招『浪子划船』直劈$n的$l，深得刀法精要",
        "force" : 300,
        "dodge" : 30,
        "damage" : 95,
        "lvl"   : 72,
     	"damage_type" : "割伤"
]),
([      "action" :
"$N轻舒猿臂，双指并拢，相隔数尺之遥，纵身向$n当胸直捣，好一招『张飞擂鼓』",
        "force" : 320,
        "dodge" : 40,
        "lvl"   : 90,
    	"damage" : 105,
    	"damage_type" : "刺伤"
]),
([      "action" :
"$N吐气开声，气灌丹田，右掌高举，一式『玉骨顶心』，向$n当头爆劈",
        "force" : 340,
        "dodge" : 0,
        "damage" : 115,
        "lvl"   : 90,
        "damage_type" : "割伤"
]),
([      "action" :
"$N使出『元霸举鼎』，双拳并举，向$n轰去",
        "force" : 360,
        "dodge" : 30,
     	"damage" : 125,
     	"lvl"   : 100,
        "damage_type" : "淤伤"
]),
([      "action" :
"$N一声长啸，一招『天王托塔』，自下而上仰攻向$n周身要穴",
        "force" : 380,
        "dodge" : 30,
   	"damage" : 145,
   	"lvl"   : 140,
  	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="taizu-changquan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练岳家散手必须空手。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法学习岳家散手。\n");
	if ((int)me->query_skill("hand", 1) < 40)
		return notify_fail("你的基本手法火候不够，无法学习岳家散手。\n");
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
        level   = (int) me->query_skill("yuejia-sanshou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练岳家散手必须空手。\n");
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
       return __DIR__"yuejia-sanshou/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
       j = me->query_skill("yuejia-sanshou", 1);
       k = me->query_skill("bixue-xinfa",1);
       if( random(10) >= 5
        && !victim->is_busy()
        && j > 120
        && k > 120
        && me->query_skill_mapped("parry") == "yuejia-sanshou"
        && F_KUNGFU->hit_rate( j, victim->query_skill("dodge",1), 9, me, victim) )
        {
          switch(random(3))
          {
            case 0 :
               msg = HIB"$N目露精光，使出「飞挎篮」，招招抓向$n胸口！\n"NOR;
               msg+= HIB"$n被$N逼的连连後退，无力还招！\n"NOR;
               F_KUNGFU->hit_busy( "fenjin", 3, victim );
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
               break;
            case 1 :
               msg = MAG"$N施出「天罗地网」，双手纷飞，幻出无数手影！\n"NOR;
               msg+= MAG"$n只觉眼花缭乱，不知所措。\n"NOR;
               F_KUNGFU->hit_busy( "fenjin", 1+random(2), victim );
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
               break;
            case 2 :
               msg = BLU"$N一招「周仓扛粮」，拿向$n，似乎$n的全身都被手影笼罩！\n"NOR;
               msg+= BLU"$n只觉得周围全被手影笼罩，毫无躲闪的余地。\n"NOR;
               F_KUNGFU->hit_busy( "fenjin", random(3), victim );
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
               break;
          }
       }
}
